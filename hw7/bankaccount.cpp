/* File: bankaccount.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the member functions of the bank account class
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "bankaccount.h"

//This function returns the name of an account
string BankAccount::getName()
{
    return owner;
}

//This function returns the balance of an account
double BankAccount::getBalance()
{
    return balance;
}

//This function sets the name of an account
//_owner is the name that is being set
void BankAccount::setName(string _owner)
{
    owner = _owner;
}

//This function sets the initial balance of an account
//_balance is the amount the initial balance is set to 
void BankAccount::setBalance(double _balance)
{
    balance = _balance;
}

//This function prints the balance in bank format (with a dollar sign in front and 2 decimal places)
void BankAccount::printBalance()
{
    cout << fixed << setprecision(2) << "$" << balance;
}


