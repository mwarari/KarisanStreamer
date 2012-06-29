object OutputForm: TOutputForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Output'
  ClientHeight = 233
  ClientWidth = 364
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
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 18
    Width = 17
    Height = 13
    Caption = 'L'
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 15
    Height = 13
    Caption = 'R'
  end
  object Label3: TLabel
    Left = 32
    Top = 64
    Width = 21
    Height = 13
    Caption = 'Gain'
  end
  object Label4: TLabel
    Left = 200
    Top = 64
    Width = 21
    Height = 13
    Caption = 'Limit'
  end
  object Label5: TLabel
    Left = 24
    Top = 144
    Width = 64
    Height = 13
    Caption = 'Pre-emphasis'
  end
  object LProgressBar: TProgressBar
    Left = 30
    Top = 18
    Width = 306
    Height = 17
    Position = 50
    Smooth = True
    Style = pbstMarquee
    MarqueeInterval = 100
    BarColor = clLime
    BackgroundColor = clBlack
    Step = 2
    TabOrder = 0
  end
  object RProgressBar: TProgressBar
    Left = 30
    Top = 40
    Width = 306
    Height = 17
    Position = 33
    Smooth = True
    Style = pbstMarquee
    MarqueeInterval = 100
    BarColor = clLime
    BackgroundColor = clBlack
    Step = 2
    TabOrder = 1
  end
  object TrackBar1: TTrackBar
    Left = 24
    Top = 88
    Width = 150
    Height = 45
    Max = 50
    TabOrder = 2
    TickMarks = tmBoth
  end
  object TrackBar2: TTrackBar
    Left = 192
    Top = 88
    Width = 150
    Height = 45
    Max = 50
    TabOrder = 3
    TickMarks = tmBoth
  end
  object TrackBar3: TTrackBar
    Left = 24
    Top = 168
    Width = 329
    Height = 45
    Max = 100
    TabOrder = 4
    TickMarks = tmBoth
  end
end
