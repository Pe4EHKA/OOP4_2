#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class MyModel {
private:
	int value;
	int A;
	int B;
	int C;
public:

	System::EventHandler^ observers;

	MyModel() : A(50), B(50), C(50) {}

	int getA() {
		return A;
	}
	
	int getB() {
		return B;
	}

	int getC() {
		return C;
	}

	void setA(int newA) {  // Разрешающее поведение
		if (newA > 100) {
			return;
		}
		if (newA < 0) {
			return;
		}
		A = newA;
		if (newA > B) {
			setB(newA);
		}
		if (newA > C) {
			setC(newA);
		}
		observers->Invoke(this, EventArgs::Empty);
	}

	void setB(int newB) {  // Запрещающее поведение
		if (newB < A) {
			// Если новое значение меньше A, откатываем изменение
			return;
		}
		if (newB > C) {
			// Если новое значение больше C, откатываем изменение
			return;
		}
		B = newB;
		observers->Invoke(this, EventArgs::Empty);
	}

	void setC(int newC) {  // Разрешающее поведение
		if (newC > 100) {
			return;
		}
		if (newC < 0) {
			return;
		}
		C = newC;
		if (B > newC) {
			setB(newC);
		}
		if (A > newC) {
			setA(newC);
		}
		observers->Invoke(this, EventArgs::Empty);
	}

	~MyModel() {}

	void setValue(int value) {
		this->value = value;
	}

	int getValue() {
		return value;
	}
};