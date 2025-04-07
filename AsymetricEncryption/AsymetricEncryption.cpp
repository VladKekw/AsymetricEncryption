#include "UIForm1.h"
#include "MainForm.h"
#include "UIAbout.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);




    MainForm* mainForm = new MainForm(hInstance);  
    AsymetricEncryption::UIForm1^ ui = gcnew  AsymetricEncryption::UIForm1(mainForm);  
    

    Application::Run(ui);  
    delete mainForm;  
    return 0;
}
