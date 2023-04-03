#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class MyModel {
private:
	int A;
	int B;
	int C;
public:

	System::EventHandler^ observers;

	MyModel() : A(0), B(0), C(0) {}

	int getA() {
		return A;
	}
	
	int getB() {
		return B;
	}

	int getC() {
		return C;
	}

	void hardsetA(int newA) {
		A = newA;
	}

	void hardsetB(int newB) {
		B = newB;
	}

	void hardsetC(int newC) {
		C = newC;
	}

	void setA(int newA) {  // Разрешающее поведение
		observers->Invoke(this, EventArgs::Empty);
		if (newA > 100) {
			return;
		}
		if (newA < 0) {
			return;
		}
		if (newA > B) {
			setB(newA);
		}
		if (newA > C) {
			setC(newA);
		}
		A = newA;
		observers->Invoke(this, EventArgs::Empty);
	}

	void setB(int newB) {  // Запрещающее поведение
		observers->Invoke(this, EventArgs::Empty);
		if (newB > 100) {
			return;
		}
		if (newB < 0) {
			return;
		}
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
		observers->Invoke(this, EventArgs::Empty);
		if (newC > 100) {
			return;
		}
		if (newC < 0) {
			return;
		}
		if (B > newC) {
			setB(newC);
		}
		if (A > newC) {
			setA(newC);
		}
		C = newC;
		observers->Invoke(this, EventArgs::Empty);
	}
	~MyModel() {}
};