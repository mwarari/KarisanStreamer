//---------------------------------------------------------------------------

#ifndef OutputFrmH
#define OutputFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TOutputForm : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *LProgressBar;
	TProgressBar *RProgressBar;
	TLabel *Label1;
	TLabel *Label2;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TLabel *Label3;
	TLabel *Label4;
	TTrackBar *TrackBar3;
	TLabel *Label5;
private:	// User declarations
public:		// User declarations
	__fastcall TOutputForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOutputForm *OutputForm;
//---------------------------------------------------------------------------
#endif
