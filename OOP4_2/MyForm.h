#pragma once
#include "Model.h"
#include "SaveSettings.h"
#using <System.Configuration.dll>

namespace OOP42 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Configuration;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			model = gcnew MyModel();
			model->observers += gcnew EventHandler(this, &MyForm::UpdateFromModel);
			model->observers->Invoke(this, EventArgs::Empty);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
		MyModel^ model;
		System::Configuration::Configuration^ configFile;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;
	private: System::Windows::Forms::TextBox^ textBoxC;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownA;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownB;	
	private: System::Windows::Forms::NumericUpDown^ numericUpDownC;
	private: System::Windows::Forms::TrackBar^ trackBarA;
	private: System::Windows::Forms::TrackBar^ trackBarB;
	private: System::Windows::Forms::TrackBar^ trackBarC;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->textBoxC = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDownA = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownB = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownC = (gcnew System::Windows::Forms::NumericUpDown());
			this->trackBarA = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarB = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarC = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarC))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(304, 225);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 109);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(480, 225);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 109);
			this->label2->TabIndex = 1;
			this->label2->Text = L"<=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(687, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 109);
			this->label3->TabIndex = 2;
			this->label3->Text = L"B";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(856, 225);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 109);
			this->label4->TabIndex = 3;
			this->label4->Text = L"<=";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1048, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 109);
			this->label5->TabIndex = 4;
			this->label5->Text = L"C";
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(268, 377);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(200, 31);
			this->textBoxA->TabIndex = 5;
			this->textBoxA->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBoxA_KeyDown);
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(632, 377);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(200, 31);
			this->textBoxB->TabIndex = 6;
			// 
			// textBoxC
			// 
			this->textBoxC->Location = System::Drawing::Point(1008, 377);
			this->textBoxC->Name = L"textBoxC";
			this->textBoxC->Size = System::Drawing::Size(200, 31);
			this->textBoxC->TabIndex = 7;
			// 
			// numericUpDownA
			// 
			this->numericUpDownA->Location = System::Drawing::Point(268, 457);
			this->numericUpDownA->Name = L"numericUpDownA";
			this->numericUpDownA->Size = System::Drawing::Size(200, 31);
			this->numericUpDownA->TabIndex = 8;
			// 
			// numericUpDownB
			// 
			this->numericUpDownB->Location = System::Drawing::Point(632, 457);
			this->numericUpDownB->Name = L"numericUpDownB";
			this->numericUpDownB->Size = System::Drawing::Size(200, 31);
			this->numericUpDownB->TabIndex = 9;
			// 
			// numericUpDownC
			// 
			this->numericUpDownC->Location = System::Drawing::Point(1008, 457);
			this->numericUpDownC->Name = L"numericUpDownC";
			this->numericUpDownC->Size = System::Drawing::Size(200, 31);
			this->numericUpDownC->TabIndex = 10;
			// 
			// trackBarA
			// 
			this->trackBarA->Location = System::Drawing::Point(268, 516);
			this->trackBarA->Maximum = 100;
			this->trackBarA->Name = L"trackBarA";
			this->trackBarA->Size = System::Drawing::Size(200, 90);
			this->trackBarA->TabIndex = 11;
			// 
			// trackBarB
			// 
			this->trackBarB->Location = System::Drawing::Point(632, 516);
			this->trackBarB->Maximum = 100;
			this->trackBarB->Name = L"trackBarB";
			this->trackBarB->Size = System::Drawing::Size(200, 90);
			this->trackBarB->TabIndex = 12;
			// 
			// trackBarC
			// 
			this->trackBarC->Location = System::Drawing::Point(1008, 516);
			this->trackBarC->Maximum = 100;
			this->trackBarC->Name = L"trackBarC";
			this->trackBarC->Size = System::Drawing::Size(200, 90);
			this->trackBarC->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1509, 636);
			this->Controls->Add(this->trackBarC);
			this->Controls->Add(this->trackBarB);
			this->Controls->Add(this->trackBarA);
			this->Controls->Add(this->numericUpDownC);
			this->Controls->Add(this->numericUpDownB);
			this->Controls->Add(this->numericUpDownA);
			this->Controls->Add(this->textBoxC);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->textBoxA);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarC))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void UpdateFromModel(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoadSettings();
	private: System::Void SaveSettings();
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadSettings();
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		SaveSettings();
	}
	private: System::Boolean IsSettingSet();
};
	
	
	
}
