// Rational.cpp
// Class Member Functions for Challenge 5, Programming Fundamentals 2
// Author: Josue Aranday
// 10/27/2023
// Reduces the fractions and performs operations with them
// Member functions for Rational.h

#include <string>
#include <sstream>
#include <stdexcept>
#include "Rational.h"		// includes the header Rational.h

using namespace std;

// Setting a reduced form of the fraction inputed
void Rational::setReduced(int num, int den) {
	if (den != 0) {
		if (num < 0 && den < 0) {
			num = num * -1;
			den = den * -1;
		}
		int lcf{ 1 };									// largest common factor
			for (int reducer = 1; reducer <= num || reducer <= den; reducer++) {		// find largest common factor
				if (num%reducer == 0 && den%reducer == 0)
					lcf = reducer;
			}
			numerator = num / lcf;
			denominator = den / lcf;
			if (numerator >= denominator) {
				wholeNum = numerator / denominator;
				numerator = numerator % denominator;
			}
	}
	else {
		throw invalid_argument("Denominator cannot be 0");
	}

}

// Display the fraction in form a/b
string Rational::toString() const {
	if (wholeNum == 0) {
		ostringstream output;
		output << "Rational Form = " << numerator << "/" << denominator;
		return output.str();
	}
	else {
		ostringstream output;
		int improper = wholeNum * denominator;
		improper += numerator;
		output << "Mixed Form    = " << wholeNum << " " << numerator << "/" << denominator
			<< "\nImproper Form = " << "  " << improper << "/" << denominator;
		return output.str();
	}
}
// To display short version between options
string Rational::toString2() const {
	if (wholeNum == 0) {
		ostringstream output;
		output << numerator << "/" << denominator;
		return output.str();
	}
	else {
		ostringstream output;
		int improper = wholeNum * denominator;
		improper += numerator;
		output << improper << "/" << denominator;
		return output.str();
	}
}

// Get num and denom to perform operations
int Rational::getNumerator() const {
	return numerator;
}
int Rational::getDenominator() const {
	return denominator;
}
int Rational::getWholeNum() const {
	return wholeNum;
}

// Add two Rational objects
void Rational::whenAdding(int addNum1, int addNum2, int addDenom1, int addDenom2, int* nPtr, int* dPtr) {
	addNum1 = addNum1 * addDenom2;
	addNum2 = addNum2 * addDenom1;
	*dPtr = addDenom1 * addDenom2;
	*nPtr = addNum1 + addNum2;
}

// Substract two Rational objects
void Rational::whenSubstracting(int subNum1, int subNum2, int subDenom1, int subDenom2, int* nPtr, int* dPtr) {
	subNum1 = subNum1 * subDenom2;
	subNum2 = subNum2 * subDenom1;
	*dPtr = subDenom1 * subDenom2;
	*nPtr = subNum1 - subNum2;
}

// Multiply two Rational objects
void Rational::whenMultiplying(int mulNum1, int mulNum2, int mulDenom1, int mulDenom2, int* nPtr, int* dPtr) {
	*nPtr = mulNum1 * mulNum2;
	*dPtr = mulDenom1 * mulDenom2;
}

// Divide two Rational objects
void Rational::whenDividing(int divNum1, int divNum2, int divDenom1, int divDenom2, int* nPtr, int* dPtr) {
	*nPtr = divNum1 * divDenom2;
	*dPtr = divDenom1 * divNum2;
}

// Convert the Fraction to Decimal
double Rational::toDecimal() const {
	double numerDec = numerator;
	double denomDec = denominator;
	double wholeDec = wholeNum;
	double decimalFinal = numerDec / denomDec;
	decimalFinal += wholeDec;
	return decimalFinal;
}

Rational::~Rational() {

}
