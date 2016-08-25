/* File: moneymarketaccount.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the class definition of a money market account
*/

#ifndef MONEYMARKETACCOUNT_H
#define MONEYMARKETACCOUNT_H

class MoneyMarketAccount : public BankAccount
{
private:
    //Note: I would do "int numWithdraws = 0;" and not include a constructor (as I am using setters and getters instead), but that only works in C++ 11 according to a warning message on my system.
    int numWithdraws;
public:
    MoneyMarketAccount()
    {
        numWithdraws = 0;
    }
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif

