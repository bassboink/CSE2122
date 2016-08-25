/* File: rational.cpp
   Created by: Mitchell Wendt
   Created on: 7/4/16
   Synopsis: This file stores the member functions (as well as general functions) used by the rational class.
*/

#include <iostream>
#include "rational.h"
using namespace std;

//Constructors

//This constructor is for two parameters: _numerator and _denominator
Rational::Rational(int _numerator, int _denominator)
{
    //Reduce Numerator and Denominator
    int g = gcd(_numerator, _denominator);
    _numerator = _numerator / g;
    _denominator = _denominator / g;

    //Fix negative signs (so that only the numerator can be negative)
    if (_denominator < 0)
    {
        _denominator = _denominator * -1;
        _numerator = _numerator * -1;
    }

    //Finally assign class attributes
    numerator = _numerator;
    denominator = _denominator;

}

//This constructor is for one parameter: _numerator. Denominator defaults to one
Rational::Rational(int _numerator)
{
    numerator = _numerator;
    denominator = 1;
}

//This constructor is for zero parameters. Numerator defaults to 0, denominator defaults to 1
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

//This function prints a rational number
//This function assumes that the constructor is used correctly and all the time so that the fractions are always reduced and the deominator is always positive.
void Rational::print()
{
    cout << numerator << "/" << denominator;
}

//This function calculates the GCD of two numbers
//a and b are the two numbers of which the GCD is being calculated
//Note: This function was made as a member function of class Rational for the purposes of scope
int Rational::gcd(int a, int b)
{
    //g is the greatest common denominator
    int g;

    /* Work with absolute values (positive integers) */
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if ((a+b) == 0)
    {
        return 0; // Error, both parameters zero
    }

    g = b;

    // Iterate until a = 0
    while(a > 0)
    {
        g = a;
        a = b % a;
        b = g;
    }

    return g;
}

//Operations

//This function adds 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::add(Rational& rhs)
{
    return Rational(((numerator * rhs.denominator) + (denominator * rhs.numerator)), (denominator  * rhs.denominator));
}

//This function subtracts 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::sub(Rational& rhs)
{
    return Rational(((numerator * rhs.denominator) - (denominator * rhs.numerator)), (denominator  * rhs.denominator));
}

//This function multiplies 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::mul(Rational& rhs)
{
    return Rational((numerator * rhs.numerator), (denominator * rhs.denominator));
}

//This function divides 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::div(Rational& rhs)
{
    return Rational((numerator * rhs.denominator), (denominator * rhs.numerator));
}

//This function determines if a rational number is less than another rational number
//rhs is the right hand of the expression
bool Rational::less(Rational& rhs)
{
    if ((numerator * rhs.denominator) < (denominator * rhs.numerator)) {
        return true;
    }
    return false;
}

Rational Rational::neg()
{
    return Rational(numerator * -1, denominator);
}

//Operation Overloading

//This function adds 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::operator+ (Rational& rhs)
{
    return Rational(((numerator * rhs.denominator) + (denominator * rhs.numerator)), (denominator  * rhs.denominator));
}

//This function subtracts 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::operator- (Rational& rhs)
{
    return Rational(((numerator * rhs.denominator) - (denominator * rhs.numerator)), (denominator  * rhs.denominator));
}

//This function multiplies 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::operator* (Rational& rhs)
{
    return Rational((numerator * rhs.numerator), (denominator * rhs.denominator));
}

//This function divides 2 rational numbers
//rhs is the right hand of the expression
Rational Rational::operator/ (Rational& rhs)
{
    return Rational((numerator * rhs.denominator), (denominator * rhs.numerator));
}

//This function determines if a rational number is less than another rational number
//rhs is the right hand of the expression
bool Rational::operator< (Rational& rhs)
{
    if ((numerator * rhs.denominator) < (denominator * rhs.numerator)) {
        return true;
    }
    return false;
}

//This function returns the negative of a rational number
Rational Rational::operator-()
{
    return Rational(numerator * -1, denominator);
}

