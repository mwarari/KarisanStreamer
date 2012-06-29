//---------------------------------------------------------------------------

#ifndef StreamsFrmH
#define StreamsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>

#include "KarisanStreamerConfig.h"
//---------------------------------------------------------------------------

class TStreamsForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StreamsGrid;
	TCheckBox *AutoConnectCb;
	TBitBtn *ConnectBtn;
	TBitBtn *AddBtn;
	TBitBtn *configureBtn;
	TBitBtn *deleteBtn;
	void __fastcall StreamsGridDblClick(TObject *Sender);
	void __fastcall AddBtnClick(TObject *Sender);
	void __fastcall configureBtnClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall deleteBtnClick(TObject *Sender);
	void __fastcall ConnectBtnClick(TObject *Sender);
private:	// User declarations
	KarisanStreamerConfig *_config ;
	void __fastcall showStreams() ;
	void __fastcall showNewStream(StreamConfig *stream) ;
	void __fastcall showStream(int row, StreamConfig *stream) ;
	void __fastcall updateStream(int row, StreamConfig *stream) ;
	void __fastcall clearStreamsGrid() ;
public:		// User declarations
	__fastcall TStreamsForm(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TStreamsForm *StreamsForm;
//---------------------------------------------------------------------------
#endif
