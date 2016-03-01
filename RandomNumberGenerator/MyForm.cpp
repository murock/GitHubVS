#include "MyForm.h"
#include "Setup.h"
#include "TimetableViewer.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TimetableGui::Setup form;
	Application::Run(%form);


}