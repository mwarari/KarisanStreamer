//---------------------------------------------------------------------------

#ifndef StreamSettingsFrmH
#define StreamSettingsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Spin.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <TabNotBk.hpp>
#include <Dialogs.hpp>

#include "StreamConfig.h"
//---------------------------------------------------------------------------
class TStreamSettingsForm : public TForm
{
__published:	// IDE-managed Components
	TTabbedNotebook *TabbedNotebook1;
	TLabel *Label1;
	TEdit *BitrateEb;
	TEdit *QualityEb;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *SampleRateEb;
	TComboBox *ChannelsCb;
	TLabel *Label4;
	TLabel *Label5;
	TComboBox *EncoderTypeCb;
	TComboBox *ServerTypeCb;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *ServerIPEb;
	TEdit *ServerPortEb;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *EncoderPasswordEb;
	TEdit *MountPointEb;
	TLabel *Label10;
	TLabel *Label11;
	TSpinEdit *ReconnectSecondsCb;
	TEdit *AttenuationEb;
	TLabel *Label12;
	TCheckBox *AdvertiseSiteCb;
	TEdit *YPStreamNameEb;
	TEdit *StreamDescriptionEb;
	TEdit *StreamURLEb;
	TEdit *StreamGenreEb;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TCheckBox *SaveStreamCb;
	TEdit *ArchiveDirectoryEb;
	TLabel *Label17;
	TEdit *LogLevelEb;
	TEdit *LogFileEb;
	TLabel *Label18;
	TLabel *Label19;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TOpenDialog *OpenDialog;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TEdit *StreamNameEb;
	TLabel *Label20;
	void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
	StreamConfig *config ;
public:		// User declarations
	__fastcall TStreamSettingsForm(TComponent* Owner);

	void __fastcall showConfig() ;
	void __fastcall getConfig() ;
	void __fastcall setConfig(StreamConfig *value) ;
};
//---------------------------------------------------------------------------
extern PACKAGE TStreamSettingsForm *StreamSettingsForm;
//---------------------------------------------------------------------------
#endif
