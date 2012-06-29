object MediaLibraryForm: TMediaLibraryForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Media Library'
  ClientHeight = 557
  ClientWidth = 1014
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
  object Splitter1: TSplitter
    Left = 385
    Top = 0
    Height = 538
    ExplicitLeft = 676
    ExplicitTop = 368
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 385
    Height = 538
    Align = alLeft
    TabOrder = 0
    object DrivesCb: TDriveComboBox
      Left = 1
      Top = 1
      Width = 383
      Height = 19
      Align = alTop
      DirList = DirectoriesLb
      TabOrder = 0
    end
    object DirectoriesLb: TDirectoryListBox
      Left = 1
      Top = 20
      Width = 383
      Height = 517
      Align = alClient
      FileList = FilesLb
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 388
    Top = 0
    Width = 626
    Height = 538
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Splitter2: TSplitter
      Left = 293
      Top = 1
      Height = 536
      ExplicitLeft = 464
      ExplicitTop = 356
      ExplicitHeight = 100
    end
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 292
      Height = 536
      Align = alLeft
      Caption = 'Panel3'
      TabOrder = 0
      object FilterCb: TFilterComboBox
        Left = 1
        Top = 1
        Width = 290
        Height = 21
        Align = alTop
        FileList = FilesLb
        Filter = 
          'MP3 (*.mp3)|*.mp3|WMA (*.wma)|*.wma|WAV (*.wav) |*.wav|All files' +
          ' (*.*)|*.*'
        TabOrder = 0
      end
      object FilesLb: TFileListBox
        Left = 1
        Top = 22
        Width = 290
        Height = 474
        Align = alClient
        ItemHeight = 13
        Mask = '*.mp3'
        TabOrder = 1
      end
      object Panel6: TPanel
        Left = 1
        Top = 496
        Width = 290
        Height = 39
        Align = alBottom
        TabOrder = 2
        object PreviewAudioBtn: TBitBtn
          Left = 4
          Top = 8
          Width = 75
          Height = 25
          Caption = '&Preview'
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnClick = PreviewAudioBtnClick
        end
        object EnqueueBtn: TBitBtn
          Left = 83
          Top = 8
          Width = 75
          Height = 25
          Caption = '&Enqueue'
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 1
          OnClick = EnqueueBtnClick
        end
      end
    end
    object Panel4: TPanel
      Left = 296
      Top = 1
      Width = 329
      Height = 536
      Align = alClient
      Caption = 'Panel4'
      TabOrder = 1
      object Panel5: TPanel
        Left = 1
        Top = 494
        Width = 327
        Height = 41
        Align = alBottom
        TabOrder = 0
        object PlayBtn: TBitBtn
          Left = 5
          Top = 8
          Width = 75
          Height = 25
          Caption = '&Play'
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
        end
        object PauseBtn: TBitBtn
          Left = 85
          Top = 8
          Width = 75
          Height = 25
          Caption = '&Pause'
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 1
        end
        object StopBtn: TBitBtn
          Left = 165
          Top = 8
          Width = 75
          Height = 25
          Caption = '&Stop'
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 2
        end
      end
      object LibraryGrid: TStringGrid
        Left = 1
        Top = 1
        Width = 327
        Height = 493
        Align = alClient
        ColCount = 4
        FixedCols = 0
        TabOrder = 1
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 538
    Width = 1014
    Height = 19
    Panels = <>
  end
end