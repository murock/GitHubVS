#pragma once

namespace RandomNumberGenerator {

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
		array<System::Windows::Forms::Label^>  ^LabelArr;



		void InitializeComponent1(void)
		{

			this->LabelArr = gcnew array<System::Windows::Forms::Label^>(3);
			this->LabelArr[0] = (gcnew System::Windows::Forms::Label());
			this->LabelArr[1] = (gcnew System::Windows::Forms::Label());
			this->LabelArr[2] = (gcnew System::Windows::Forms::Label());

			this->tableLayoutPanel1->Controls->Add(this->LabelArr[0], 0, 0);
			// 
			// LabelArr 
			// 
			this->LabelArr[0]->AutoSize = true;
			this->LabelArr[0]->Location = System::Drawing::Point(3, 0);
			this->LabelArr[0]->Name = L"label1";
			this->LabelArr[0]->Size = System::Drawing::Size(35, 13);
			this->LabelArr[0]->TabIndex = 0;
			this->LabelArr[0]->Text = L"label1";

		}
		


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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(216, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Type the Class\'s Timetable you want to view";
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
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				86)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(184, 198);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 51)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(272, 152);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// TimetableViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1020, 788);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"TimetableViewer";
			this->Text = L"TimetableViewer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
