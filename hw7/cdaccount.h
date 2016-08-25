/* File: cdaccount.h
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the class definition of a CD account
*/

#ifndef CDACCOUNT_H
#define CDACCOUNT_H

class CDAccount : public BankAccount
{
private:
    double interestRate;
public:
    bool deposit(double amount);
    bool withdraw(double amount);
    void setInterestRate(double _interestRate);
};

#endif

