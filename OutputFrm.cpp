//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OutputFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOutputForm *OutputForm;
//---------------------------------------------------------------------------
__fastcall TOutputForm::TOutputForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
