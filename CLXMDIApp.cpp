//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop
USEFORM("CLXAbout.cpp", AboutBox);
USEFORM("CLXChildWin.cpp", MDIChild);
USEFORM("CLXMain.cpp", MainForm);
//---------------------------------------------------------------------------
int main(void)
{
//        try
//        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->Run();
//        }
//        catch (Exception &exception)
//        {
//                 Application->ShowException(&exception);
//        }
        return 0;
}
//---------------------------------------------------------------------------

