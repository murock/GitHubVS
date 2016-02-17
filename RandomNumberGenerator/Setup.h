#pragma once
#include "mylib.h"
#include "TimetableGenerator.h"


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
	private: System::Windows::Forms::Button^  NextButton;
	private: System::Windows::Forms::Label^  QuestionLabel;
	private: System::Windows::Forms::TextBox^  AnswerBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  nextSubjectButton;
	private: System::Windows::Forms::Button^  nextClassButton;
	private: System::Windows::Forms::Button^  enterTeachersButton;
	private: System::Windows::Forms::Button^  enterRoomsButton;
	private: System::Windows::Forms::Button^  enterSubjectsButton;


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
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->QuestionLabel = (gcnew System::Windows::Forms::Label());
			this->AnswerBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nextSubjectButton = (gcnew System::Windows::Forms::Button());
			this->nextClassButton = (gcnew System::Windows::Forms::Button());
			this->enterTeachersButton = (gcnew System::Windows::Forms::Button());
			this->enterRoomsButton = (gcnew System::Windows::Forms::Button());
			this->enterSubjectsButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// NextButton
			// 
			this->NextButton->Location = System::Drawing::Point(237, 47);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(75, 23);
			this->NextButton->TabIndex = 0;
			this->NextButton->Text = L"Next";
			this->NextButton->UseVisualStyleBackColor = true;
			this->NextButton->Click += gcnew System::EventHandler(this, &Setup::NextButton_Click);
			// 
			// QuestionLabel
			// 
			this->QuestionLabel->AutoSize = true;
			this->QuestionLabel->Location = System::Drawing::Point(22, 9);
			this->QuestionLabel->Name = L"QuestionLabel";
			this->QuestionLabel->Size = System::Drawing::Size(236, 13);
			this->QuestionLabel->TabIndex = 1;
			this->QuestionLabel->Text = L"List subjects taught. e.g (Maths,English,Science)";
			// 
			// AnswerBox
			// 
			this->AnswerBox->Location = System::Drawing::Point(20, 42);
			this->AnswerBox->Name = L"AnswerBox";
			this->AnswerBox->Size = System::Drawing::Size(155, 20);
			this->AnswerBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// nextSubjectButton
			// 
			this->nextSubjectButton->Location = System::Drawing::Point(222, 47);
			this->nextSubjectButton->Name = L"nextSubjectButton";
			this->nextSubjectButton->Size = System::Drawing::Size(90, 23);
			this->nextSubjectButton->TabIndex = 4;
			this->nextSubjectButton->Text = L"Next Subject";
			this->nextSubjectButton->UseVisualStyleBackColor = true;
			this->nextSubjectButton->Visible = false;
			this->nextSubjectButton->Click += gcnew System::EventHandler(this, &Setup::nextSubjectButton_Click);
			// 
			// nextClassButton
			// 
			this->nextClassButton->Location = System::Drawing::Point(224, 49);
			this->nextClassButton->Name = L"nextClassButton";
			this->nextClassButton->Size = System::Drawing::Size(87, 20);
			this->nextClassButton->TabIndex = 5;
			this->nextClassButton->Text = L"Enter Class Names";
			this->nextClassButton->UseVisualStyleBackColor = true;
			this->nextClassButton->Visible = false;
			this->nextClassButton->Click += gcnew System::EventHandler(this, &Setup::nextClassButton_Click);
			// 
			// enterTeachersButton
			// 
			this->enterTeachersButton->Location = System::Drawing::Point(222, 50);
			this->enterTeachersButton->Name = L"enterTeachersButton";
			this->enterTeachersButton->Size = System::Drawing::Size(88, 19);
			this->enterTeachersButton->TabIndex = 6;
			this->enterTeachersButton->Text = L"Enter Teachers";
			this->enterTeachersButton->UseVisualStyleBackColor = true;
			this->enterTeachersButton->Visible = false;
			this->enterTeachersButton->Click += gcnew System::EventHandler(this, &Setup::enterTeachersButton_Click);
			// 
			// enterRoomsButton
			// 
			this->enterRoomsButton->Location = System::Drawing::Point(224, 49);
			this->enterRoomsButton->Name = L"enterRoomsButton";
			this->enterRoomsButton->Size = System::Drawing::Size(87, 20);
			this->enterRoomsButton->TabIndex = 7;
			this->enterRoomsButton->Text = L"Enter Rooms";
			this->enterRoomsButton->UseVisualStyleBackColor = true;
			this->enterRoomsButton->Visible = false;
			this->enterRoomsButton->Click += gcnew System::EventHandler(this, &Setup::enterRoomsButton_Click);
			// 
			// enterSubjectsButton
			// 
			this->enterSubjectsButton->Location = System::Drawing::Point(224, 47);
			this->enterSubjectsButton->Name = L"enterSubjectsButton";
			this->enterSubjectsButton->Size = System::Drawing::Size(88, 22);
			this->enterSubjectsButton->TabIndex = 8;
			this->enterSubjectsButton->Text = L"Enter Subjects";
			this->enterSubjectsButton->UseVisualStyleBackColor = true;
			this->enterSubjectsButton->Visible = false;
			this->enterSubjectsButton->Click += gcnew System::EventHandler(this, &Setup::enterSubjectsButton_Click);
			// 
			// Setup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(324, 139);
			this->Controls->Add(this->enterSubjectsButton);
			this->Controls->Add(this->enterRoomsButton);
			this->Controls->Add(this->enterTeachersButton);
			this->Controls->Add(this->nextClassButton);
			this->Controls->Add(this->nextSubjectButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->AnswerBox);
			this->Controls->Add(this->QuestionLabel);
			this->Controls->Add(this->NextButton);
			this->Name = L"Setup";
			this->Text = L"Setup";
			this->Load += gcnew System::EventHandler(this, &Setup::Setup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Setup_Load(System::Object^  sender, System::EventArgs^  e) {
	}

			 int hoursPageNum = 0;
			 int teacherPageNum = 0;
			 int roomsPageNum = 0;
			 int subjectsPageNum = 0;
	private: System::Void NextButton_Click(System::Object^  sender, System::EventArgs^  e) {

		_RPT0(0, "Button Pressed\n");
			DefaultValues();
		//_RPT0(0, "Default values generated\n");

			AttachTeachertoGroup();
			Generate();
			checkTimetable();

	/*		String^ temp;
			temp = System::Convert::ToString(AnswerBox->Text);	//gets the text from the answer box and saves it to temp

			std::string converted_temp = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
			std::stringstream ss(converted_temp);

			std::string str;

			while (std::getline(ss, str, ','))	//puts the string into a vector 
			{
				subjects.push_back(str);

			}
			temp = msclr::interop::marshal_as< String^ >(subjects[1]);	//test to print vector
			label1->Text = temp;



			NextButton->Hide();		//hide the next button
			nextSubjectButton->Show();	//show the next subject button
		    temp = msclr::interop::marshal_as< String^ >(subjects[0]);
			QuestionLabel->Text = "How many Hours are needed to teach " + temp + "?";
			AnswerBox->Text = "";

			/*
			std::string test = "hello";			


			_RPT1(0, "The test variable is %s\n",test.c_str());  //prints to output


			std::vector<std::string>::const_iterator iter;
			for (iter = subjects.begin(); iter != subjects.end() ; ++iter) {		//iterates through the subjects vector
				temp = msclr::interop::marshal_as< String^ >(*iter);



			}*/

	}

	private: System::Void nextSubjectButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (hoursPageNum < (subjects.size() -1)) {
			String^ temp = msclr::interop::marshal_as< String^ >(subjects[hoursPageNum+1]); 
			QuestionLabel->Text = "How many Hours are needed to teach " + temp + "?";
			double tempInt;
			tempInt = System::Convert::ToDouble(AnswerBox->Text);
			AnswerBox->Text = ""; //clear answer box
			hoursSubject.push_back(tempInt);
			label1->Text = "Added to vector hoursSubject vector location " + System::Convert::ToString(hoursPageNum);
			//label1->Text = System::Convert::ToString(hoursSubject[hoursPageNum]);
		}
		else {
			nextSubjectButton->Hide();	//hide the next subject button
			nextClassButton->Show();		//Show the next class button
			this->QuestionLabel->Text = "List class names. e.g (7A,7B,7C)";
			AnswerBox->Text = "";	//clear answer box text
		}
		hoursPageNum++;
	}

private: System::Void nextClassButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ temp;
	temp = System::Convert::ToString(AnswerBox->Text);	//gets the text from the answer box and saves it to temp

	std::string converted_temp = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
	std::stringstream ss(converted_temp);

	std::string str;

	while (std::getline(ss, str, ','))	//puts the string into a vector 
	{
		groupNames.push_back(str);
	}
	nextClassButton->Hide();	//hide the next subject button
	enterTeachersButton->Show();		//Show the next class button
	temp = msclr::interop::marshal_as< String^ >(subjects[0]);
	this->QuestionLabel->Text = "List teacher names for " + temp + " e.g (Mr Coats,Dr Lane,Miss Baker)";
	AnswerBox->Text = "";	//clear answer box text
}

private: System::Void enterTeachersButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (teacherPageNum < (subjects.size() - 1)) {
		String^ temp;
		std::vector<std::string> tempVector;
		temp = System::Convert::ToString(AnswerBox->Text);	//gets the text from the answer box and saves it to temp

		std::string converted_temp = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
		std::stringstream ss(converted_temp);

		std::string str;

		while (std::getline(ss, str, ','))	//puts the string into a vector 
		{
			tempVector.push_back(str);
		}
		teacherNames.push_back(tempVector);	//put the temp vector into the teacher names 2d vector
		temp = msclr::interop::marshal_as< String^ >(subjects[teacherPageNum + 1]);
		this->QuestionLabel->Text = "List teacher names for " + temp + " e.g (Mr Coats,Dr Lane,Miss Baker)";
		AnswerBox->Text = "";
	}
	else {
		String^ temp;
		enterTeachersButton->Hide();	
		enterRoomsButton->Show();		
		temp = msclr::interop::marshal_as< String^ >(subjects[0]);
		this->QuestionLabel->Text = "List room names for " + temp + " e.g (M1,M2,A3)";
		AnswerBox->Text = "";	//clear answer box text
	}
	teacherPageNum++;
}

private: System::Void enterRoomsButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (roomsPageNum < (subjects.size() - 1)) {
		String^ temp;
		std::vector<std::string> tempVector;
		temp = System::Convert::ToString(AnswerBox->Text);	//gets the text from the answer box and saves it to temp

		std::string converted_temp = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
		std::stringstream ss(converted_temp);

		std::string str;

		while (std::getline(ss, str, ','))	//puts the string into a vector 
		{
			tempVector.push_back(str);
		}
		roomNames.push_back(tempVector);	//put the temp vector into the room names 2d vector
		temp = msclr::interop::marshal_as< String^ >(subjects[roomsPageNum + 1]);
		this->QuestionLabel->Text = "List room names for " + temp + " e.g (M1,M2,A3)";
		AnswerBox->Text = "";
	}
	else {
		String^ temp;
		enterRoomsButton->Hide();	
		enterSubjectsButton->Show();		
		temp = msclr::interop::marshal_as< String^ >(groupNames[0]);
		this->QuestionLabel->Text = "List subjects for class " + temp + " e.g (Maths,English,Science)";
		AnswerBox->Text = "";	//clear answer box text
	}
	roomsPageNum++;
}

private: System::Void enterSubjectsButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (subjectsPageNum < (groupNames.size() - 1)) {
		String^ temp;
		std::vector<std::string> tempVector;
		temp = System::Convert::ToString(AnswerBox->Text);	//gets the text from the answer box and saves it to temp

		std::string converted_temp = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
		std::stringstream ss(converted_temp);

		std::string str;

		while (std::getline(ss, str, ','))	//puts the string into a vector 
		{
			tempVector.push_back(str);
		}
		roomNames.push_back(tempVector);	//put the temp vector into the room names 2d vector
		temp = msclr::interop::marshal_as< String^ >(groupNames[subjectsPageNum + 1]);
		this->QuestionLabel->Text = "List subjects for class" + temp + " e.g (Maths,English,Science)";
		AnswerBox->Text = "";
	}
	else {
		this->QuestionLabel->Text = "Set-up Finished";
		AnswerBox->Text = "";	//clear answer box text

		}
	subjectsPageNum++;
}

};
}
