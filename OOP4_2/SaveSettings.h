#pragma once
using namespace System::Configuration;

ref class MyAppSettings : public ApplicationSettingsBase {
public:
	property int A {
		int get() {
			return (int)this["A"];
		}
		void set(int value) {
			this["A"] = value;
		}
	}
	property int B {
		int get() {
			return (int)this["B"];
		}
		void set(int value) {
			this["B"] = value;
		}
	}
	property int C {
		int get() {
			return (int)this["C"];
		}
		void set(int value) {
			this["C"] = value;
		}
	}


private:

};