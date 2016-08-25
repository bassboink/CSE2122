/* File: rational.h
   Created by: Mitchell Wendt
   Created on: 7/4/16
   Synopsis: This file stores the class definition of a rational number.
*/

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
    int numerator;
    int denominator;

    //Constructors
    Rational(int, int);
    Rational(int);
    Rational();

    //Functions
    void print();
    int gcd(int, int);

    //Operations
    Rational add(Rational&);
    Rational sub(Rational&);
    Rational mul(Rational&);
    Rational div(Rational&);
    bool less(Rational&);
    Rational neg();

    //Operation Overloading
    Rational operator+ (Rational&);
    Rational operator- (Rational&);
    Rational operator* (Rational&);
    Rational operator/ (Rational&);
    bool operator< (Rational&);
    Rational operator-();

};

#endif
