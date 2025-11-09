// Rational.h
// Class header for Challenge 5, Programming Fundamentals 2
// Author: Josue Aranday
// 10/27/2023
// Creates fractions and saves them in reduced form
// Member functions defined in Rational.cpp

#include <string>

// Prevents multiple inclusions of header
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational() : numerator(0), denominator(1) {};
	void setReduced(int, int);
	std::string toString() const;
	std::string toString2() const;
	void whenAdding(int, int, int, int, int*, int*);
	void whenSubstracting(int, int, int, int, int*, int*);
	void whenMultiplying(int, int, int, int, int*, int*);
	void whenDividing(int, int, int, int, int*, int*);
	int getNumerator() const;
	int getDenominator() const;
	int getWholeNum() const;
	double toDecimal() const;
	~Rational();

private:
	int numerator{ 0 };
	int denominator{ 1 };
	int wholeNum{ 0 };
};
#endif 
