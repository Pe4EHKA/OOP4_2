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

System::Void OOP42::MyForm::textBoxA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter) {
		model->setA(Int32::Parse(textBoxA->Text));
	}
	return System::Void();
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
		model->setA(Int32::Parse(appSettings[L"A"]->ToString()));
		model->setB(Int32::Parse(appSettings[L"B"]->ToString()));
		model->setC(Int32::Parse(appSettings[L"C"]->ToString()));
	}
	
	/*String^ configFilePath = "app.config";
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(configFilePath);
	if (config->HasFile) {
		AppSettingsSection^ appSettings = config->AppSettings;
		if (appSettings != nullptr) {
			model->setA(Int32::Parse(appSettings->Settings["A"]->Value));
			model->setB(Int32::Parse(appSettings->Settings["B"]->Value));
			model->setC(Int32::Parse(appSettings->Settings["C"]->Value));

		}
	}
	else {
		MessageBox::Show("ERROR");
	}*/
	/*MyAppSettings^ appSettings = gcnew MyAppSettings();
	textBoxA->Text = appSettings->A.ToString();
	numericUpDownA->Value = appSettings->A;
	trackBarA->Value = appSettings->A;

	textBoxB->Text = appSettings->B.ToString();
	numericUpDownB->Value = appSettings->B;
	trackBarB->Value = appSettings->B;

	textBoxC->Text = appSettings->C.ToString();
	numericUpDownC->Value = appSettings->C;
	trackBarC->Value = appSettings->C;*/
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
	/*String^ configFilePath = "app.config";
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(configFilePath);
	if (config->HasFile) {

		AppSettingsSection^ appSettings = config->AppSettings;
		if (appSettings != nullptr) {
			appSettings->Settings["A"]->Value = model->getA().ToString();
			appSettings->Settings["B"]->Value = model->getB().ToString();
			appSettings->Settings["C"]->Value = model->getC().ToString();
			config->Save(ConfigurationSaveMode::Modified);
		}

	}*/
	/*
	// Получаем путь к файлу конфигурации
	String^ configFilePath = AppDomain::CurrentDomain->SetupInformation->ConfigurationFile;

	// Создаем объект конфигурации
	auto config = ConfigurationManager::OpenExeConfiguration(configFilePath);

	// Получаем секцию настроек
	ClientSettingsSection^ settings = safe_cast<ClientSettingsSection^>(config->GetSection("applicationSettings/MyNamespace.Properties.Settings"));

	MyAppSettings^ appSettings = gcnew MyAppSettings();
	appSettings->A = int::Parse(textBoxA->ToString());
	appSettings->B = (int)numericUpDownB->Value;
	appSettings->C = trackBarC->Value;
	appSettings->Save();*/
	return System::Void();
}

System::Boolean OOP42::MyForm::IsSettingSet()
{
	auto appSettings = ConfigurationManager::AppSettings;
	return appSettings[L"A"] != nullptr && appSettings[L"B"] != nullptr && appSettings[L"C"] != nullptr;
	//return System::Boolean();
}
