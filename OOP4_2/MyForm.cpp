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
	numericUpDownB->Value = Convert::ToDecimal(model->getB());
	numericUpDownC->Value = Convert::ToDecimal(model->getC());

	trackBarA->Value = model->getA();
	trackBarB->Value = model->getB();
	trackBarC->Value = model->getC();

	return System::Void();
}

System::Void OOP42::MyForm::LoadSettings() {

	configFile = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	auto appSettings = ConfigurationManager::AppSettings;
	if (IsSettingSet()) {
		model->hardsetA(Int32::Parse(appSettings[L"A"]->ToString()));
		model->hardsetB(Int32::Parse(appSettings[L"B"]->ToString()));
		model->hardsetC(Int32::Parse(appSettings[L"C"]->ToString()));
		model->observers->Invoke(this, EventArgs::Empty);
	}
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

System::Void OOP42::MyForm::textBoxA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setA(Int32::Parse(textBoxA->Text));
	}
	return System::Void();
}

System::Void OOP42::MyForm::textBoxB_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setB(Int32::Parse(textBoxB->Text));
	}
	return System::Void();
}

System::Void OOP42::MyForm::textBoxC_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setC(Int32::Parse(textBoxC->Text));
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setA(Decimal::ToInt32(numericUpDownA->Value));
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownB_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setB(Decimal::ToInt32(numericUpDownB->Value));
	}
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownC_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setC(Decimal::ToInt32(numericUpDownC->Value));
	}
	return System::Void();
}

System::Void OOP42::MyForm::trackBarA_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	model->setA(trackBarA->Value);
	return System::Void();
}

System::Void OOP42::MyForm::trackBarB_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	model->setB(trackBarB->Value);
	return System::Void();
}

System::Void OOP42::MyForm::trackBarC_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	model->setC(trackBarC->Value);

	return System::Void();
}

System::Void OOP42::MyForm::textBoxA_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setA(Int32::Parse(textBoxA->Text));
	return System::Void();
}

System::Void OOP42::MyForm::textBoxB_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setB(Int32::Parse(textBoxB->Text));
	return System::Void();
}

System::Void OOP42::MyForm::textBoxC_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setC(Int32::Parse(textBoxC->Text));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownA_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	model->setA(Decimal::ToInt32(numericUpDownA->Value));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownB_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	model->setB(Decimal::ToInt32(numericUpDownB->Value));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownC_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	model->setC(Decimal::ToInt32(numericUpDownC->Value));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownA_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setA(Decimal::ToInt32(numericUpDownA->Value));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownB_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setB(Decimal::ToInt32(numericUpDownB->Value));
	return System::Void();
}

System::Void OOP42::MyForm::numericUpDownC_Leave(System::Object^ sender, System::EventArgs^ e)
{
	model->setC(Decimal::ToInt32(numericUpDownC->Value));
	return System::Void();
}
