#pragma once
#include <vcclr.h> 
#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "UIAbout.h"
#include <windows.h>

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
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	protected:
	private:
		MainForm* mainForm;

	private: System::Windows::Forms::StatusStrip^ statusStrip1;

	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ó·‡ÚË Î˛˜ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mniSaveas;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ Á‡ÍËÚËToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ¯ËÙÛ‚‡ÌÌˇToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ „ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ¯ËÙÛ‚‡ÚËToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ mnialgorithm;
	private: System::Windows::Forms::ToolStripMenuItem^ mnirsa;
	private: System::Windows::Forms::ToolStripMenuItem^ mniecc;
	private: System::Windows::Forms::ToolStripMenuItem^ mnieig;
	private: System::Windows::Forms::ToolStripMenuItem^ chooseKeyToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButtonGenerateKeys;

	private: System::Windows::Forms::ToolStripButton^ toolStripButtonEncrypt;

	private: System::Windows::Forms::ToolStripButton^ toolStripButtonDecrypt;




	private: System::Windows::Forms::TextBox^ txbOrgtext;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TextBox^ txbCrypttext;
	private: System::Windows::Forms::ToolStripMenuItem^ mniSave;
	private: System::Windows::Forms::SaveFileDialog^ dlgsave;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblCurrentAlghoInfo;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblCurrentAlgho;
	private: System::Windows::Forms::ToolTip^ toolTip2;






	private: System::ComponentModel::IContainer^ components;

		   /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UIForm1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniSaveas = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->Á‡ÍËÚËToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnialgorithm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnirsa = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniecc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnieig = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->lblCurrentAlghoInfo = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblCurrentAlgho = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonGenerateKeys = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonEncrypt = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonDecrypt = (gcnew System::Windows::Forms::ToolStripButton());
			this->txbOrgtext = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->txbCrypttext = (gcnew System::Windows::Forms::TextBox());
			this->dlgsave = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem, this->aboutProgramToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(797, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &UIForm1::menuStrip1_ItemClicked);
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem,
					this->Ó·‡ÚË Î˛˜ToolStripMenuItem, this->mniSave, this->mniSaveas, this->toolStripMenuItem1, this->Á‡ÍËÚËToolStripMenuItem
			});
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			this->Ù‡ÈÎToolStripMenuItem->ToolTipText = L"ŒÔˆ≥ø Ó·ÓÚË Á Ù‡ÈÎ‡ÏË";
			// 
			// Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem
			// 
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem->Name = L"Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem";
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem->Text = L"Œ·‡ÚË ÚÂÍÒÚÓ‚ËÈ Ù‡ÈÎ";
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem->ToolTipText = L"Œ·Ë‡∫ ÚÂÍÒÚÓ‚ËÈ Ù‡ÈÎ";
			this->Ó·‡ÚË“ÂÍÒÚÓ‚ËÈ‘‡ÈÎToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::chooseFileToolStripMenuItem_Click);
			// 
			// Ó·‡ÚË Î˛˜ToolStripMenuItem
			// 
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem->Name = L"Ó·‡ÚË Î˛˜ToolStripMenuItem";
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem->Text = L"Œ·‡ÚË ÍÎ˛˜";
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem->ToolTipText = L"Œ·Ë‡È Ù‡ÈÎ ÍÎ˛˜‡";
			this->Ó·‡ÚË Î˛˜ToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::chooseKeyToolStripMenuItem_Click);
			// 
			// mniSave
			// 
			this->mniSave->Name = L"mniSave";
			this->mniSave->Size = System::Drawing::Size(205, 22);
			this->mniSave->Text = L"«·ÂÂ„ÚË";
			this->mniSave->ToolTipText = L"«·Â≥„‡∫ Û ÔÓÚÓ˜ÌÓÏÛ Ù‡ÈÎ≥";
			this->mniSave->Click += gcnew System::EventHandler(this, &UIForm1::mniSave_Click);
			// 
			// mniSaveas
			// 
			this->mniSaveas->Name = L"mniSaveas";
			this->mniSaveas->Size = System::Drawing::Size(205, 22);
			this->mniSaveas->Text = L"«·ÂÂ„ÚË ˇÍ";
			this->mniSaveas->ToolTipText = L"«·Â≥„‡∫ Á‡ ‚ËÁÌ‡˜ÂÌËÏ ¯ÎˇıÓÏ";
			this->mniSaveas->Click += gcnew System::EventHandler(this, &UIForm1::mniSaveas_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(202, 6);
			// 
			// Á‡ÍËÚËToolStripMenuItem
			// 
			this->Á‡ÍËÚËToolStripMenuItem->Name = L"Á‡ÍËÚËToolStripMenuItem";
			this->Á‡ÍËÚËToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->Á‡ÍËÚËToolStripMenuItem->Text = L"«‡ÍËÚË";
			this->Á‡ÍËÚËToolStripMenuItem->ToolTipText = L"«‡ÍË‚‡∫ ÔÓ„‡ÏÛ";
			this->Á‡ÍËÚËToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::Á‡ÍËÚËToolStripMenuItem_Click);
			// 
			// ¯ËÙÛ‚‡ÌÌˇToolStripMenuItem
			// 
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem,
					this->¯ËÙÛ‚‡ÚËToolStripMenuItem, this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem, this->toolStripMenuItem2, this->mnialgorithm
			});
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem->Name = L"¯ËÙÛ‚‡ÌÌˇToolStripMenuItem";
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem->Size = System::Drawing::Size(91, 20);
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem->Text = L"ÿËÙÛ‚‡ÌÌˇ";
			this->¯ËÙÛ‚‡ÌÌˇToolStripMenuItem->ToolTipText = L" ËÔÚÓ„‡Ù≥˜Ì≥ ÏÂÚÓ‰Ë ÔÓ„‡ÏË";
			// 
			// „ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem
			// 
			this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem->Name = L"„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem";
			this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem->Text = L"√ÂÌÂÛ‚‡ÚË ÍÎ˛˜≥";
			this->„ÂÌÂÛ‚‡ÚË Î˛˜≥ToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::button1_Click);
			// 
			// ¯ËÙÛ‚‡ÚËToolStripMenuItem
			// 
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem->Name = L"¯ËÙÛ‚‡ÚËToolStripMenuItem";
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem->Text = L"ÿËÙÛ‚‡ÚË";
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem->ToolTipText = L"ÿËÙÛ∫ ÚÂÍÒÚ";
			this->¯ËÙÛ‚‡ÚËToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::button2_Click);
			// 
			// ‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem
			// 
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem->Name = L"‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem";
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem->Text = L"ƒÂ¯ËÙÛ‚‡ÚË";
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem->ToolTipText = L"ƒÂ¯ËÙÛ∫ ÚÂÍÒÚ";
			this->‰Â¯ËÙÛ‚‡ÚËToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::button3_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(177, 6);
			// 
			// mnialgorithm
			// 
			this->mnialgorithm->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mnirsa,
					this->mniecc, this->mnieig
			});
			this->mnialgorithm->Name = L"mnialgorithm";
			this->mnialgorithm->Size = System::Drawing::Size(180, 22);
			this->mnialgorithm->Text = L"¿Î„ÓËÚÏË";
			this->mnialgorithm->ToolTipText = L"ƒ‡∫ ÏÓÊÎË‚≥ÒÚ¸ Ó·‡ÚË 1 ≥Á 3 ‡Î„ÓËÚÏ≥‚";
			// 
			// mnirsa
			// 
			this->mnirsa->CheckOnClick = true;
			this->mnirsa->Name = L"mnirsa";
			this->mnirsa->Size = System::Drawing::Size(117, 22);
			this->mnirsa->Text = L"RSA";
			this->mnirsa->Click += gcnew System::EventHandler(this, &UIForm1::toolStripMenuItem8_Click);
			// 
			// mniecc
			// 
			this->mniecc->Name = L"mniecc";
			this->mniecc->Size = System::Drawing::Size(117, 22);
			this->mniecc->Text = L"ECC";
			this->mniecc->Click += gcnew System::EventHandler(this, &UIForm1::toolStripMenuItem8_Click);
			// 
			// mnieig
			// 
			this->mnieig->Name = L"mnieig";
			this->mnieig->Size = System::Drawing::Size(117, 22);
			this->mnieig->Text = L"ElGamal";
			this->mnieig->Click += gcnew System::EventHandler(this, &UIForm1::toolStripMenuItem8_Click);
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->aboutProgramToolStripMenuItem->Text = L"œÓ ÔÓ„‡ÏÛ";
			this->aboutProgramToolStripMenuItem->ToolTipText = L"¬≥‰ÍË‚‡∫ ≥ÌÙÓÏ‡ˆ≥ÈÌÂ ‚≥ÍÌÓ";
			this->aboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm1::aboutProgramToolStripMenuItem_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(322, 397);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(106, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripStatusLabel1,
					this->toolStripProgressBar1, this->lblCurrentAlghoInfo, this->lblCurrentAlgho
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 397);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(797, 22);
			this->statusStrip1->TabIndex = 9;
			this->statusStrip1->Text = L"Current status";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &UIForm1::statusStrip1_ItemClicked);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(166, 17);
			this->toolStripStatusLabel1->Text = L"œÓÚÓ˜ÌËÈ ÔÓ„ÂÒ ÓÔÂ‡ˆ≥ø: ";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &UIForm1::toolStripStatusLabel1_Click_1);
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			// 
			// lblCurrentAlghoInfo
			// 
			this->lblCurrentAlghoInfo->Name = L"lblCurrentAlghoInfo";
			this->lblCurrentAlghoInfo->Size = System::Drawing::Size(125, 17);
			this->lblCurrentAlghoInfo->Text = L"œÓÚÓ˜ÌËÈ ‡Î„ÓËÚÏ: ";
			this->lblCurrentAlghoInfo->Click += gcnew System::EventHandler(this, &UIForm1::lblCurrentAlgho_Click);
			// 
			// lblCurrentAlgho
			// 
			this->lblCurrentAlgho->Name = L"lblCurrentAlgho";
			this->lblCurrentAlgho->Size = System::Drawing::Size(28, 17);
			this->lblCurrentAlgho->Text = L"RSA";
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->InitialDelay = 500;
			this->toolTip1->ReshowDelay = 200;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripButtonGenerateKeys,
					this->toolStripButtonEncrypt, this->toolStripButtonDecrypt
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(797, 27);
			this->toolStrip1->TabIndex = 10;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButtonGenerateKeys
			// 
			this->toolStripButtonGenerateKeys->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonGenerateKeys->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonGenerateKeys.Image")));
			this->toolStripButtonGenerateKeys->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonGenerateKeys->Name = L"toolStripButtonGenerateKeys";
			this->toolStripButtonGenerateKeys->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonGenerateKeys->Text = L"toolStripButton1";
			this->toolStripButtonGenerateKeys->ToolTipText = L"√ÂÌÂÛ∫ ÍËÔÚÓ„‡Ù≥˜Ì≥ ÍÎ˛˜≥";
			this->toolStripButtonGenerateKeys->Click += gcnew System::EventHandler(this, &UIForm1::button1_Click);
			// 
			// toolStripButtonEncrypt
			// 
			this->toolStripButtonEncrypt->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonEncrypt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonEncrypt.Image")));
			this->toolStripButtonEncrypt->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonEncrypt->Name = L"toolStripButtonEncrypt";
			this->toolStripButtonEncrypt->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonEncrypt->Text = L"toolStripButton2";
			this->toolStripButtonEncrypt->ToolTipText = L"ÿËÙÛ∫ ÚÂÍÒÚ";
			this->toolStripButtonEncrypt->Click += gcnew System::EventHandler(this, &UIForm1::button2_Click);
			// 
			// toolStripButtonDecrypt
			// 
			this->toolStripButtonDecrypt->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonDecrypt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonDecrypt.Image")));
			this->toolStripButtonDecrypt->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonDecrypt->Name = L"toolStripButtonDecrypt";
			this->toolStripButtonDecrypt->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonDecrypt->Text = L"toolStripButton3";
			this->toolStripButtonDecrypt->ToolTipText = L"ƒÂ¯ËÙÛ∫ ÚÂÍÒÚ";
			this->toolStripButtonDecrypt->Click += gcnew System::EventHandler(this, &UIForm1::button3_Click);
			// 
			// txbOrgtext
			// 
			this->txbOrgtext->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txbOrgtext->Location = System::Drawing::Point(2, 2);
			this->txbOrgtext->Margin = System::Windows::Forms::Padding(2);
			this->txbOrgtext->Multiline = true;
			this->txbOrgtext->Name = L"txbOrgtext";
			this->txbOrgtext->ReadOnly = true;
			this->txbOrgtext->Size = System::Drawing::Size(394, 342);
			this->txbOrgtext->TabIndex = 11;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->txbCrypttext, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->txbOrgtext, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 51);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(797, 346);
			this->tableLayoutPanel1->TabIndex = 12;
			// 
			// txbCrypttext
			// 
			this->txbCrypttext->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txbCrypttext->Location = System::Drawing::Point(400, 2);
			this->txbCrypttext->Margin = System::Windows::Forms::Padding(2);
			this->txbCrypttext->Multiline = true;
			this->txbCrypttext->Name = L"txbCrypttext";
			this->txbCrypttext->ReadOnly = true;
			this->txbCrypttext->Size = System::Drawing::Size(395, 342);
			this->txbCrypttext->TabIndex = 12;
			// 
			// dlgsave
			// 
			this->dlgsave->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &UIForm1::dlgsave_FileOk);
			// 
			// UIForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 419);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"UIForm1";
			this->Text = L"¿ÒËÏÂÚË˜ÌËÈ ¯ËÙÛ‚‡Î¸ÌËÍ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->cryptoHandler.GenerateKeys("public.key", "private.key");
	MessageBox::Show(L" Î˛˜≥ ÛÒÔ≥¯ÌÓ Á„ÂÌÂÓ‚‡ÌÓ!", L"√ÂÌÂ‡ˆ≥ˇ ÍÎ˛˜≥‚", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripProgressBar1->Value = 0;
	mainForm->OnEncrypt();
	toolStripProgressBar1->Value = 34;

	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	if (!String::IsNullOrEmpty(selectedFile)) {
		txbCrypttext->Text = System::IO::File::ReadAllText(selectedFile);
	}
	toolStripProgressBar1->Value = 100;

}
	private: System::Void dlgsave_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	
	}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripProgressBar1->Value = 0;
	mainForm->OnDecrypt();
	toolStripProgressBar1->Value = 56;

	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	if (!String::IsNullOrEmpty(selectedFile)) {
		txbCrypttext->Text = System::IO::File::ReadAllText(selectedFile);
	}

	toolStripProgressBar1->Value = 100;
}
private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripProgressBar1->Value = 0;
	AsymetricEncryption::UIAbout^ uia = gcnew AsymetricEncryption::UIAbout();
	uia->ShowDialog();
}
private: System::Void chooseFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripProgressBar1->Value = 0;
	mainForm->OnOpenFile();

	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	if (!String::IsNullOrEmpty(selectedFile)) {
		txbOrgtext->Text = System::IO::File::ReadAllText(selectedFile);
	}
	MessageBox::Show(selectedFile, "Œ·‡ÌËÈ Ù‡ÈÎ");  

}
private: System::Void chooseKeyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripProgressBar1->Value = 0;
	mainForm->OnSelectKey();


	MessageBox::Show(gcnew String(mainForm->GetSelectedKey().c_str()), "Œ·‡ÌËÈ ÍÎ˛˜");
	String^ selectedFile = gcnew String(mainForm->GetSelectedFile().c_str());
	MessageBox::Show(selectedFile, "Œ·‡ÌËÈ Ù‡ÈÎ");

}
private: System::Void rSAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->SetAlgorithm("RSA");
}
private: System::Void elGamalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->SetAlgorithm("ElGamal");
}
private: System::Void eCCToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mainForm->SetAlgorithm("ECC");
}

private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void ‡Î„ÓËÚÏToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripMenuItem8_Click(System::Object^ sender, System::EventArgs^ e) {
	ToolStripMenuItem^ item = dynamic_cast<ToolStripMenuItem^>(sender);
	if (item) {
		mnirsa->Checked = false;
		mniecc->Checked = false;
		mnieig->Checked = false;

		item->Checked = true;
		std::string algorithm = msclr::interop::marshal_as<std::string>(item->Text);
		mainForm->SetAlgorithm(algorithm);
		lblCurrentAlgho->Text = item->Text;
	}
}

private: System::Void mniSaveas_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dlgsave->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::IO::File::WriteAllText(dlgsave->FileName, txbCrypttext->Text);
		MessageBox::Show(L"‘‡ÈÎ Á·ÂÂÊÂÌÓ!", L"«·ÂÂÊÂÌÌˇ", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

private: System::Void mniSave_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = gcnew String(mainForm->GetSelectedFile().c_str());
	if (!String::IsNullOrEmpty(filePath)) {
		System::IO::File::WriteAllText(filePath, txbCrypttext->Text);
		MessageBox::Show(L"‘‡ÈÎ ÓÌÓ‚ÎÂÌÓ!", L"«·ÂÂÊÂÌÌˇ", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void lblCurrentAlgho_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Á‡ÍËÚËToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
