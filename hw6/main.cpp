/* File: main.cpp
   Created by: Mitchell Wendt
   Created on: 7/4/16
   Synopsis: This program evaluates some expressions of rational numbers using a class representation of rational numbers. Rational numbers are stored in the class in reduced form as a numerator and denominator. The functions of the class include adding, subtracting, multiplying, dividing, less than, and printing.
*/

#include <iostream>
using namespace std;

#include "rational.h"

int main ()
{
    //Test Functions
    Rational a(5,7);
    Rational b(25,-5);
    Rational y;
    Rational z(-300);

    //Test print, constructors
    cout << "a = ";
    a.print();
    cout << endl;

    cout << "b = ";
    b.print();
    cout << endl;

    cout << "y = ";
    y.print();
    cout << endl;

    cout << "z = ";
    z.print();
    cout << endl << endl;

    //Test adding
    Rational c = a.add(b);
  
    cout << "c = a.add(b) = ";
    c.print();
    cout << endl;

    Rational d = c + b;

    cout << "d = c + b = ";
    d.print();
    cout << endl << endl;

    //Test subtracting
    Rational e = b.sub(c);

    cout << "e = b.sub(c) = ";
    e.print();
    cout << endl;

    Rational f = d - a;

    cout << "f = d - a = ";
    f.print();
    cout << endl << endl;

    //Test multiplying
    Rational g = f.mul(e);

    cout << "g = f.mul(e) = ";
    g.print();
    cout << endl;

    Rational h = b * e;
    
    cout << "h = b * e = ";
    h.print();
    cout << endl << endl;

    //Test dividing
    Rational i = b.div(g);

    cout << "i = b.div(g) = ";
    i.print();
    cout << endl;

    Rational j = f / c;

    cout << "j = f / c = ";
    j.print();
    cout << endl << endl;

    //Test less than
    if (a < b)
    {
        a.print();
        cout << " (a) is less than ";
        b.print();
        cout << " (b)" << endl;
    }
    else
    {
        b.print();
        cout << " (b) is less than ";
        a.print();
        cout << " (a)" << endl;
    }

    if (c.less(d))
    {
        c.print();
        cout << " (c) is less than ";
        d.print();
        cout << " (d)" << endl;
    }
    else
    {
        d.print();
        cout << " (d) is less than ";
        c.print();
        cout << " (c)" << endl;
    }

    cout << endl;

    //Test Negative
    Rational k = -g;

    cout << "k = -g (negative g) = ";
    k.print();
    cout << endl;

    Rational l = b.neg();

    cout << "l = b.neg() = ";
    l.print();
    cout << endl << endl;

    return 0;
}
