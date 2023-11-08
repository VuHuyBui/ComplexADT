//========================================================
// James Bui
// Francessco Assalone
// Dipanker Thapa
// Complex.cpp
// November 2023
// This file contains the class methods for the
// Complex number class.
//========================================================

#include "Complex.h"
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

//========================================================
// setReal access method
// setReal - Set the real part of a complex number.
//
// Parameters:
// r - The real part to set.
//
// Return Value:
// None
//========================================================
void Complex::setReal(float r)
{
    a = r;
}
//========================================================
// getReal access method
// getReal - Get the real part of a complex number.
//
// Parameters:
// None
//
// Return Value:
// The real part of the complex number.
//========================================================
float Complex::getReal(void) const
{
    return a;
}
//========================================================
// setImag
// setImag - Set the imaginary part of a complex number.
//
// Parameters:
// x - The imaginary part to set.
//
// Return Value:
// None
//========================================================

void Complex::setImag(float x)
{
    a = x;
}

//========================================================
// getImag
// getImag - Get the imaginary part of a complex number.
//
// Parameters:
// None
//
// Return Value:
// The imaginary part of the complex number.
//========================================================

float Complex::getImag(void) const
{
    return a;
}

//========================================================
// assignment operator
// operator= - Assignment operator for complex numbers.
//
// Parameters:
// c - The complex number to assign.
//
// Return Value:
// The assigned complex number.
//========================================================

Complex Complex::operator=(const Complex &c)
{
    a = c.a;
    b = c.b;
    return *this;
}
//========================================================
// addition operators
// operator+ - Addition operator for complex numbers.
// Adds two complex numbers.
//
// Parameters:
// c - The complex number to add.
//
// Return Value:
// The result of the addition.
//========================================================
Complex Complex::operator+(const Complex &c) const
{
    Complex res;
    res.a = a + c.a;
    res.b = b + c.b;

    return res;
}
//========================================================
// operator+ - Addition operator for a complex number and an integer.
//
// Parameters:
// i - The integer to add.
//
// Return Value:
// The result of the addition.
//========================================================
Complex Complex::operator+(int i) const
{
    Complex res;
    res.a = a + (float)i;
    res.b = b;
    return res;
}
//========================================================
// operator+ - Addition operator for a complex number and a float.
//
// Parameters:
// f - The float to add.
//
// Return Value:
// The result of the addition.
//========================================================
Complex Complex::operator+(float f) const
{
    Complex res;
    res.a = a + f;
    res.b = b;
    return res;
}

//========================================================
// subtraction operators
//========================================================
//========================================================
// operator- - Subtraction operator for complex numbers.
// Subtracts one complex number from another.
//
// Parameters:
// c - The complex number to subtract.
//
// Return Value:
// The result of the subtraction.
//========================================================

Complex Complex::operator-(const Complex &c) const
{
    Complex res;
    res.a = a - c.a;
    res.b = b - c.b;
    return res;
}
//========================================================
// operator- - Subtraction operator for a complex number and an integer.
//
// Parameters:
// i - The integer to subtract.
//
// Return Value:
// The result of the subtraction.
//========================================================
Complex Complex::operator-(int i) const
{
    Complex res;
    res.a = a - (float)i;
    res.b = b;
    return res;
}
//========================================================
// operator- - Subtraction operator for a complex number and a float.
//
// Parameters:
// f - The float to subtract.
//
// Return Value:
// The result of the subtraction.
//========================================================
Complex Complex::operator-(float f) const
{
    Complex res;
    res.a = a - f;
    res.b = b;
    return res;
}

//========================================================
// multiplication operators
//========================================================
//========================================================
// operator* - Multiplication operator for complex numbers.
// Multiplies two complex numbers.
//
// Parameters:
// c - The complex number to multiply.
//
// Return Value:
// The result of the multiplication.
//========================================================
Complex Complex::operator*(const Complex &c) const
{
    Complex res;
    res.a = a * c.a - b * c.b;
    res.b = a * c.b + b * c.a;
    return res;
}
//========================================================
// operator* - Multiplication operator for a complex number and an integer.
//
// Parameters:
// i - The integer to multiply.
//
// Return Value:
// The result of the multiplication.
//========================================================
Complex Complex::operator*(int i) const
{
    Complex res;
    res.a = a * i;
    res.b = b * i;
    return res;
}
//========================================================
// operator* - Multiplication operator for a complex number and a float.
//
// Parameters:
// f - The float to multiply.
//
// Return Value:
// The result of the multiplication.
//========================================================
Complex Complex::operator*(float f) const
{
    Complex res;
    res.a = a * f;
    res.b = b * f;
    return res;
}

//========================================================
// division operators
//========================================================
//========================================================
// operator/ - Division operator for complex numbers.
// Divides one complex number by another.
//
// Parameters:
// c - The complex number to divide by.
//
// Return Value:
// The result of the division.
//========================================================
Complex Complex::operator/(const Complex &c) const
{
    Complex res;
    res.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
    res.b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
    return res;
}
//========================================================
// operator/ - Division operator for a complex number by an integer.
//
// Parameters:
// i - The integer to divide by.
//
// Return Value:
// The result of the division.
//========================================================
Complex Complex::operator/(int i) const
{
    Complex res;
    res.a = a / (float)i;
    res.b = b / (float)i;
    return res;
}
//========================================================
// operator/ - Division operator for a complex number by a float.
//
// Parameters:
// f - The float to divide by.
//
// Return Value:
// The result of the division.
//========================================================
Complex Complex::operator/(float f) const
{
    Complex res;
    res.a = a / f;
    res.b = b / f;
    return res;
}

//========================================================
// exponentiation
//========================================================
//========================================================
// exponentiation
// operator^ - Exponentiation operator for a complex number.
// Raises the complex number to a given integer power.
//
// Parameters:
// p - The integer exponent to raise the complex number to.
//
// Return Value:
// The result of raising the complex number to the given power.
//========================================================
Complex Complex::operator^(int p) const
{
    Complex one(1, 0);

    if (p == 0)
    {
        return one;
    }
    Complex res(a, b);
    Complex temp(a, b);
    for (int i = 0; i < p - 1; i++)
    {
        res = res * temp;
    }
    if (p < 0)
    {
        res = one / res;
    }

    return res;
}
//========================================================
// operator~
// operator~ - Conjugate operator for a complex number.
// Computes the conjugate of the complex number by negating the imaginary part.
//
// Return Value:
// The complex conjugate of the original complex number.
//========================================================
Complex Complex::operator~(void) const
{
    Complex res;
    res.a = a;
    res.b = -b;
    return res;
}

//========================================================
// abs - Calculate the absolute value (magnitude) of the complex number.
//
// Parameters:
// None
//
// Return Value:
// The absolute value (magnitude) of the complex number.
//========================================================
float Complex::abs(void) const
{
    return sqrt(a * a + b * b);
}
//========================================================
// operator== - Equality operator for complex numbers.
// Checks if two complex numbers are equal.
//
// Parameters:
// c - The complex number to compare.
//
// Return Value:
// True if the complex numbers are equal, otherwise false.
//========================================================

bool Complex::operator==(const Complex &c) const
{
    return ((a == c.a) && (b == c.b));
}

//========================================================
// operator!= - Inequality operator for complex numbers.
// Checks if two complex numbers are not equal.
//
// Parameters:
// c - The complex number to compare.
//
// Return Value:
// True if the complex numbers are not equal, otherwise false.
//========================================================

bool Complex::operator!=(const Complex &c) const
{
    return (a != c.a || b != c.b);
}

//========================================================
// operator>> - Overload >> for cin to input complex numbers.
//
// Parameters:
// is - The input stream (cin).
// c - The complex number to read from the input stream.
//
// Return Value:
// The input stream (cin) after reading the complex number.
//========================================================

istream &operator>>(istream &is, Complex &c)
{
    c.a = 0;
    c.b = 0;
    string s;
    is >> s;
    size_t i_spot = s.find('i');
    if (i_spot == string::npos)
        c.a = stof(s);
    else
    {
        size_t plus = s.substr(1, s.length() - 1).find('+');
        size_t minus = s.substr(1, s.length() - 1).find('-');
        if (plus == string::npos && minus == string::npos)
        {
            if (i_spot == 0)
                c.b = 1;
            else if (i_spot == 1 && s[0] == '-')
                c.b = -1;
            else if (i_spot == 1 && s[0] == '+')
                c.b = 1;
            else
                c.b = stof(s);
        }
        else
        {
            if (plus != string::npos)
            {

                c.a = stof(s.substr(0, plus + 1));
                if (plus + 2 == i_spot)
                    c.b = 1;
                else if (minus + 2 == i_spot)
                    c.b = -1;
                else
                    c.b = stof(s.substr(plus + 2, s.length() - plus - 1 - 1));
            }
            else if (minus != string::npos)
            {
                c.a = stof(s.substr(0, minus + 1));
                if (minus + 2 == i_spot)
                    c.b = -1;
                else
                    c.b = stof(s.substr(minus + 1, s.length() - minus - 1 - 1));
            }
        }
    }

    return is;
}

//========================================================
// operator<< - Overload << for cout to output complex numbers.
//
// Parameters:
// os - The output stream (cout).
// c - The complex number to write to the output stream.
//
// Return Value:
// The output stream (cout) after writing the complex number.
//========================================================
ostream &operator<<(ostream &os, const Complex c)
{
    string strb = to_string(c.b);
    if (abs(c.b) == 1)
    {
        strb = strb.substr(0, strb.find('1'));
    }
    if (c.a == 0 && c.b == 0)
        os << 0;
    else if (c.b == 0)
        os << c.a;

    else if (c.a == 0)
        os << strb << "i";
    else if (c.b < 0)
        os << c.a << strb << "i";
    else
        os << c.a << "+" << strb << "i";

    return os;
}