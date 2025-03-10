#pragma once
#include <vcclr.h> 
#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "UIAbout.h"

namespace AsymetricEncryption {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for UIForm1
	/// </summary>
	public ref class UIForm1 : public System::Windows::Forms::Form
	{
	public:
		UIForm1(MainForm* main)
		{
			InitializeComponent();
			mainForm = main;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutProgramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chooseFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chooseKeyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chooseAlghorithmToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rSAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ elGamalToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



	protected:


	private:
		MainForm* mainForm;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chooseFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chooseKeyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chooseAlghorithmToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rSAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elGamalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->aboutProgramToolStripMenuItem,
					this->chooseFileToolStripMenuItem, this->chooseKeyToolStripMenuItem, this->chooseAlghorithmToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(797, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->aboutProgramToolStripMenuItem->Text = L"Про програму";
			this->aboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::aboutProgramToolStripMenuItem_Click);
			// 
			// chooseFileToolStripMenuItem
			// 
			this->chooseFileToolStripMenuItem->Name = L"chooseFileToolStripMenuItem";
			this->chooseFileToolStripMenuItem->Size = System::Drawing::Size(284, 20);
			this->chooseFileToolStripMenuItem->Text = L"Обрати файл для шифрування / дешифрування";
			this->chooseFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::chooseFileToolStripMenuItem_Click);
			// 
			// chooseKeyToolStripMenuItem
			// 
			this->chooseKeyToolStripMenuItem->Name = L"chooseKeyToolStripMenuItem";
			this->chooseKeyToolStripMenuItem->Size = System::Drawing::Size(285, 20);
			this->chooseKeyToolStripMenuItem->Text = L"Обрати ключ для шифрування / дешифрування";
			this->chooseKeyToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::chooseKeyToolStripMenuItem_Click);
			// 
			// chooseAlghorithmToolStripMenuItem
			// 
			this->chooseAlghorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->rSAToolStripMenuItem,
					this->elGamalToolStripMenuItem
			});
			this->chooseAlghorithmToolStripMenuItem->Name = L"chooseAlghorithmToolStripMenuItem";
			this->chooseAlghorithmToolStripMenuItem->Size = System::Drawing::Size(119, 20);
			this->chooseAlghorithmToolStripMenuItem->Text = L"Обрати алгоритм ";
			// 
			// rSAToolStripMenuItem
			// 
			this->rSAToolStripMenuItem->Name = L"rSAToolStripMenuItem";
			this->rSAToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->rSAToolStripMenuItem->Text = L"RSA";
			this->rSAToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::rSAToolStripMenuItem_Click);
			// 
			// elGamalToolStripMenuItem
			// 
			this->elGamalToolStripMenuItem->Name = L"elGamalToolStripMenuItem";
			this->elGamalToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->elGamalToolStripMenuItem->Text = L"ElGamal";
			this->elGamalToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::elGamalToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(116, 79);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(118, 113);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\close.png");
			this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(560, 79);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(118, 113);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\close.png");
			this->pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(322, 223);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Генерувати ключі";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UIForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(322, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Шифрувати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UIForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(322, 322);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"дешифрувати";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UIForm1::button3_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(322, 371);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(106, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(263, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Текстовий файл для шифрування / дешифрування";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(509, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(206, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Ключ для шифрування / дешифрування";
			// 
			// UIForm1
			// 
			this->Icon = gcnew System::Drawing::Icon("lock.ico");
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 419);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"UIForm1";
			this->Text = L"Асиметричний шифрувальник";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->cryptoHandler.GenerateKeys("public.key", "private.key");
	MessageBox::Show(L"Ключі успішно згенеровано!", L"Генерація ключів", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	mainForm->OnEncrypt();
	progressBar1->Value = 34;
	progressBar1->Value = 100;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	mainForm->OnDecrypt();
	progressBar1->Value = 56;

	progressBar1->Value = 100;
}
private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	AsymetricEncryption::UIAbout^ uia = gcnew AsymetricEncryption::UIAbout();
	uia->ShowDialog();
}
private: System::Void chooseFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	mainForm->OnOpenFile();

	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	MessageBox::Show(selectedFile, "Обраний файл");  // Проверяем путь в MessageBox

	if (!String::IsNullOrEmpty(selectedFile) && System::IO::File::Exists(selectedFile)) {
		this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\txt-file.png");
	}
	else {
		this->pictureBox1->Image = Image::FromFile(Application::StartupPath + "\\close.png");
	}
}
private: System::Void chooseKeyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Value = 0;
	mainForm->OnSelectKey();


	MessageBox::Show(gcnew String(mainForm->GetSelectedKey().c_str()), "Вибраний ключ");
	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	MessageBox::Show(selectedFile, "Обраний файл");


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
private: System::Void elGamalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->SetAlgorithm("ElGamal ");
}
};
}
