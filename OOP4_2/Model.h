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

	MyModel(int newA, int newB, int newC) : A(newA), B(newB), C(newC) {}

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
		if (A == newA) {
			return;
		}
		if (newA > 100) {
			newA = 100;
		}
		if (newA < 0) {
			newA = 0;
		}
		if (newA > C) {
			B = newA;
			C = newA;
		}
		else if (newA > B) {
			B = A;
		}
		A = newA;
		observers->Invoke(this, EventArgs::Empty);
		return;
	}

	void setB(int newB) {  // Запрещающее поведение
		if (B == newB) {
			return;
		}
		if (newB > 100) {
			newB = 100;
		}
		if (newB < 0) {
			newB = 0;
		}
		if (newB >= A && newB <= C) {
			B = newB;
		}
		observers->Invoke(this, EventArgs::Empty);
		return;
	}

	void setC(int newC) {  // Разрешающее поведение
		if (C == newC) {
			return;
		}
		if (newC > 100) {
			newC = 100;
		}
		if (newC < 0) {
			newC = 0;
		}
		if (B > newC) {
			B = newC;
		}
		if (A > newC) {
			A = newC;
			B = newC;
		}
		C = newC;
		observers->Invoke(this, EventArgs::Empty);
		return;
	}
	~MyModel() {}
};