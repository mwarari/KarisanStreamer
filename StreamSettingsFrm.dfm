object StreamSettingsForm: TStreamSettingsForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Stream Settings'
  ClientHeight = 469
  ClientWidth = 403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object TabbedNotebook1: TTabbedNotebook
    Left = 8
    Top = 8
    Width = 385
    Height = 409
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'Tahoma'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Basic Settings'
      object Label1: TLabel
        Left = 13
        Top = 59
        Width = 38
        Height = 13
        Caption = 'Bit Rate'
      end
      object Label2: TLabel
        Left = 12
        Top = 86
        Width = 34
        Height = 13
        Caption = 'Quality'
      end
      object Label3: TLabel
        Left = 13
        Top = 113
        Width = 60
        Height = 13
        Caption = 'Sample Rate'
      end
      object Label4: TLabel
        Left = 12
        Top = 140
        Width = 44
        Height = 13
        Caption = 'Channels'
      end
      object Label5: TLabel
        Left = 12
        Top = 167
        Width = 66
        Height = 13
        Caption = 'Encoder Type'
      end
      object Label6: TLabel
        Left = 12
        Top = 194
        Width = 59
        Height = 13
        Caption = 'Server Type'
      end
      object Label7: TLabel
        Left = 13
        Top = 221
        Width = 45
        Height = 13
        Caption = 'Server IP'
      end
      object Label8: TLabel
        Left = 10
        Top = 248
        Width = 55
        Height = 13
        Caption = 'Server Port'
      end
      object Label9: TLabel
        Left = 10
        Top = 275
        Width = 88
        Height = 13
        Caption = 'Encoder Password'
      end
      object Label10: TLabel
        Left = 12
        Top = 302
        Width = 53
        Height = 13
        Caption = 'Moint Point'
      end
      object Label11: TLabel
        Left = 12
        Top = 331
        Width = 94
        Height = 13
        Caption = 'Reconnect Seconds'
      end
      object Label12: TLabel
        Left = 12
        Top = 358
        Width = 57
        Height = 13
        Caption = 'Attenuation'
      end
      object Label20: TLabel
        Left = 16
        Top = 32
        Width = 64
        Height = 13
        Caption = 'Stream Name'
      end
      object BitrateEb: TEdit
        Left = 112
        Top = 56
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object QualityEb: TEdit
        Left = 112
        Top = 83
        Width = 121
        Height = 21
        TabOrder = 2
      end
      object SampleRateEb: TEdit
        Left = 112
        Top = 110
        Width = 121
        Height = 21
        TabOrder = 3
      end
      object ChannelsCb: TComboBox
        Left = 112
        Top = 137
        Width = 121
        Height = 21
        Style = csDropDownList
        TabOrder = 4
        Items.Strings = (
          'Mono'
          'Stereo')
      end
      object EncoderTypeCb: TComboBox
        Left = 112
        Top = 164
        Width = 121
        Height = 21
        Style = csDropDownList
        TabOrder = 5
        Items.Strings = (
          'AAC'
          'MP3')
      end
      object ServerTypeCb: TComboBox
        Left = 112
        Top = 191
        Width = 121
        Height = 21
        Style = csDropDownList
        TabOrder = 6
        Items.Strings = (
          'Ice Cast 2')
      end
      object ServerIPEb: TEdit
        Left = 112
        Top = 218
        Width = 121
        Height = 21
        TabOrder = 7
      end
      object ServerPortEb: TEdit
        Left = 112
        Top = 245
        Width = 121
        Height = 21
        TabOrder = 8
      end
      object EncoderPasswordEb: TEdit
        Left = 112
        Top = 272
        Width = 121
        Height = 21
        TabOrder = 9
      end
      object MountPointEb: TEdit
        Left = 112
        Top = 299
        Width = 121
        Height = 21
        TabOrder = 10
      end
      object ReconnectSecondsCb: TSpinEdit
        Left = 112
        Top = 326
        Width = 121
        Height = 22
        MaxValue = 0
        MinValue = 0
        TabOrder = 11
        Value = 0
      end
      object AttenuationEb: TEdit
        Left = 112
        Top = 354
        Width = 121
        Height = 21
        TabOrder = 12
      end
      object StreamNameEb: TEdit
        Left = 112
        Top = 28
        Width = 121
        Height = 21
        TabOrder = 0
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'YP Settings'
      object Label13: TLabel
        Left = 8
        Top = 40
        Width = 64
        Height = 13
        Caption = 'Stream Name'
      end
      object Label14: TLabel
        Left = 8
        Top = 64
        Width = 90
        Height = 13
        Caption = 'Stream Description'
      end
      object Label15: TLabel
        Left = 0
        Top = 88
        Width = 56
        Height = 13
        Caption = 'Stream URL'
      end
      object Label16: TLabel
        Left = 8
        Top = 112
        Width = 66
        Height = 13
        Caption = 'Stream Genre'
      end
      object AdvertiseSiteCb: TCheckBox
        Left = 104
        Top = 12
        Width = 97
        Height = 17
        Caption = 'Advertise Site'
        TabOrder = 0
      end
      object YPStreamNameEb: TEdit
        Left = 104
        Top = 35
        Width = 220
        Height = 21
        TabOrder = 1
      end
      object StreamDescriptionEb: TEdit
        Left = 104
        Top = 62
        Width = 219
        Height = 21
        TabOrder = 2
      end
      object StreamURLEb: TEdit
        Left = 104
        Top = 89
        Width = 218
        Height = 21
        TabOrder = 3
      end
      object StreamGenreEb: TEdit
        Left = 104
        Top = 116
        Width = 217
        Height = 21
        TabOrder = 4
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Advanced Settings'
      object Label17: TLabel
        Left = 10
        Top = 47
        Width = 83
        Height = 13
        Caption = 'Archive Directory'
      end
      object Label18: TLabel
        Left = 11
        Top = 70
        Width = 45
        Height = 13
        Caption = 'Log Level'
      end
      object Label19: TLabel
        Left = 12
        Top = 101
        Width = 36
        Height = 13
        Caption = 'Log File'
      end
      object SpeedButton1: TSpeedButton
        Left = 340
        Top = 92
        Width = 23
        Height = 22
        Caption = '...'
      end
      object SpeedButton2: TSpeedButton
        Left = 339
        Top = 38
        Width = 23
        Height = 22
        Caption = '...'
        OnClick = SpeedButton2Click
      end
      object SaveStreamCb: TCheckBox
        Left = 112
        Top = 16
        Width = 97
        Height = 17
        Caption = 'Save Stream'
        TabOrder = 0
      end
      object ArchiveDirectoryEb: TEdit
        Left = 112
        Top = 39
        Width = 225
        Height = 21
        TabOrder = 1
      end
      object LogLevelEb: TEdit
        Left = 112
        Top = 66
        Width = 225
        Height = 21
        TabOrder = 2
      end
      object LogFileEb: TEdit
        Left = 112
        Top = 93
        Width = 225
        Height = 21
        TabOrder = 3
      end
    end
  end
  object BitBtn1: TBitBtn
    Left = 224
    Top = 432
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkOK
    ParentDoubleBuffered = False
    TabOrder = 1
  end
  object BitBtn2: TBitBtn
    Left = 318
    Top = 432
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkCancel
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object OpenDialog: TOpenDialog
    Options = [ofHideReadOnly, ofCreatePrompt, ofEnableSizing]
    Left = 264
    Top = 323
  end
end
