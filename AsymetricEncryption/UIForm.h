#pragma once

#include "MainForm.h"
#include "UIAbout.h"
#include <vcclr.h> 
#include <msclr/marshal_cppstd.h>

namespace AsymetricEncryption {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace msclr::interop;

    public ref class UIForm : public System::Windows::Forms::Form
    {
    public:
        UIForm(MainForm* main) {
            InitializeComponent();
            mainForm = main;
        }

    protected:
        ~UIForm() {   }
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    protected:
    private: System::Windows::Forms::ToolStripMenuItem^ ïğîÏğîãğàìóToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ îáğàòèÔàéëÊëş÷àToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ îáğàòèÀëãîğèòìToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ rSAToolStripMenuItem;
    private: System::Windows::Forms::StatusStrip^ statusStrip1;
    private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
    private: System::Windows::Forms::ToolStripMenuItem^ eCCToolStripMenuItem;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::ProgressBar^ progressBar1;
    private: System::Windows::Forms::StatusStrip^ statusStrip2;
    private: System::Windows::Forms::Button^ button3;

    private:
        MainForm* mainForm;







        // Èíèöèàëèçàöèÿ UI


    private: System::Void InitializeComponent() {
        this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
        this->ïğîÏğîãğàìóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->îáğàòèÔàéëÊëş÷àToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->îáğàòèÀëãîğèòìToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->rSAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->eCCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->button2 = (gcnew System::Windows::Forms::Button());
        this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
        this->statusStrip2 = (gcnew System::Windows::Forms::StatusStrip());
        this->button3 = (gcnew System::Windows::Forms::Button());
        this->menuStrip1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
        this->SuspendLayout();
        // 
        // menuStrip1
        // 
        this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
            this->ïğîÏğîãğàìóToolStripMenuItem,
                this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem, this->îáğàòèÔàéëÊëş÷àToolStripMenuItem, this->îáğàòèÀëãîğèòìToolStripMenuItem
        });
        this->menuStrip1->Location = System::Drawing::Point(0, 0);
        this->menuStrip1->Name = L"menuStrip1";
        this->menuStrip1->Size = System::Drawing::Size(651, 24);
        this->menuStrip1->TabIndex = 0;
        this->menuStrip1->Text = L"menuStrip1";
        // 
        // ïğîÏğîãğàìóToolStripMenuItem
        // 
        this->ïğîÏğîãğàìóToolStripMenuItem->Name = L"ïğîÏğîãğàìóToolStripMenuItem";
        this->ïğîÏğîãğàìóToolStripMenuItem->Size = System::Drawing::Size(99, 20);
        this->ïğîÏğîãğàìóToolStripMenuItem->Text = L"Ïğî ïğîãğàìó";
        this->ïğîÏğîãğàìóToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::ïğîÏğîãğàìóToolStripMenuItem_Click);
        // 
        // îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem
        // 
        this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem->Name = L"îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem";
        this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem->Size = System::Drawing::Size(284, 20);
        this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem->Text = L"Îáğàòè ôàéë äëÿ øèôğóâàííÿ / äåøèôğóâàííÿ";
        this->îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem_Click);
        // 
        // îáğàòèÔàéëÊëş÷àToolStripMenuItem
        // 
        this->îáğàòèÔàéëÊëş÷àToolStripMenuItem->Name = L"îáğàòèÔàéëÊëş÷àToolStripMenuItem";
        this->îáğàòèÔàéëÊëş÷àToolStripMenuItem->Size = System::Drawing::Size(131, 20);
        this->îáğàòèÔàéëÊëş÷àToolStripMenuItem->Text = L"Îáğàòè ôàéë êëş÷à";
        this->îáğàòèÔàéëÊëş÷àToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::îáğàòèÔàéëÊëş÷àToolStripMenuItem_Click);
        // 
        // îáğàòèÀëãîğèòìToolStripMenuItem
        // 
        this->îáğàòèÀëãîğèòìToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
            this->rSAToolStripMenuItem,
                this->eCCToolStripMenuItem
        });
        this->îáğàòèÀëãîğèòìToolStripMenuItem->Name = L"îáğàòèÀëãîğèòìToolStripMenuItem";
        this->îáğàòèÀëãîğèòìToolStripMenuItem->Size = System::Drawing::Size(118, 20);
        this->îáğàòèÀëãîğèòìToolStripMenuItem->Text = L"Îáğàòè Àëãîğèòì";
        // 
        // rSAToolStripMenuItem
        // 
        this->rSAToolStripMenuItem->Name = L"rSAToolStripMenuItem";
        this->rSAToolStripMenuItem->Size = System::Drawing::Size(96, 22);
        this->rSAToolStripMenuItem->Text = L"RSA";
        this->rSAToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::rSAToolStripMenuItem_Click);
        // 
        // eCCToolStripMenuItem
        // 
        this->eCCToolStripMenuItem->Name = L"eCCToolStripMenuItem";
        this->eCCToolStripMenuItem->Size = System::Drawing::Size(96, 22);
        this->eCCToolStripMenuItem->Text = L"ElGamal ";
        this->eCCToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::eCCToolStripMenuItem_Click);
        // 
        // dSAToolStripMenuItem
        // 

        // 
        // pictureBox1
        // 
        this->pictureBox1->Location = System::Drawing::Point(58, 96);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(115, 121);
        this->pictureBox1->TabIndex = 1;
        this->pictureBox1->TabStop = false;
        this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
        this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\close.png");

        // 
        // pictureBox2
        // 
        this->pictureBox2->Location = System::Drawing::Point(474, 96);
        this->pictureBox2->Name = L"pictureBox2";
        this->pictureBox2->Size = System::Drawing::Size(115, 121);
        this->pictureBox2->TabIndex = 2;
        this->pictureBox2->TabStop = false;
        this->pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
        this->pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\close.png");

        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(12, 66);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(209, 13);
        this->label1->TabIndex = 3;
        this->label1->Text = L"Ôàéë äëÿ øèôğóâàííÿ / äåøèôğóâàííÿ";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(495, 66);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(71, 13);
        this->label2->TabIndex = 4;
        this->label2->Text = L"Ôàéë Êëş÷à";
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(271, 242);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(100, 23);
        this->button1->TabIndex = 5;
        this->button1->Text = L"Øèôğóâàòè";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &UIForm::button1_Click);
        // 
        // button2
        // 
        this->button2->Location = System::Drawing::Point(271, 287);
        this->button2->Name = L"button2";
        this->button2->Size = System::Drawing::Size(100, 23);
        this->button2->TabIndex = 6;
        this->button2->Text = L"Äåøèôğóâàòè";
        this->button2->UseVisualStyleBackColor = true;
        this->button2->Click += gcnew System::EventHandler(this, &UIForm::button2_Click);
        // 
        // progressBar1
        // 
        this->progressBar1->Location = System::Drawing::Point(271, 343);
        this->progressBar1->Name = L"progressBar1";
        this->progressBar1->Size = System::Drawing::Size(100, 23);
        this->progressBar1->TabIndex = 7;
        // 
        // statusStrip2
        // 
        this->statusStrip2->Location = System::Drawing::Point(0, 369);
        this->statusStrip2->Name = L"statusStrip2";
        this->statusStrip2->Size = System::Drawing::Size(651, 22);
        this->statusStrip2->TabIndex = 8;
        this->statusStrip2->Text = L"statusStrip2";
        // 
        // button3
        // 
        this->button3->Location = System::Drawing::Point(271, 184);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(100, 23);
        this->button3->TabIndex = 9;
        this->button3->Text = L"Çãåíåğóâàòè êëş÷³";
        this->button3->UseVisualStyleBackColor = true;
        this->button3->Click += gcnew System::EventHandler(this, &UIForm::button3_Click);
        // 
        // UIForm
        // 
        this->Icon = gcnew System::Drawing::Icon("lock.ico");

        this->ClientSize = System::Drawing::Size(651, 391);
        this->Controls->Add(this->button3);
        this->Controls->Add(this->statusStrip2);
        this->Controls->Add(this->progressBar1);
        this->Controls->Add(this->button2);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->pictureBox2);
        this->Controls->Add(this->pictureBox1);
        this->Controls->Add(this->menuStrip1);
        this->MainMenuStrip = this->menuStrip1;
        this->Name = L"UIForm";
        this->menuStrip1->ResumeLayout(false);
        this->menuStrip1->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }
    private: System::Windows::Forms::ToolStripMenuItem^ dSAToolStripMenuItem;


   

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBar1->Value = 0;
    mainForm->OnEncrypt();
    progressBar1->Value = 34;    
    progressBar1->Value = 100;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBar1->Value = 0;
    mainForm->OnDecrypt();
    progressBar1->Value = 56;
  
    progressBar1->Value = 100;
}
private: System::Void ïğîÏğîãğàìóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBar1->Value = 0;
    AsymetricEncryption::UIAbout^ uia = gcnew AsymetricEncryption::UIAbout();
    uia->ShowDialog();

}
private: System::Void îáğàòèÔàéëÄëÿØèôğóâàííÿÄåøèôğóâàííÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBar1->Value = 0;
    mainForm->OnOpenFile();

    String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
    MessageBox::Show(selectedFile, "Îáğàíèé ôàéë");  // Ïğîâåğÿåì ïóòü â MessageBox

    if (!String::IsNullOrEmpty(selectedFile) && System::IO::File::Exists(selectedFile)) {
        this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\txt-file.png");
    }
    else {
        this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\close.png");
    }
}

private: System::Void îáğàòèÔàéëÊëş÷àToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBar1->Value = 0;
    mainForm->OnSelectKey();


    MessageBox::Show(gcnew String(mainForm->GetSelectedKey().c_str()), "Âèáğàíèé êëş÷");
    String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
    MessageBox::Show(selectedFile, "Îáğàíèé ôàéë");  


    if (!String::IsNullOrEmpty(selectedFile) && System::IO::File::Exists(selectedFile)) {
        this->pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\key.png");
    }
    else {
        this->pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\close.png");
    }
}
private: System::Void rSAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    mainForm->SetAlgorithm("RSA");
}
private: System::Void eCCToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    mainForm->SetAlgorithm("ElGamal ");
}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    mainForm->cryptoHandler.GenerateKeys("public.key", "private.key");
    MessageBox::Show(L"Êëş÷³ óñï³øíî çãåíåğîâàíî!", L"Ãåíåğàö³ÿ êëş÷³â", MessageBoxButtons::OK, MessageBoxIcon::Information);   
}
};
    
}
