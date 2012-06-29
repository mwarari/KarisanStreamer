//---------------------------------------------------------------------------

#ifndef MediaLibraryFrmH
#define MediaLibraryFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <FileCtrl.hpp>
#include <Buttons.hpp>

#include "bass.hpp"
//---------------------------------------------------------------------------
class TMediaLibraryForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDriveComboBox *DrivesCb;
	TDirectoryListBox *DirectoriesLb;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TPanel *Panel3;
	TFilterComboBox *FilterCb;
	TFileListBox *FilesLb;
	TSplitter *Splitter2;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TBitBtn *PreviewAudioBtn;
	TBitBtn *EnqueueBtn;
	TBitBtn *PlayBtn;
	TBitBtn *PauseBtn;
	TBitBtn *StopBtn;
	TStringGrid *LibraryGrid;
	TStatusBar *StatusBar1;
	void __fastcall PreviewAudioBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EnqueueBtnClick(TObject *Sender);
private:	// User declarations
	BassAudio *_bass_audio ;
	bool _playing ;
	void showHeadings() ;
	BOOL queueRowIsEmpty(int row) ;
	void addToQueue(string title, string artist, string song_len) ;
public:		// User declarations
	__fastcall TMediaLibraryForm(TComponent* Owner);
	__fastcall ~TMediaLibraryForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TMediaLibraryForm *MediaLibraryForm;
//---------------------------------------------------------------------------
#endif
