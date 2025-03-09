#include "UIForm.h"
#include "MainForm.h"
#include "UIAbout.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MainForm* mainForm = new MainForm(hInstance);  // Создаём MainForm (он хранит методы)
    AsymetricEncryption::UIForm^ ui = gcnew  AsymetricEncryption::UIForm(mainForm);  // Передаём mainForm в UIForm
    

    Application::Run(ui);  // Запускаем UI
    delete mainForm;  // Освобождаем память
    return 0;
}
