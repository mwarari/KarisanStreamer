//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StreamSettingsFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Spin"
#pragma resource "*.dfm"
TStreamSettingsForm *StreamSettingsForm;
//---------------------------------------------------------------------------
__fastcall TStreamSettingsForm::TStreamSettingsForm(TComponent* Owner)
	: TForm(Owner)
{
	config = NULL ;
}
//---------------------------------------------------------------------------
void __fastcall TStreamSettingsForm::SpeedButton2Click(TObject *Sender)
{
	//OpenDialog.ShowModal() ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamSettingsForm::showConfig()
{
	// Basic Settings
    StreamNameEb->Text = config->getName().c_str() ;

	BitrateEb->Text = config->getBitRate() ;

	QualityEb->Text = config->getQuality() ;

	SampleRateEb->Text = config->getSampleRate() ;

	ChannelsCb->ItemIndex = ChannelsCb->Items->IndexOf(UnicodeString(config->getChannels().c_str())) ;

	EncoderTypeCb->ItemIndex = EncoderTypeCb->Items->IndexOf(UnicodeString(config->getEncoderType().c_str())) ;

	ServerTypeCb->ItemIndex = ServerTypeCb->Items->IndexOf(UnicodeString(config->getServerType().c_str())) ;

	ServerIPEb->Text = UnicodeString(config->getServerIP().c_str()) ;

	ServerPortEb->Text = config->getServerPort() ;

	EncoderPasswordEb->Text = UnicodeString(config->getPassword().c_str()) ;

	MountPointEb->Text = UnicodeString(config->getMountPoint().c_str()) ;

	ReconnectSecondsCb->Value = config->getReconnectInterval() ;

	AttenuationEb->Text = config->getAttenuation() ;

	// YP Settings
	AdvertiseSiteCb->Checked = config->getPublicServer() ;

	YPStreamNameEb->Text = UnicodeString(config->getYPStreamName().c_str()) ;

	StreamDescriptionEb->Text = UnicodeString(config->getStreamDescription().c_str()) ;

	StreamURLEb->Text = UnicodeString(config->getStreamURL().c_str()) ;

	StreamGenreEb->Text = UnicodeString(config->getStreamGenre().c_str()) ;

	// Advanced Settings
	SaveStreamCb->Checked = config->getSaveStream() ;

	ArchiveDirectoryEb->Text = UnicodeString(config->getArchiveDirectory().c_str()) ;

	LogLevelEb->Text = config->getLogLevel() ;

	LogFileEb->Text = UnicodeString(config->getLogFile().c_str()) ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamSettingsForm::getConfig()
{
	// Basic Settings
	config->setName(StreamNameEb->Text.t_str()) ;

	config->setBitRate(BitrateEb->Text.ToIntDef(0)) ;

	config->setQuality(QualityEb->Text.ToIntDef(0)) ;

	config->setSampleRate(SampleRateEb->Text.ToIntDef(0)) ;

	config->setChannels(ChannelsCb->Text.t_str()) ;

	config->setEncoderType(EncoderTypeCb->Text.t_str()) ;

	config->setServerType(ServerTypeCb->Text.t_str()) ;

	config->setServerIP(ServerIPEb->Text.t_str()) ;

	config->setServerPort(ServerPortEb->Text.ToIntDef(0)) ;

	config->setPassword(EncoderPasswordEb->Text.t_str()) ;

	config->setMountPoint(MountPointEb->Text.t_str()) ;

	config->setReconnectInterval(ReconnectSecondsCb->Value) ;

	if(!AttenuationEb->Text.IsEmpty()) {
		config->setAttenuation(AttenuationEb->Text.ToDouble()) ;
	} else {
		config->setAttenuation(0.0) ;
	}

	// YP Settings
	config->setPublicServer(AdvertiseSiteCb->Checked) ;

	config->setYPStreamName(YPStreamNameEb->Text.t_str()) ;

	config->setStreamDescription(StreamDescriptionEb->Text.t_str()) ;

	config->setStreamURL(StreamURLEb->Text.t_str()) ;

	config->setStreamGenre(StreamGenreEb->Text.t_str()) ;

	// Advanced Settings
	config->setSaveStream(SaveStreamCb->Checked) ;

	config->setArchiveDirectory(ArchiveDirectoryEb->Text.t_str()) ;

	config->setLogLevel(LogLevelEb->Text.ToIntDef(0)) ;

	config->setLogFile(LogFileEb->Text.t_str()) ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamSettingsForm::setConfig(StreamConfig *value)
{
	config = value ;
}
//---------------------------------------------------------------------------

