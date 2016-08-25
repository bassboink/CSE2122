/* File: cdaccount.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the member functions of a CD Account
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "bankaccount.h"
#include "cdaccount.h"

//This function deposits money in a CD Account, returns false if the deposit is invalid
//amount is the amount that is being deposited
bool CDAccount::deposit(double amount)
{
    if (amount < 0)
    {
        return false;
    }

    balance += amount;
    return true;
}

//This function withdraws money from a CD Account, returns false if the withdraw is invalid
//amount is the amount being withdrawn from the account
bool CDAccount::withdraw(double amount)
{
    if (amount < 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    balance = balance - amount - (0.25 * balance * interestRate);
    return true;
}

//This function sets the interest rate of a CD Account
//_interest rate is the interest rate being set
void CDAccount::setInterestRate(double _interestRate)
{
    interestRate = _interestRate;
}


