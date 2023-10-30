//========================================================
// Matt Kretchmar
// Complex.h
// October 2023
// This file contains the class declaration for the
// Complex number class.
// DO NOT CHANGE THIS FILE!!!
//========================================================

#include <iostream>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    float a;          // number = a + bi
    float b;
public:
                Complex         ( void ) { a = 0; b = 0; }
                Complex         ( const Complex &c ) { a = c.a; b = c.b; }
                Complex         ( float x, float y ) { a = x; b = y; }
               ~Complex         ( void ) {} // destructor
    void        setReal         ( float r );
    float       getReal         ( void ) const;
    void        setImag         ( float r );
    float       getImag         ( void ) const;
    Complex     operator=       ( const Complex &c );
    Complex     operator+       ( const Complex &c ) const;
    Complex     operator+       ( float f ) const;
    Complex     operator+       ( int i ) const;
    Complex     operator-       ( const Complex &c ) const;
    Complex     operator-       ( float f ) const;
    Complex     operator-       ( int i ) const;
    Complex     operator*       ( const Complex &c ) const;
    Complex     operator*       ( float f ) const;
    Complex     operator*       ( int i ) const;
    Complex     operator/       ( const Complex &c ) const;
    Complex     operator/       ( float f ) const;
    Complex     operator/       ( int i ) const;
    Complex     operator~       ( void ) const;
    Complex     operator^       ( int p ) const;
    float       abs             ( void ) const;
    bool        operator==      ( const Complex &c ) const;
    bool        operator!=      ( const Complex &c ) const;

    friend ostream & operator<< ( ostream &, const Complex c );
    friend istream & operator>> ( istream &, Complex &c );
};


#endif
