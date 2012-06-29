//---------------------------------------------------------------------------

#ifndef SourceFrmH
#define SourceFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSourceForm : public TForm
{
__published:	// IDE-managed Components
	TComboBox *InputSourceCb;
	TComboBox *VolumeSourceCb;
	TTrackBar *VolumeTrackBar;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSourceForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSourceForm *SourceForm;
//---------------------------------------------------------------------------
#endif
