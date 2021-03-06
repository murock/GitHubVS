#pragma once
#include "mylib.h"
#include "Stats.h"
namespace TimetableGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TimetableViewer
	/// </summary>
	public ref class TimetableViewer : public System::Windows::Forms::Form
	{
	public:
		TimetableViewer(void)
		{
			InitializeComponent();
			InitializeComponent1();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TimetableViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  enterTimetableButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  fridayLabel;
	private: System::Windows::Forms::Label^  thursdayLabel;

	private: System::Windows::Forms::Label^  wednesdayLabel;
	private: System::Windows::Forms::Label^  tuesdayLabel;
	private: System::Windows::Forms::Label^  MondayLabel;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  tenLabel;

	private: System::Windows::Forms::Label^  nineLabel;
	private: System::Windows::Forms::Label^  twolabel;

	private: System::Windows::Forms::Label^  onelabel;

	private: System::Windows::Forms::Label^  elevenLabel;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  statsButton;



			 array<System::Windows::Forms::Label^>  ^LabelArr;



		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->enterTimetableButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->fridayLabel = (gcnew System::Windows::Forms::Label());
			this->thursdayLabel = (gcnew System::Windows::Forms::Label());
			this->wednesdayLabel = (gcnew System::Windows::Forms::Label());
			this->tuesdayLabel = (gcnew System::Windows::Forms::Label());
			this->MondayLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->twolabel = (gcnew System::Windows::Forms::Label());
			this->onelabel = (gcnew System::Windows::Forms::Label());
			this->elevenLabel = (gcnew System::Windows::Forms::Label());
			this->tenLabel = (gcnew System::Windows::Forms::Label());
			this->nineLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->statsButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(32, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(261, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Insert the Class Timetable you want to view";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(82, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(136, 20);
			this->textBox1->TabIndex = 1;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(103, 130);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(905, 646);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// enterTimetableButton
			// 
			this->enterTimetableButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->enterTimetableButton->Location = System::Drawing::Point(250, 36);
			this->enterTimetableButton->Name = L"enterTimetableButton";
			this->enterTimetableButton->Size = System::Drawing::Size(95, 31);
			this->enterTimetableButton->TabIndex = 3;
			this->enterTimetableButton->Text = L"Enter";
			this->enterTimetableButton->UseVisualStyleBackColor = true;
			this->enterTimetableButton->Click += gcnew System::EventHandler(this, &TimetableViewer::enterTimetableButton_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 5;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->fridayLabel, 4, 0);
			this->tableLayoutPanel2->Controls->Add(this->thursdayLabel, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->wednesdayLabel, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->tuesdayLabel, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->MondayLabel, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(103, 73);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(905, 57);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// fridayLabel
			// 
			this->fridayLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->fridayLabel->AutoSize = true;
			this->fridayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fridayLabel->Location = System::Drawing::Point(779, 16);
			this->fridayLabel->Name = L"fridayLabel";
			this->fridayLabel->Size = System::Drawing::Size(66, 25);
			this->fridayLabel->TabIndex = 4;
			this->fridayLabel->Text = L"Friday";
			// 
			// thursdayLabel
			// 
			this->thursdayLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->thursdayLabel->AutoSize = true;
			this->thursdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->thursdayLabel->Location = System::Drawing::Point(583, 16);
			this->thursdayLabel->Name = L"thursdayLabel";
			this->thursdayLabel->Size = System::Drawing::Size(95, 25);
			this->thursdayLabel->TabIndex = 3;
			this->thursdayLabel->Text = L"Thursday";
			// 
			// wednesdayLabel
			// 
			this->wednesdayLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->wednesdayLabel->AutoSize = true;
			this->wednesdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wednesdayLabel->Location = System::Drawing::Point(391, 16);
			this->wednesdayLabel->Name = L"wednesdayLabel";
			this->wednesdayLabel->Size = System::Drawing::Size(118, 25);
			this->wednesdayLabel->TabIndex = 2;
			this->wednesdayLabel->Text = L"Wednesday";
			// 
			// tuesdayLabel
			// 
			this->tuesdayLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tuesdayLabel->AutoSize = true;
			this->tuesdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tuesdayLabel->Location = System::Drawing::Point(226, 16);
			this->tuesdayLabel->Name = L"tuesdayLabel";
			this->tuesdayLabel->Size = System::Drawing::Size(89, 25);
			this->tuesdayLabel->TabIndex = 1;
			this->tuesdayLabel->Text = L"Tuesday";
			// 
			// MondayLabel
			// 
			this->MondayLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->MondayLabel->AutoSize = true;
			this->MondayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MondayLabel->Location = System::Drawing::Point(49, 16);
			this->MondayLabel->Name = L"MondayLabel";
			this->MondayLabel->Size = System::Drawing::Size(83, 25);
			this->MondayLabel->TabIndex = 0;
			this->MondayLabel->Text = L"Monday";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->tableLayoutPanel3->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 6);
			this->tableLayoutPanel3->Controls->Add(this->twolabel, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->onelabel, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->elevenLabel, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->tenLabel, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->nineLabel, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 5);
			this->tableLayoutPanel3->Location = System::Drawing::Point(2, 130);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 7;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(104, 646);
			this->tableLayoutPanel3->TabIndex = 5;
			this->tableLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TimetableViewer::tableLayoutPanel3_Paint);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 572);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"2:30pm";
			// 
			// twolabel
			// 
			this->twolabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->twolabel->AutoSize = true;
			this->twolabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->twolabel->Location = System::Drawing::Point(7, 381);
			this->twolabel->Name = L"twolabel";
			this->twolabel->Size = System::Drawing::Size(89, 25);
			this->twolabel->TabIndex = 5;
			this->twolabel->Text = L"12:30pm";
			// 
			// onelabel
			// 
			this->onelabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->onelabel->AutoSize = true;
			this->onelabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->onelabel->Location = System::Drawing::Point(7, 307);
			this->onelabel->Name = L"onelabel";
			this->onelabel->Size = System::Drawing::Size(89, 25);
			this->onelabel->TabIndex = 4;
			this->onelabel->Text = L"11:30am";
			// 
			// elevenLabel
			// 
			this->elevenLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->elevenLabel->AutoSize = true;
			this->elevenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->elevenLabel->Location = System::Drawing::Point(21, 234);
			this->elevenLabel->Name = L"elevenLabel";
			this->elevenLabel->Size = System::Drawing::Size(61, 25);
			this->elevenLabel->TabIndex = 3;
			this->elevenLabel->Text = L"11am";
			// 
			// tenLabel
			// 
			this->tenLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tenLabel->AutoSize = true;
			this->tenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tenLabel->Location = System::Drawing::Point(21, 160);
			this->tenLabel->Name = L"tenLabel";
			this->tenLabel->Size = System::Drawing::Size(61, 25);
			this->tenLabel->TabIndex = 2;
			this->tenLabel->Text = L"10am";
			// 
			// nineLabel
			// 
			this->nineLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nineLabel->AutoSize = true;
			this->nineLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nineLabel->Location = System::Drawing::Point(27, 45);
			this->nineLabel->Name = L"nineLabel";
			this->nineLabel->Size = System::Drawing::Size(50, 25);
			this->nineLabel->TabIndex = 1;
			this->nineLabel->Text = L"9am";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 454);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"1:30pm";
			// 
			// statsButton
			// 
			this->statsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->statsButton->Location = System::Drawing::Point(887, 22);
			this->statsButton->Name = L"statsButton";
			this->statsButton->Size = System::Drawing::Size(95, 31);
			this->statsButton->TabIndex = 7;
			this->statsButton->Text = L"Statistics";
			this->statsButton->UseVisualStyleBackColor = true;
			this->statsButton->Click += gcnew System::EventHandler(this, &TimetableViewer::statsButton_Click);
			// 
			// TimetableViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1020, 788);
			this->Controls->Add(this->statsButton);
			this->Controls->Add(this->tableLayoutPanel3);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->enterTimetableButton);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"TimetableViewer";
			this->Text = L"TimetableViewer";
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//make an array of labels
		void InitializeComponent1(void)
		{
			//create the label array
			this->LabelArr = gcnew array<System::Windows::Forms::Label^>(35);
			int i = 0;
			while ( i < 35)
			{
				this->LabelArr[i] = (gcnew System::Windows::Forms::Label());
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 7; y++) {
						this->LabelArr[i] = (gcnew System::Windows::Forms::Label());
						this->tableLayoutPanel1->Controls->Add(this->LabelArr[i], x, y);
						this->LabelArr[i]->AutoSize = true;
						this->LabelArr[i]->Location = System::Drawing::Point(3, 0);
						this->LabelArr[i]->Size = System::Drawing::Size(35, 13);
						this->LabelArr[i]->TabIndex = 0;
						this->LabelArr[i]->Text = L"Blank Period";
						this->LabelArr[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						this->LabelArr[i]->Anchor = System::Windows::Forms::AnchorStyles::None;
						i++;

					}
				}
			}

		}
	private: System::Void enterTimetableButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ temp;
		temp = System::Convert::ToString(textBox1->Text);	//gets the text from the textbox saves it to temp
		std::string groupName = msclr::interop::marshal_as< std::string >(temp); // converts from a String^ to a std::string
		Timetable currentTimetable;
		for (std::vector<Timetable>::const_iterator iter = timetables.begin(); iter != timetables.end(); ++iter) {			//iterate through Timetables vector
			Timetable timetableCheck = *iter;
			if (groupName == timetableCheck.getGroup()) {
				currentTimetable = *iter;
			}
		}
		this->label1->Text = L"Type the Class\'s Timetable you want to view";
		std::vector<std::string> checkEmpty = currentTimetable.getPeriods();
		if (checkEmpty.empty())
			this->label1->Text = L"Invalid Class Name try again";
		else {
			int periodCountWithBreaks = 0;			//period count with breaks included so 0-34
			int periodCount = 0;					//period count of subjects so 0-24
			while ( periodCount < 25) {
				for (int periodDayCount = 0; periodDayCount < 7; periodDayCount++) {
					if (periodDayCount == 2) {
						this->LabelArr[periodCountWithBreaks]->Text = "Break";
					}
					else if (periodDayCount == 4) {
						this->LabelArr[periodCountWithBreaks]->Text = "Lunch";
					}
					else {
						std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
						std::string currentTeacher = periods[(periodCount * 3 + 1)];		//get current teacher for that period
						std::string currentRoom = periods[(periodCount * 3 + 2)];		//get current room for that period
						std::string subject = periods[periodCount * 3];			//get current subject
						String^ str = msclr::interop::marshal_as< String^ >(subject);
						String^ str2 = msclr::interop::marshal_as< String^ >(currentTeacher);
						String^ str3 = msclr::interop::marshal_as< String^ >(currentRoom);
						if (subject == "Free")
							this->LabelArr[periodCountWithBreaks]->Text = str;
						else
							this->LabelArr[periodCountWithBreaks]->Text = str + "\n" + str2 + "\n" + str3;
						periodCount++;
					}
					periodCountWithBreaks++;
				}
			}
		}
	}
private: System::Void tableLayoutPanel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
	private: System::Void statsButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Stats ^ form = gcnew Stats;
		form->ShowDialog();
	}
};
}
