//---------------------------------------------------------------------------

#include <map>
#include <string>
#include <memory>
#include <vcl.h>
#pragma hdrstop

#include "SourceFrm.h"
#include "bass.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std ;
TSourceForm *SourceForm;
//---------------------------------------------------------------------------
__fastcall TSourceForm::TSourceForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSourceForm::FormShow(TObject *Sender)
{
	BassAudio bass_audio ;

	bass_audio.recordInit() ;

	map<const int, string> devices = bass_audio.getRecordingDevices() ;
	for (int idx=0; idx < devices.size(); idx++) {
			InputSourceCb->Items->Add(devices[idx].c_str()) ;
	}

	map<const int, string> inputs = bass_audio.getRecordingInputs() ;
	for(int idx = 0; idx < inputs.size();idx++) {
		VolumeSourceCb->Items->Add(inputs[idx].c_str()) ;
	}
}
//---------------------------------------------------------------------------

