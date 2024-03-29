//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("StreamsFrm.cpp", StreamsForm);
USEFORM("OutputFrm.cpp", OutputForm);
USEFORM("CHILDWIN.CPP", MDIChild);
USEFORM("MediaLibraryFrm.cpp", MediaLibraryForm);
USEFORM("about.cpp", AboutBox);
USEFORM("SourceFrm.cpp", SourceForm);
USEFORM("MAIN.CPP", MainForm);
USEFORM("StreamSettingsFrm.cpp", StreamSettingsForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TStreamsForm), &StreamsForm);
		Application->CreateForm(__classid(TStreamSettingsForm), &StreamSettingsForm);
		Application->CreateForm(__classid(TSourceForm), &SourceForm);
		Application->CreateForm(__classid(TOutputForm), &OutputForm);
		Application->CreateForm(__classid(TMediaLibraryForm), &MediaLibraryForm);
		Application->Run();

	return 0;
}
//---------------------------------------------------------------------
