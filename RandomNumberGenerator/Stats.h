#pragma once
#include <fstream>	//for reading in files
#include <iostream>
#include <string>
#include <sstream>
namespace TimetableGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Stats
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Stats(void)
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
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  loadChartButton;
	private: System::Windows::Forms::Button^  loadChartButton2;
	private: System::Windows::Forms::Label^  graphTitle;
	private: System::Windows::Forms::Label^  xAxisLabel;
	private: System::Windows::Forms::Label^  label1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->loadChartButton = (gcnew System::Windows::Forms::Button());
			this->loadChartButton2 = (gcnew System::Windows::Forms::Button());
			this->graphTitle = (gcnew System::Windows::Forms::Label());
			this->xAxisLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(45, 35);
			this->chart1->Name = L"chart1";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"Fitness";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(561, 358);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// loadChartButton
			// 
			this->loadChartButton->Location = System::Drawing::Point(112, 416);
			this->loadChartButton->Name = L"loadChartButton";
			this->loadChartButton->Size = System::Drawing::Size(100, 42);
			this->loadChartButton->TabIndex = 1;
			this->loadChartButton->Text = L"Load Individual Chart";
			this->loadChartButton->UseVisualStyleBackColor = true;
			this->loadChartButton->Click += gcnew System::EventHandler(this, &Stats::loadChartButton_Click);
			// 
			// loadChartButton2
			// 
			this->loadChartButton2->Location = System::Drawing::Point(385, 416);
			this->loadChartButton2->Name = L"loadChartButton2";
			this->loadChartButton2->Size = System::Drawing::Size(104, 42);
			this->loadChartButton2->TabIndex = 2;
			this->loadChartButton2->Text = L"Load Total Population Chart";
			this->loadChartButton2->UseVisualStyleBackColor = true;
			this->loadChartButton2->Click += gcnew System::EventHandler(this, &Stats::loadChartButton2_Click);
			// 
			// graphTitle
			// 
			this->graphTitle->AutoSize = true;
			this->graphTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graphTitle->Location = System::Drawing::Point(107, 9);
			this->graphTitle->Name = L"graphTitle";
			this->graphTitle->Size = System::Drawing::Size(82, 25);
			this->graphTitle->TabIndex = 3;
			this->graphTitle->Text = L"Fitness";
			// 
			// xAxisLabel
			// 
			this->xAxisLabel->AutoSize = true;
			this->xAxisLabel->BackColor = System::Drawing::SystemColors::Window;
			this->xAxisLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->xAxisLabel->Location = System::Drawing::Point(262, 378);
			this->xAxisLabel->Name = L"xAxisLabel";
			this->xAxisLabel->Size = System::Drawing::Size(85, 15);
			this->xAxisLabel->TabIndex = 4;
			this->xAxisLabel->Text = L"Generations";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Window;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(52, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Score";
			// 
			// Stats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 542);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->xAxisLabel);
			this->Controls->Add(this->graphTitle);
			this->Controls->Add(this->loadChartButton2);
			this->Controls->Add(this->loadChartButton);
			this->Controls->Add(this->chart1);
			this->Name = L"Stats";
			this->Text = L"Stats";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadChartButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->graphTitle->Text = L"Fitness of Best Individual";
		this->chart1->Series["Fitness"]->Points->Clear();
		std::ifstream infile("bestscores.txt");
		std::string line;
		for (int i = 0; infile; i++)
		{
			while (getline(infile,line))
			{
				int tempNum;
				std::istringstream convert(line);
				convert >> tempNum;		//make the string an int
				this->chart1->Series["Fitness"]->Points->AddXY(i, tempNum);
			}
		}
	}
	private: System::Void loadChartButton2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->graphTitle->Text = L"Fitness of Population";
		this->chart1->Series["Fitness"]->Points->Clear();
		std::ifstream infile("totalscores.txt");
		std::string line;
		for (int i = 0; infile; i++)
		{
			while (getline(infile, line))
			{
				int tempNum;
				std::istringstream convert(line);
				convert >> tempNum;		//make the string an int
				this->chart1->Series["Fitness"]->Points->AddXY(i, tempNum);
			}
		}
	}
};
}
