// Operations with rational objects
// Tester Code for Challenge 5, Programming Fundamentals 2
// Author: Josue Aranday
// 10/27/2023
// Tests the different operations for Rational.h and Rational.cpp
#include <iostream>
#include <stdexcept>
#include "Rational.h"
using namespace std;

void displayRational(const string&, const Rational&);

int main() {
	int d1{ 0 };
	int n1{ 0 };
	int d2{ 0 };
	int n2{ 0 };
	int menuChoice{ 0 };

	cout << "Type Numerator #1: " << endl;
	cin >> n1;
	cout << "\nType Denominator #1 (cannot be 0): " << endl;
	cin >> d1;
	Rational r1;
	r1.Rational::setReduced(n1, d1);
	
	cout << endl;
	displayRational("Fraction #1: ", r1);
	cout << endl;
	
	cout << "Type Numerator #2: " << endl;
	cin >> n2;
	cout << "\nType Denominator #2 (cannot be 0): " << endl;
	cin >> d2;

	Rational r2;
	r2.Rational::setReduced(n2, d2);

	cout << endl;
	displayRational("Fraction #2: ", r2);
	cout << endl;

	// Update numbers and get wholes
	int w1 = r1.Rational::getWholeNum();
	n1 = r1.Rational::getNumerator();
	
	int w2 = r2.Rational::getWholeNum();
	n2 = r2.Rational::getNumerator();

	d1 = r1.Rational::getDenominator();
	d2 = r2.Rational::getDenominator();

	n1 = n1 + (w1 * d1);
	n2 = n2 + (w2 * d2);

	int n3{ 0 };
	int* n3ptr = &n3;
	int d3{ 0 };
	int* d3ptr = &d3;
	

	do {
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
		cout << "Operations available:\n" << endl;
		cout << "   1) Add both fractions" << endl;
		cout << "      " << r1.toString2() << " + " << r2.toString2() << endl;
		cout << "   2) Substract fraction #2 to fraction #1" << endl;
		cout << "      " << r1.toString2() << " - " << r2.toString2() << endl;
		cout << "   3) Substract fraction #1 to fraction #2" << endl;
		cout << "      " << r2.toString2() << " - " << r1.toString2() << endl;
		cout << "   4) Multiply both fractions" << endl;
		cout << "      " << r1.toString2() << " X " << r2.toString2() << endl;
		cout << "   5) Divide fraction #2 to fraction #1" << endl;
		cout << "      " << r1.toString2() << " / " << r2.toString2() << endl;
		cout << "   6) Divide fraction #1 to fraction #2" << endl;
		cout << "      " << r2.toString2() << " / " << r1.toString2() << endl;
		cout << "   7) Exit the program" << endl;
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		Rational r3;

		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "The Sum of both fractions is: " << endl;
			r1.Rational::whenAdding(n1, n2, d1, d2, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 2:
			cout << "The Diference fraction #1 to franction #2 is: " << endl;
			r1.Rational::whenSubstracting(n1, n2, d1, d2, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 3:
			cout << "The Diference fraction #2 to franction #1 is: " << endl;
			r1.Rational::whenSubstracting(n2, n1, d2, d1, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 4:
			cout << "The Product of both fractions is: " << endl;
			r1.Rational::whenMultiplying(n1, n2, d1, d2, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 5:
			cout << "The Quotient of fraction #1 divided by franction #2 is: " << endl;
			r1.Rational::whenDividing(n1, n2, d1, d2, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 6:
			cout << "The Quotient of fraction #2 divided by franction #1 is: " << endl;
			r1.Rational::whenDividing(n2, n1, d2, d1, n3ptr, d3ptr);
			r3.Rational::setReduced(n3, d3);
			displayRational("", r3);
			cout << endl;
			r3.Rational::~Rational();
			break;
		case 7:
			cout << "Thank you for testing... Goodbye!" << endl;

			break;
		default:
			cout << "That is not a valid option. Try again." << endl;
		}

	} while (menuChoice != 7);


	system("pause");
	return 0;
}

void displayRational(const string& message, const Rational& rational) {
	cout << message << "\n" << rational.toString() << endl;
	cout << "Decimal form  = " << rational.toDecimal() << endl;
}