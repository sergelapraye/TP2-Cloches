//---------------------------------------------------------------------------
#if defined (WIN32)
	#include <winsock2.h>
	typedef int socklen_t;
#endif
#include <stdio.h>
#include <vector>
 #include "Windows.h"
#include "windows.h"
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#define BUFFERSIZE 25
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Button2->Visible=false;
	Button3->Visible=false;
	Button4->Visible=false;
	Button5->Visible=false;
	Button6->Visible=false;
	Button7->Visible=false;
	Edit1->Visible=false;
	Button8->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{
		/* Création de la socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr("192.168.64.124");
		sin.sin_family = AF_INET;
			sin.sin_port = htons(502);

		/* Si le client arrive à se connecter */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
            // affichage des boutons d'envoi de trame
			Button1->Visible=false;
			Button2->Visible=true;
			Button3->Visible=true;
			Button4->Visible=true;
			Button5->Visible=true;
			Button6->Visible=true;
			Button7->Visible=true;
            Button8->Visible=true;
			Edit1->Visible=true;
            test = new cloche(sock);
		}
		else
		{
		 // connexion non valide
		}

	}
}
//---------------------------------------------------------------------------
// activation cloche 1
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	test->cloche1();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  /* On ferme la socket précédemment ouverte */
	closesocket(sock);
	delete test;
	#if defined (WIN32)
		WSACleanup();
	#endif
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	test->cloche2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	test->cloche3();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	test->cloche4();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if (Key==VK_F1) {
		test->cloche1();
  }
  if (Key==VK_F2) {
	   test->cloche2();
  }
  if (Key==VK_F3) {
	   test->cloche3();
  }
  if (Key==VK_F4) {
		test->cloche4();
  }
  if (Key==VK_F5) {
		test->toutCloche();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{

	test->cloche3();
	test->cloche1();
	test->cloche4();
	test->cloche2();
	test->cloche1();
	test->cloche4();
	test->cloche2();
	test->cloche3();
	test->toutCloche();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	/*
	HANDLE hFile;
	char buf[24];
	const wchar_t * File= L"C:/Users/BTSSN2/Documents/Embarcadero/Studio/Projets/ProjetCloche/Trame.txt";
	unsigned long nbBytes;
	hFile =CreateFile	(	File,
							GENERIC_READ ,
							FILE_SHARE_READ,
							NULL,
							OPEN_EXISTING,
							FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
							NULL
						);
	if  (hFile == INVALID_HANDLE_VALUE)
	{
		Memo1->Lines->Add("non");
	}
	else
	{
	ReadFile(hFile,buf,24,&nbBytes,0);
	Memo1->Lines->Add(buf);
	send(sock, buf, 24, 0);

	}
	*/
	std::ifstream ifs ("C:/Users/BTSSN2/Documents/Embarcadero/Studio/Projets/ProjetCloche/Trame.txt", std::ifstream::in);

	char c = ifs.get();
	UnicodeString str ="";
	char buf[5] ;

	while (ifs.good()) {

		str += c;
		c = ifs.get();
	}
	wcstombs(buf,str.c_str(),5);
	for (int i = 0; i < 5; i++) {
		if (buf[i]==1) {
			test->cloche1();
		}
		if (buf[i]==2) {
			test->cloche2();
		}
		if (buf[i]==3) {
			test->cloche3();
		}
		if (buf[i]==4) {
			test->cloche4();
		}
		if (buf[i]==5) {
			test->toutCloche();
		}
	}
	ifs.close();


}
//---------------------------------------------------------------------------



