object SourceForm: TSourceForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Source'
  ClientHeight = 179
  ClientWidth = 260
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 62
    Height = 13
    Caption = 'Input Source'
  end
  object Label2: TLabel
    Left = 10
    Top = 62
    Width = 70
    Height = 13
    Caption = 'Volume Source'
  end
  object InputSourceCb: TComboBox
    Left = 7
    Top = 31
    Width = 242
    Height = 21
    Style = csDropDownList
    TabOrder = 0
  end
  object VolumeSourceCb: TComboBox
    Left = 8
    Top = 79
    Width = 241
    Height = 21
    Style = csDropDownList
    TabOrder = 1
  end
  object VolumeTrackBar: TTrackBar
    Left = 2
    Top = 110
    Width = 251
    Height = 45
    Max = 100
    TabOrder = 2
    TickMarks = tmBoth
  end
end
