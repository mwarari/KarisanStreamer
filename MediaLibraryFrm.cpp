//---------------------------------------------------------------------------

#include <vcl.h>
#include <sstream>
#include <string>
#pragma hdrstop

#include "MediaLibraryFrm.h"
#include "fileref.h"
#include "tag.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMediaLibraryForm *MediaLibraryForm;
//---------------------------------------------------------------------------
__fastcall TMediaLibraryForm::TMediaLibraryForm(TComponent* Owner)
	: TForm(Owner)
{
	_bass_audio = new BassAudio(this->ClientHandle) ;
	_playing = false ;

}
//---------------------------------------------------------------------------

__fastcall TMediaLibraryForm::~TMediaLibraryForm()
{
	delete _bass_audio ;
}
//---------------------------------------------------------------------------
void __fastcall TMediaLibraryForm::PreviewAudioBtnClick(TObject *Sender)
{
	if(_playing == false) {
	_bass_audio->playFile(FilesLb->FileName.t_str()) ;
	PreviewAudioBtn->Caption = "&Stop" ;
	_playing = TRUE ;
	} else {
		_bass_audio->stopStream() ;
		_playing = FALSE ;
		PreviewAudioBtn->Caption = "Preview" ;
	}
}
//---------------------------------------------------------------------------

void TMediaLibraryForm::showHeadings()
{
	LibraryGrid->Cells[0][0] = "Song" ;
	LibraryGrid->Cells[1][0] = "Artist" ;
	LibraryGrid->Cells[2][0] = "Length" ;
}
//---------------------------------------------------------------------------

void __fastcall TMediaLibraryForm::FormShow(TObject *Sender)
{
	showHeadings() ;
}
//---------------------------------------------------------------------------

void __fastcall TMediaLibraryForm::EnqueueBtnClick(TObject *Sender)
{
	string music_file = FilesLb->FileName.t_str() ;
	TagLib::FileRef file_id3(music_file.c_str());

	if(!file_id3.isNull() && file_id3.tag()) {
	  TagLib::Tag *tag = file_id3.tag();

	  stringstream title ;
	  title << tag->title() ;
	  stringstream artist ;
	  artist << tag->artist() ;
	  int seconds = 0 ;
	  int minutes = 0 ;
	  stringstream length ;

	  if(!file_id3.isNull() && file_id3.audioProperties()) {
		TagLib::AudioProperties *properties = file_id3.audioProperties();

		seconds = properties->length() % 60 ;
		minutes = (properties->length() - seconds) / 60 ;

		length << minutes << ":" << seconds ;
	  }
	  addToQueue(title.str(), artist.str(), length.str()) ;
	}

}
//---------------------------------------------------------------------------

void TMediaLibraryForm::addToQueue(string title, string artist, string song_len)
{
	int row = 0 ;

	for(row = 1 ; row < LibraryGrid->RowCount ; row++) {
		if(queueRowIsEmpty(row) == TRUE) {
			LibraryGrid->Cells[0][row] = title.c_str() ;
			LibraryGrid->Cells[1][row] = artist.c_str() ;
			LibraryGrid->Cells[2][row] = song_len.c_str() ;
			break ;
		}
	}
	if(row >= LibraryGrid->RowCount) {
		LibraryGrid->RowCount += 15 ;
		LibraryGrid->Cells[0][row] = title.c_str() ;
		LibraryGrid->Cells[1][row] = artist.c_str() ;
		LibraryGrid->Cells[2][row] = song_len.c_str() ;
	}
}
//---------------------------------------------------------------------------

BOOL TMediaLibraryForm::queueRowIsEmpty(int row)
{
	if(LibraryGrid->Cells[0][row] ==  "" &&
		LibraryGrid->Cells[1][row] == "" &&
		LibraryGrid->Cells[2][row] == "") {
			return(TRUE) ;
	} else {
		return(FALSE) ;
	}
}
//---------------------------------------------------------------------------

