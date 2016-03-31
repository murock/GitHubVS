#pragma once
#include "mylib.h"
#include "TimetableGenerator.h"
#include "TimetableViewer.h"
#include "timetableScore.h"

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
			this->SuspendLayout();
			// 
			// defaultButton
			// 
			this->defaultButton->Location = System::Drawing::Point(84, 25);
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->Size = System::Drawing::Size(140, 27);
			this->defaultButton->TabIndex = 9;
			this->defaultButton->Text = L"Load Default Values";
			this->defaultButton->UseVisualStyleBackColor = true;
			this->defaultButton->Click += gcnew System::EventHandler(this, &Setup::defaultButton_Click);
			// 
			// preconButton
			// 
			this->preconButton->Location = System::Drawing::Point(63, 82);
			this->preconButton->Name = L"preconButton";
			this->preconButton->Size = System::Drawing::Size(180, 28);
			this->preconButton->TabIndex = 10;
			this->preconButton->Text = L"Load Preconfiured Timetables";
			this->preconButton->UseVisualStyleBackColor = true;
			this->preconButton->Click += gcnew System::EventHandler(this, &Setup::preconButton_Click);
			// 
			// Setup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(324, 186);
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



	ClearGlobals();
	//DefaultValues();
	LoadConfig();
	_RPT0(0, "attach\n");  //prints to output
	AttachTeachertoGroup();
	_RPT0(0, "optimise\n");  //prints to output
	populationGlobal = optimiseTimetable(20, populationGlobal, 1, 40, 2);
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
	populationGlobal = optimiseTimetable(5, populationGlobal, 0, 40, 2);
/*	ClearGlobals();
	DefaultValues();
	LoadTimetable();*/
	TimetableViewer ^ form = gcnew TimetableViewer;
	form->ShowDialog();
}
};
}
