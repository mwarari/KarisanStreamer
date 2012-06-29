//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StreamsFrm.h"
#include "StreamSettingsFrm.h"
#include "StreamConfig.h"
#include "IceCastStreamer.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStreamsForm *StreamsForm;
//---------------------------------------------------------------------------
__fastcall TStreamsForm::TStreamsForm(TComponent* Owner)
	: TForm(Owner)
{
	_config = new KarisanStreamerConfig() ;
	_config->loadStreams() ;
}
//---------------------------------------------------------------------------
void __fastcall TStreamsForm::StreamsGridDblClick(TObject *Sender)
{
	configureBtnClick(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::AddBtnClick(TObject *Sender)
{
	TStreamSettingsForm *streamSettingsForm ;
	StreamConfig *stream_config = new StreamConfig() ;

	streamSettingsForm = new TStreamSettingsForm(Application) ;

	streamSettingsForm->setConfig(stream_config) ;
	if(streamSettingsForm->ShowModal() == mrOk) {
    	streamSettingsForm->getConfig() ;
		_config->addStream(stream_config) ;
		_config->update() ;
		showNewStream(stream_config) ;
	}

	delete streamSettingsForm ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::configureBtnClick(TObject *Sender)
{
	if(StreamsGrid->Row > 0) {
		TStreamSettingsForm *streamSettingsForm ;

		int idx = StreamsGrid->Row - 1 ;
		StreamConfig *stream_config = _config->getStream(idx) ;
		string old_stream_name = stream_config->getName() ;

		streamSettingsForm = new TStreamSettingsForm(Application) ;
		streamSettingsForm->setConfig(stream_config) ;
		streamSettingsForm->showConfig() ;

		streamSettingsForm->ShowModal() ;
		streamSettingsForm->getConfig() ;

		_config->updateStream(idx, old_stream_name) ;
		_config->update() ;
		showStream(idx + 1, stream_config) ;

		delete streamSettingsForm ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::FormDestroy(TObject *Sender)
{
	delete _config ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::showNewStream(StreamConfig *stream)
{
	for(int row = 1 ; row < StreamsGrid->RowCount ; row++) {
		if(StreamsGrid->Cells[0][row] == "") {
			StreamsGrid->Cells[0][row] = UnicodeString(stream->getName().c_str()) ;
			StreamsGrid->Cells[1][row] = UnicodeString(stream->getEncoderType().c_str()) ;
			StreamsGrid->Cells[2][row] = UnicodeString(stream->getBitRate()) + " Kbps" ;
			StreamsGrid->Cells[3][row] = UnicodeString(stream->getSampleRate()) + " Hz";
			StreamsGrid->Cells[4][row] = UnicodeString(stream->getChannels().c_str()) ;
			StreamsGrid->Cells[5][row] = "Discon." ;
			StreamsGrid->Cells[6][row] = UnicodeString(stream->getMountPoint().c_str()) ;
			break ;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::showStream(int row, StreamConfig *stream)
{
	StreamsGrid->Cells[0][row] = UnicodeString(stream->getName().c_str()) ;
	StreamsGrid->Cells[1][row] = UnicodeString(stream->getEncoderType().c_str()) ;
	StreamsGrid->Cells[2][row] = UnicodeString(stream->getBitRate()) + " Kbps" ;
	StreamsGrid->Cells[3][row] = UnicodeString(stream->getSampleRate()) + " Hz";
	StreamsGrid->Cells[4][row] = UnicodeString(stream->getChannels().c_str()) ;
	StreamsGrid->Cells[5][row] = "Discon." ;
	StreamsGrid->Cells[6][row] = UnicodeString(stream->getMountPoint().c_str()) ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::updateStream(int row, StreamConfig *stream)
{

}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::FormShow(TObject *Sender)
{
	StreamsGrid->Cells[0][0] = "Name" ;
	StreamsGrid->Cells[1][0] = "Enc." ;
	StreamsGrid->Cells[2][0] = "Bitrate" ;
	StreamsGrid->Cells[3][0] = "Sample rate" ;
	StreamsGrid->Cells[4][0] = "Channels" ;
	StreamsGrid->Cells[5][0] = "Trans. rate" ;
	StreamsGrid->Cells[6][0] = "Mount" ;

	showStreams() ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::showStreams()
{
	clearStreamsGrid() ;
	int row = 1 ;
	map<int, StreamConfig *> *streams = _config->getStreams() ;
	if(streams != NULL) {
		for(map<int, StreamConfig*>::iterator it = streams->begin() ; it != streams->end() ; ++it) {
			StreamConfig *stream  = it->second ;
			if(stream != NULL) {
				showStream(row++, stream) ;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::deleteBtnClick(TObject *Sender)
{
	int row = StreamsGrid->Row ;
	int idx = -1 ;

	map<int, StreamConfig *> *streams = _config->getStreams() ;

	StreamConfig *stream = _config->getStream((StreamsGrid->Cells[0][row]).t_str(), &idx) ;

	streams->erase(idx) ;

	delete stream ;

	_config->update() ;

	showStreams() ;
}
//---------------------------------------------------------------------------

void __fastcall TStreamsForm::clearStreamsGrid()
{
	for(int row = 1 ; row < StreamsGrid->RowCount ; row++) {
		StreamsGrid->Cells[0][row] = "" ;
		StreamsGrid->Cells[1][row] = "" ;
		StreamsGrid->Cells[2][row] = "" ;
		StreamsGrid->Cells[3][row] = "" ;
		StreamsGrid->Cells[4][row] = "" ;
		StreamsGrid->Cells[5][row] = "" ;
		StreamsGrid->Cells[6][row] = "" ;
    }
}
//---------------------------------------------------------------------------



void __fastcall TStreamsForm::ConnectBtnClick(TObject *Sender)
{
	StreamConfig *stream = _config->getStream((StreamsGrid->Cells[0][StreamsGrid->Row]).t_str()) ;
	IceCastStreamer streamer(stream) ;

	
	streamer.setChannels(2) ;
	streamer.setAudioFormat(MPEG) ;

	streamer.connect() ;
	// streamer.disconnect() ;


}
//---------------------------------------------------------------------------

