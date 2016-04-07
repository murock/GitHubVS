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










	private: System::Windows::Forms::Button^  defaultButton;
	private: System::Windows::Forms::Button^  preconButton;
	private: System::Windows::Forms::Button^  configButton;
	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::Button^  configHelpButton;



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
			this->defaultButton = (gcnew System::Windows::Forms::Button());
			this->preconButton = (gcnew System::Windows::Forms::Button());
			this->configButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->configHelpButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// defaultButton
			// 
			this->defaultButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->defaultButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->defaultButton->Location = System::Drawing::Point(45, 12);
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->Size = System::Drawing::Size(140, 27);
			this->defaultButton->TabIndex = 9;
			this->defaultButton->Text = L"Load Default Values";
			this->defaultButton->UseVisualStyleBackColor = false;
			this->defaultButton->Click += gcnew System::EventHandler(this, &Setup::defaultButton_Click);
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
			// Setup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(236, 178);
			this->Controls->Add(this->configHelpButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->configButton);
			this->Controls->Add(this->preconButton);
			this->Controls->Add(this->defaultButton);
			this->Name = L"Setup";
			this->Text = L"Setup";
			this->Load += gcnew System::EventHandler(this, &Setup::Setup_Load);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void Setup_Load(System::Object^  sender, System::EventArgs^  e) {
	}




private: System::Void defaultButton_Click(System::Object^  sender, System::EventArgs^  e) {
/*//	std::vector<std::string> names = {"1","2","3","4","5","6","7","8","9","10"};
	ClearGlobals();
	DefaultValues();
	AttachTeachertoGroup();
	//for (std::vector<std::string>::const_iterator iter = names.begin(); iter != names.end(); ++iter) {
		bool checkFeasible = 1;
		for (int i = 0; checkFeasible; i++) {
			//ClearGlobals();		//MAY NEED TO CHANGE THIS TO KEEP USER INPUT
		//	DefaultValues();	//THIS IS NOT GOOD RESETING USER TYPED IN INPUT
		//	AttachTeachertoGroup();
			Timetables.clear();
			Generate();
			checkFeasible = checkTimetable();
			_RPT1(0, "i is %d\n", i);  //prints to output
			//if (i == 4)
			//	this->QuestionLabel->Text = "TIMETABLE PRODUCED NOT FEASIBLE CHECK YOUR INPUTS";
		}
	//	std::string name = *iter;
		SaveTimetable1();
	//}
	SaveTeachers();*/



	/*ClearGlobals();
	//DefaultValues();
	LoadConfig();
	_RPT0(0, "attach\n");  //prints to output
	AttachTeachertoGroup();
	_RPT0(0, "optimise\n");  //prints to output*/
	populationGlobal = optimiseTimetable(100, populationGlobal, 0, 30, 2, 30, 1);
	_RPT0(0, "finish optimise\n");  //prints to output
	//testSelector();
	//Timetables = GenerateV2();

/*
	std::vector<Timetable> testTimetable = GenerateV2();



	int hardScore = checkTimetableV2(testTimetable);
	int softScore = ScoreTimetable(testTimetable);
	_RPT1(0, "The score for meeting hard constraints is %d\n", hardScore);  //prints to output
	_RPT1(0, "The score for meeting soft constraints is %d\n", softScore);  //prints to output
	
	Timetables = testTimetable;*/
	TimetableViewer ^ form = gcnew TimetableViewer;
	form->ShowDialog();
}
private: System::Void preconButton_Click(System::Object^  sender, System::EventArgs^  e) {
//	populationGlobal = optimiseTimetable(2, populationGlobal, 0, 10, 2, 10, 10);
//	ClearGlobals();
//	DefaultValues();
	ClearGlobals();
	LoadConfig();
	LoadTimetable();
	TimetableViewer ^ form = gcnew TimetableViewer;
	form->ShowDialog();
}
private: System::Void configButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ClearGlobals();
	LoadConfig();
	_RPT0(0, "attach\n");  //prints to output
	AttachTeachertoGroup();
	_RPT0(0, "optimise\n");  //prints to output
	populationGlobal = optimiseTimetable(1100, populationGlobal, 1, 50, 2, 50, 2);
	_RPT0(0, "finish optimise\n");  //prints to output
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
};
}
