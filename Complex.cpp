//========================================================
// put all group names here
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
//========================================================
void Complex::setReal(float r)
{
    a = r;
}
//========================================================
// getReal access method
//========================================================
float Complex::getReal(void) const
{
    return a;
}
//========================================================
// setImag
//========================================================

void Complex::setImag(float x)
{
    a = x;
}

//========================================================
// getImag
//========================================================

float Complex::getImag(void) const
{
    return a;
}

//========================================================
// assignment operator
//========================================================
Complex Complex::operator=(const Complex &c)
{
    a = c.a;
    b = c.b;
    return *this;
}
//========================================================
// addition operators
//========================================================
Complex Complex::operator+(const Complex &c) const
{
    Complex res;
    res.a = a + c.a;
    res.b = b + c.b;

    return res;
}

Complex Complex::operator+(int i) const
{
    Complex res;
    res.a = a + (float)i;
    res.b = b;
    return res;
}

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

Complex Complex::operator-(const Complex &c) const
{
    Complex res;
    res.a = a - c.a;
    res.b = b - c.b;
    return res;
}

Complex Complex::operator-(int i) const
{
    Complex res;
    res.a = a - (float)i;
    res.b = b;
    return res;
}

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

Complex Complex::operator*(const Complex &c) const
{
    Complex res;
    res.a = a * c.a - b * c.b;
    res.b = a * c.b + b * c.a;
    return res;
}

Complex Complex::operator*(int i) const
{
    Complex res;
    res.a = a * i;
    res.b = b * i;
    return res;
}

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

Complex Complex::operator/(const Complex &c) const
{
    Complex res;
    res.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
    res.b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
    return res;
}

Complex Complex::operator/(int i) const
{
    Complex res;
    res.a = a / (float)i;
    res.b = b / (float)i;
    return res;
}

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

Complex Complex::operator^(int p) const
{
    Complex res(a, b);
    Complex temp(a, b);
    for (int i = 0; i < p - 1; i++)
    {
        res = res * temp;
    }

    return res;
}

//========================================================
// operator~
//========================================================

Complex Complex::operator~(void) const
{
    Complex res;
    res.a = a;
    res.b = -b;
    return res;
}

//========================================================
// abs
//========================================================
float Complex::abs(void) const
{
    return sqrt(a * a + b * b);
}
//========================================================
// equality operator
//========================================================

bool Complex::operator==(const Complex &c) const
{
    return ((a == c.a) && (b == c.b));
}

//========================================================
// inequality operator
//========================================================

bool Complex::operator!=(const Complex &c) const
{
    return (a != c.a || b != c.b);
}

//========================================================
// overload >> for cin
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
// overload << for cout
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