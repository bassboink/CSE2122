/* File: bankaccount.h
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This file contains the class definition of a bank account
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
private:
    string owner;
protected:
    double balance;
public:
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    string getName();
    double getBalance();
    void setName(string _owner);
    void setBalance(double _balance);
    void printBalance();
};

#endif

