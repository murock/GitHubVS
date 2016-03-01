#pragma once

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
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 81);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(996, 646);
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

		//added code to make an array of labels CURRENTLY USELESS need to load this form to test it
		void InitializeComponent1(void)
		{

			this->LabelArr = gcnew array<System::Windows::Forms::Label^>(25);
			/*	this->LabelArr[0] = (gcnew System::Windows::Forms::Label());
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

			this->tableLayoutPanel1->Controls->Add(this->LabelArr[1], 0, 1); // x then y

			this->LabelArr[1]->AutoSize = true;
			this->LabelArr[1]->Location = System::Drawing::Point(3, 0);
			this->LabelArr[1]->Name = L"label2";
			this->LabelArr[1]->Size = System::Drawing::Size(35, 13);
			this->LabelArr[1]->TabIndex = 0;
			this->LabelArr[1]->Text = L"label2"; */
			int i = 0;
			while ( i < 25)
			{
				this->LabelArr[i] = (gcnew System::Windows::Forms::Label());
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						this->LabelArr[i] = (gcnew System::Windows::Forms::Label());

						this->tableLayoutPanel1->Controls->Add(this->LabelArr[i], x, y);

						this->LabelArr[i]->AutoSize = true;
						this->LabelArr[i]->Location = System::Drawing::Point(3, 0);
					//	this->LabelArr[i]->Name = L"label" + i;
						this->LabelArr[i]->Size = System::Drawing::Size(35, 13);
						this->LabelArr[i]->TabIndex = 0;
						this->LabelArr[i]->Text = L"label";
						i++;

					}
				}
			}

		}
	};
}
