object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 80
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Cloche 1'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Cloche 2'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 272
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Cloche 3'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 368
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Cloche 4'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 544
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Fermeture'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 200
    Top = 136
    Width = 121
    Height = 21
    TabOrder = 6
    OnKeyDown = Edit1KeyDown
  end
  object Button7: TButton
    Left = 224
    Top = 105
    Width = 75
    Height = 25
    Caption = 'M'#233'lodie'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 224
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Fichier'
    TabOrder = 8
    OnClick = Button8Click
  end
end
