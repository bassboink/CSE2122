/* File: moneymarketaccount.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the member functions of the money market account class.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "bankaccount.h"
#include "moneymarketaccount.h"

//This function deposits money into a money market account
//amount is the amount being deposited
bool MoneyMarketAccount::deposit(double amount)
{
    if (amount < 0)
    {
        return false;
    }

    balance += amount;
    return true;
}

//This function withdraws money from a money market account
//amount is the amount being withdrawn
bool MoneyMarketAccount::withdraw(double amount)
{
    if (amount < 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    numWithdraws++;

    if (numWithdraws > 2)
    {
        balance = balance - amount - 1.5;
    }
    else
    {
        balance = balance - amount;
    }
    return true;
}
