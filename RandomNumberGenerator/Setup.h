#pragma once
#include "mylib.h"
#include "TimetableGenerator.h"
#include "TimetableViewer.h"
#include "timetableScore.h"
#include "ConfigHelp.h"


namespace TimetableGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Setup
	/// </summary>
	public ref class Setup : public System::Windows::Forms::Form
	{
	public:
		Setup(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Setup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  advButton;
	protected:











	private: System::Windows::Forms::Button^  preconButton;
	private: System::Windows::Forms::Button^  configButton;
	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::Button^  configHelpButton;
	private: System::Windows::Forms::Label^  genLabel;
	private: System::Windows::Forms::Label^  popLabel;
	private: System::Windows::Forms::Label^  eliteLabel;
	private: System::Windows::Forms::Label^  culLabel;
	private: System::Windows::Forms::Label^  mutLabel;
	private: System::Windows::Forms::TextBox^  genTextBox;
	private: System::Windows::Forms::TextBox^  popTextBox;
	private: System::Windows::Forms::TextBox^  eliteTextBox;
	private: System::Windows::Forms::TextBox^  culTextBox;
	private: System::Windows::Forms::TextBox^  mutTextBox;
	private: System::Windows::Forms::Button^  inputButton;




	protected:

	private:
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
			this->advButton = (gcnew System::Windows::Forms::Button());
			this->preconButton = (gcnew System::Windows::Forms::Button());
			this->configButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->configHelpButton = (gcnew System::Windows::Forms::Button());
			this->genLabel = (gcnew System::Windows::Forms::Label());
			this->popLabel = (gcnew System::Windows::Forms::Label());
			this->eliteLabel = (gcnew System::Windows::Forms::Label());
			this->culLabel = (gcnew System::Windows::Forms::Label());
			this->mutLabel = (gcnew System::Windows::Forms::Label());
			this->genTextBox = (gcnew System::Windows::Forms::TextBox());
			this->popTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eliteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->culTextBox = (gcnew System::Windows::Forms::TextBox());
			this->mutTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// advButton
			// 
			this->advButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->advButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->advButton->Location = System::Drawing::Point(45, 12);
			this->advButton->Name = L"advButton";
			this->advButton->Size = System::Drawing::Size(140, 27);
			this->advButton->TabIndex = 9;
			this->advButton->Text = L"Advanced Options";
			this->advButton->UseVisualStyleBackColor = false;
			this->advButton->Click += gcnew System::EventHandler(this, &Setup::advButton_Click);
			// 
			// preconButton
			// 
			this->preconButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->preconButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->preconButton->Location = System::Drawing::Point(26, 140);
			this->preconButton->Name = L"preconButton";
			this->preconButton->Size = System::Drawing::Size(186, 28);
			this->preconButton->TabIndex = 10;
			this->preconButton->Text = L"Load Saved Timetables";
			this->preconButton->UseVisualStyleBackColor = false;
			this->preconButton->Click += gcnew System::EventHandler(this, &Setup::preconButton_Click);
			// 
			// configButton
			// 
			this->configButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->configButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->configButton->Location = System::Drawing::Point(45, 45);
			this->configButton->Name = L"configButton";
			this->configButton->Size = System::Drawing::Size(140, 26);
			this->configButton->TabIndex = 11;
			this->configButton->Text = L"Load Configuration File ";
			this->configButton->UseVisualStyleBackColor = false;
			this->configButton->Click += gcnew System::EventHandler(this, &Setup::configButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveButton->Location = System::Drawing::Point(26, 107);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(186, 27);
			this->saveButton->TabIndex = 12;
			this->saveButton->Text = L"Save Timetables";
			this->saveButton->UseVisualStyleBackColor = false;
			this->saveButton->Click += gcnew System::EventHandler(this, &Setup::saveButton_Click);
			// 
			// configHelpButton
			// 
			this->configHelpButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->configHelpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->configHelpButton->Location = System::Drawing::Point(45, 78);
			this->configHelpButton->Name = L"configHelpButton";
			this->configHelpButton->Size = System::Drawing::Size(140, 23);
			this->configHelpButton->TabIndex = 13;
			this->configHelpButton->Text = L"Configuration Help";
			this->configHelpButton->UseVisualStyleBackColor = false;
			this->configHelpButton->Click += gcnew System::EventHandler(this, &Setup::configHelpButton_Click);
			// 
			// genLabel
			// 
			this->genLabel->AutoSize = true;
			this->genLabel->Location = System::Drawing::Point(13, 13);
			this->genLabel->Name = L"genLabel";
			this->genLabel->Size = System::Drawing::Size(64, 13);
			this->genLabel->TabIndex = 14;
			this->genLabel->Text = L"Generations";
			this->genLabel->Visible = false;
			// 
			// popLabel
			// 
			this->popLabel->AutoSize = true;
			this->popLabel->Location = System::Drawing::Point(13, 42);
			this->popLabel->Name = L"popLabel";
			this->popLabel->Size = System::Drawing::Size(80, 13);
			this->popLabel->TabIndex = 15;
			this->popLabel->Text = L"Population Size";
			this->popLabel->Visible = false;
			// 
			// eliteLabel
			// 
			this->eliteLabel->AutoSize = true;
			this->eliteLabel->Location = System::Drawing::Point(13, 74);
			this->eliteLabel->Name = L"eliteLabel";
			this->eliteLabel->Size = System::Drawing::Size(36, 13);
			this->eliteLabel->TabIndex = 16;
			this->eliteLabel->Text = L"Elitism";
			this->eliteLabel->Visible = false;
			// 
			// culLabel
			// 
			this->culLabel->AutoSize = true;
			this->culLabel->Location = System::Drawing::Point(13, 104);
			this->culLabel->Name = L"culLabel";
			this->culLabel->Size = System::Drawing::Size(38, 13);
			this->culLabel->TabIndex = 17;
			this->culLabel->Text = L"Culling";
			this->culLabel->Visible = false;
			// 
			// mutLabel
			// 
			this->mutLabel->AutoSize = true;
			this->mutLabel->Location = System::Drawing::Point(12, 137);
			this->mutLabel->Name = L"mutLabel";
			this->mutLabel->Size = System::Drawing::Size(48, 13);
			this->mutLabel->TabIndex = 18;
			this->mutLabel->Text = L"Mutation";
			this->mutLabel->Visible = false;
			// 
			// genTextBox
			// 
			this->genTextBox->Location = System::Drawing::Point(126, 6);
			this->genTextBox->Name = L"genTextBox";
			this->genTextBox->Size = System::Drawing::Size(28, 20);
			this->genTextBox->TabIndex = 19;
			this->genTextBox->Visible = false;
			// 
			// popTextBox
			// 
			this->popTextBox->Location = System::Drawing::Point(126, 39);
			this->popTextBox->Name = L"popTextBox";
			this->popTextBox->Size = System::Drawing::Size(28, 20);
			this->popTextBox->TabIndex = 20;
			this->popTextBox->Visible = false;
			// 
			// eliteTextBox
			// 
			this->eliteTextBox->Location = System::Drawing::Point(126, 67);
			this->eliteTextBox->Name = L"eliteTextBox";
			this->eliteTextBox->Size = System::Drawing::Size(28, 20);
			this->eliteTextBox->TabIndex = 21;
			this->eliteTextBox->Visible = false;
			// 
			// culTextBox
			// 
			this->culTextBox->Location = System::Drawing::Point(126, 97);
			this->culTextBox->Name = L"culTextBox";
			this->culTextBox->Size = System::Drawing::Size(28, 20);
			this->culTextBox->TabIndex = 22;
			this->culTextBox->Visible = false;
			// 
			// mutTextBox
			// 
			this->mutTextBox->Location = System::Drawing::Point(126, 130);
			this->mutTextBox->Name = L"mutTextBox";
			this->mutTextBox->Size = System::Drawing::Size(28, 20);
			this->mutTextBox->TabIndex = 23;
			this->mutTextBox->Visible = false;
			// 
			// inputButton
			// 
			this->inputButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->inputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputButton->Location = System::Drawing::Point(160, 69);
			this->inputButton->Name = L"inputButton";
			this->inputButton->Size = System::Drawing::Size(75, 23);
			this->inputButton->TabIndex = 24;
			this->inputButton->Text = L"Input";
			this->inputButton->UseVisualStyleBackColor = false;
			this->inputButton->Visible = false;
			this->inputButton->Click += gcnew System::EventHandler(this, &Setup::inputButton_Click);
			// 
			// Setup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(236, 178);
			this->Controls->Add(this->inputButton);
			this->Controls->Add(this->mutTextBox);
			this->Controls->Add(this->culTextBox);
			this->Controls->Add(this->eliteTextBox);
			this->Controls->Add(this->popTextBox);
			this->Controls->Add(this->genTextBox);
			this->Controls->Add(this->mutLabel);
			this->Controls->Add(this->culLabel);
			this->Controls->Add(this->eliteLabel);
			this->Controls->Add(this->popLabel);
			this->Controls->Add(this->genLabel);
			this->Controls->Add(this->configHelpButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->configButton);
			this->Controls->Add(this->preconButton);
			this->Controls->Add(this->advButton);
			this->Name = L"Setup";
			this->Text = L"Setup";
			this->Load += gcnew System::EventHandler(this, &Setup::Setup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int generations = 230, popSize = 30, elitism = 5, culling = 25, mutation = 1;		//default values for GA algorithm adjustment factors

	private: System::Void Setup_Load(System::Object^  sender, System::EventArgs^  e) {
	}




private: System::Void advButton_Click(System::Object^  sender, System::EventArgs^  e) {
	configHelpButton->Hide();
	saveButton->Hide();
	configButton->Hide();
	preconButton->Hide();
	advButton->Hide();
	inputButton->Show();
	mutTextBox->Show();
	culTextBox->Show();
	eliteTextBox->Show();
	popTextBox->Show();
	genTextBox->Show();
	mutLabel->Show();
	culLabel->Show();
	eliteLabel->Show();
	popLabel->Show();
	genLabel->Show();


	std::ostringstream convert;
	convert << generations;
	std::string tempString = convert.str();
	String^ temp = msclr::interop::marshal_as< String^ >(tempString);
	genTextBox->Text = temp;
	convert.str("");
	convert.clear();
	convert << popSize;
	tempString = convert.str();
	temp = msclr::interop::marshal_as< String^ >(tempString);
	popTextBox->Text = temp;
	convert.str("");
	convert.clear();
	convert << elitism;
	tempString = convert.str();
	temp = msclr::interop::marshal_as< String^ >(tempString);
	eliteTextBox->Text = temp;
	convert.str("");
	convert.clear();
	convert << culling;
	tempString = convert.str();
	temp = msclr::interop::marshal_as< String^ >(tempString);
	culTextBox->Text = temp;
	convert.str("");
	convert.clear();
	convert << mutation;
	tempString = convert.str();
	temp = msclr::interop::marshal_as< String^ >(tempString);
	mutTextBox->Text = temp;
}
private: System::Void preconButton_Click(System::Object^  sender, System::EventArgs^  e) {
	clearGlobals();
	loadConfig();
	LoadTimetable();
	TimetableViewer ^ form = gcnew TimetableViewer;
	form->ShowDialog();
}
private: System::Void configButton_Click(System::Object^  sender, System::EventArgs^  e) {
	clearGlobals();
	loadConfig();
	attachTeacherToGroup();
	populationGlobal = optimiseTimetable(generations, populationGlobal, 1, popSize, elitism, culling, mutation);
	TimetableViewer ^ form = gcnew TimetableViewer;
	form->ShowDialog();
}
private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveTimetable();
}
private: System::Void configHelpButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ConfigHelp ^ form = gcnew ConfigHelp;
	form->ShowDialog();
}
private: System::Void inputButton_Click(System::Object^  sender, System::EventArgs^  e) {
	configHelpButton->Show();
	saveButton->Show();
	configButton->Show();
	preconButton->Show();
	advButton->Show();
	inputButton->Hide();
	mutTextBox->Hide();
	culTextBox->Hide();
	eliteTextBox->Hide();
	popTextBox->Hide();
	genTextBox->Hide();
	mutLabel->Hide();
	culLabel->Hide();
	eliteLabel->Hide();
	popLabel->Hide();
	genLabel->Hide();
	generations = int::Parse(genTextBox->Text);
	popSize = int::Parse(popTextBox->Text);
	elitism = int::Parse(eliteTextBox->Text);
	culling = int::Parse(culTextBox->Text);
	mutation = int::Parse(mutTextBox->Text);
}
};
}
