#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OOP42::MyForm form; // OOP42 имя проекта
	Application::Run(% form);
	return 0;
}



System::Void OOP42::MyForm::UpdateFromModel(System::Object^ sender, System::EventArgs^ e)
{
	textBoxA->Text = model->getA().ToString();
	textBoxB->Text = model->getB().ToString();
	textBoxC->Text = model->getC().ToString();

	numericUpDownA->Value = Convert::ToDecimal(model->getA());
	numericUpDownC->Value = Convert::ToDecimal(model->getC());
	numericUpDownB->Value = Convert::ToDecimal(model->getB());
	numericUpDownB->Maximum = model->getC();
	numericUpDownB->Minimum = model->getA();

	trackBarA->Value = model->getA();
	trackBarB->Value = model->getB();
	trackBarC->Value = model->getC();
	return System::Void();
}

System::Void OOP42::MyForm::LoadSettings() {

	configFile = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	auto appSettings = ConfigurationManager::AppSettings;
	if (IsSettingSet()) {
		model = gcnew MyModel(Int32::Parse(appSettings[L"A"]->ToString()), Int32::Parse(appSettings[L"B"]->ToString()), Int32::Parse(appSettings[L"C"]->ToString()));
		model->observers += gcnew EventHandler(this, &MyForm::UpdateFromModel);
	}
	else {
		model = gcnew MyModel();
		model->observers += gcnew EventHandler(this, &MyForm::UpdateFromModel);
	}
	model->observers->Invoke(this, EventArgs::Empty);
	return System::Void();
}

System::Void OOP42::MyForm::SaveSettings()
{
	auto settings = configFile->AppSettings->Settings;
	if (IsSettingSet()) {
		settings[L"A"]->Value = model->getA().ToString();
		settings[L"B"]->Value = model->getB().ToString();
		settings[L"C"]->Value = model->getC().ToString();
	}
	else {
		settings->Add(L"A", model->getA().ToString());
		settings->Add(L"B", model->getB().ToString());
		settings->Add(L"C", model->getC().ToString());
	}
	configFile->Save(ConfigurationSaveMode::Modified);
	ConfigurationManager::RefreshSection(configFile->AppSettings->SectionInformation->Name);
	return System::Void();
}

System::Boolean OOP42::MyForm::IsSettingSet()
{
	auto appSettings = ConfigurationManager::AppSettings;
	return appSettings[L"A"] != nullptr && appSettings[L"B"] != nullptr && appSettings[L"C"] != nullptr;
}

System::Void OOP42::MyForm::textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		int value;
		TextBox^ box = dynamic_cast<TextBox^>(sender);
		Boolean number = Int32::TryParse(box->Text, value);
		if (number) {
			if (box->Name == textBoxA->Name) {
				model->setA(value);
			}
			else if (box->Name == textBoxB->Name) {
				model->setB(value);
			}
			else if (box->Name == textBoxC->Name) {
				model->setC(value);
			}
		}
	}
	else if (e->KeyCode == Keys::Escape) {
		model->observers->Invoke(this, EventArgs::Empty);
	}
	return System::Void();
}

System::Void OOP42::MyForm::textBox_LeaveFocus(System::Object^ sender, System::EventArgs^ e)
{
	int value;
	TextBox^ box = dynamic_cast<TextBox^>(sender);
	Boolean number = Int32::TryParse(box->Text, value);
	if (number) {
		if (box->Name == textBoxA->Name) {
			model->setA(value);
		}
		else if (box->Name == textBoxB->Name) {
			model->setB(value);
		}
		else if (box->Name == textBoxC->Name) {
			model->setC(value);
		}
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDown_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		NumericUpDown^ box = dynamic_cast<NumericUpDown^>(sender);
		int value = Decimal::ToInt32(box->Value);
		if (box->Name == numericUpDownA->Name) {
			model->setA(value);
		}
		else if (box->Name == numericUpDownB->Name) {
			model->setB(value);
		}
		else if (box->Name == numericUpDownC->Name) {
			model->setC(value);
		}
	}
	else if (e->KeyCode == Keys::Escape) {
		model->observers->Invoke(this, EventArgs::Empty);
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDown_ChangedValue(System::Object^ sender, System::EventArgs^ e)
{
	NumericUpDown^ box = dynamic_cast<NumericUpDown^>(sender);
	int value = Decimal::ToInt32(box->Value);
	if (box->Name == numericUpDownA->Name) {
		model->setA(value);
	}
	else if (box->Name == numericUpDownB->Name) {
		model->setB(value);
	}
	else if (box->Name == numericUpDownC->Name) {
		model->setC(value);
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDown_LeaveFocus(System::Object^ sender, System::EventArgs^ e)
{
	NumericUpDown^ box = dynamic_cast<NumericUpDown^>(sender);
	int value = Decimal::ToInt32(box->Value);
	if (box->Name == numericUpDownA->Name) {
		model->setA(value);
	}
	else if (box->Name == numericUpDownB->Name) {
		model->setB(value);
	}
	else if (box->Name == numericUpDownC->Name) {
		model->setC(value);
	}
	return System::Void();
}

System::Void OOP42::MyForm::trackBar_Scrolling(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ box = dynamic_cast<TrackBar^>(sender);
	int value = box->Value;
	if (box->Name == trackBarA->Name) {
		model->setA(value);
	}
	else if (box->Name == trackBarB->Name) {
		model->setB(value);
	}
	else if (box->Name == trackBarC->Name) {
		model->setC(value);
	}
	return System::Void();
}

