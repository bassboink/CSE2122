/* File: main.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/10/16
   Synopsis: This program manages bank accounts, CD accounts and money market accounts. This program must be compiled alongside bankaccount.cpp, cdaccount.cpp, and moneymarketaccount.cpp to work correctly.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "bankaccount.h"
#include "cdaccount.h"
#include "moneymarketaccount.h"

//Function prototype for the transfer function (the only non member function in the program)
bool transfer(BankAccount* from, BankAccount* to, double amount);

int main()
{
    //Create accounts
    MoneyMarketAccount acct1;
    CDAccount acct2;

    //Set the name for the first account
    string name1;
    cout << "Enter name for Money Market Account: ";
    getline(cin, name1);
    acct1.setName(name1);

    //Set the name for the second account
    string name2;
    cout << "Enter name for CD Account: ";
    getline(cin, name2);
    acct2.setName(name2);

    //Set the initial balance of the first account
    double balance1;
    cout << "Enter " << acct1.getName() << "'s initial balance: ";
    cin >> balance1;
    acct1.setBalance(balance1);

    //Set the initial balance of the second acocunt
    double balance2;
    cout << "Enter " << acct2.getName() << "'s initial balance: ";
    cin >> balance2;
    acct2.setBalance(balance2);

    //Set the interest rate of the CD Account
    double interestRate;
    cout << "Enter " << acct2.getName() << "'s interest rate: ";
    cin >> interestRate;
    acct2.setInterestRate(interestRate);

    cout << endl;

    //Read first amount, withdraw from account 1, display new balance or error
    double amount1;
    cout << "Enter amount to withdraw from " << acct1.getName() << ": ";
    cin >> amount1;
    bool worked1 = acct1.withdraw(amount1);
    if (worked1)
    {
        cout << "That worked." << endl;
        cout << acct1.getName() << "'s new balance: ";
        acct1.printBalance();
        cout << endl << endl;
    }
    else
    {
        cout << "That didn't work." << endl << endl;
    }

    //Read second amount, withdraw from account 1, display new balance or error
    double amount2;
    cout << "Enter amount to withdraw from " << acct1.getName() << " (again): ";
    cin >> amount2;
    bool worked2 = acct1.withdraw(amount2);
    if (worked2)
    {
        cout << "That worked." << endl;
        cout << acct1.getName() << "'s new balance: ";
        acct1.printBalance();
        cout << endl << endl;
    }
    else
    {
        cout << "That didn't work." << endl << endl;
    }

    //Read third amount, deposit into account 2, display new balance or error
    double amount3;
    cout << "Enter amount to deposit into " << acct2.getName() << "'s account: ";
    cin >> amount3;
    bool worked3 = acct2.deposit(amount3);
    if (worked3)
    {
        cout << "That worked." << endl;
        cout << acct2.getName() << "'s new balance: ";
        acct2.printBalance();
        cout << endl << endl;
    }
    else
    {
        cout << "That didn't work." << endl << endl;
    }

    //Read amount 4, transfer from account 2 to 1, display new balances or error
    double amount4;
    cout << "Enter amount to transfer from " << acct2.getName() << " to " << acct1.getName() << ": ";
    cin >> amount4;
    bool worked4 = transfer(&acct2, &acct1, amount4);
    if (worked4)
    {
        cout << "That worked." << endl;
        cout << acct1.getName() << "'s new balance: ";
        acct1.printBalance();
        cout << endl;
        cout << acct2.getName() << "'s new balance: ";
        acct2.printBalance();
        cout << endl << endl;
    }
    else
    {
        cout << "That didn't work." << endl << endl;
    }

    //Read amount 5, transfer from account 1 to 2, display new balances or error
    double amount5;
    cout << "Enter amount to transfer from " << acct1.getName() << " to " << acct2.getName() << ": ";
    cin >> amount5;
    bool worked5 = transfer(&acct1, &acct2, amount5);
    if (worked5)
    {
        cout << "That worked." << endl;
        cout << acct1.getName() << "'s new balance: ";
        acct1.printBalance();
        cout << endl;
        cout << acct2.getName() << "'s new balance: ";
        acct2.printBalance();
        cout << endl << endl;
    }
    else
    {
        cout << "That didn't work." << endl << endl;
    }

    return 0;
}

//This function transfers money from one account to another (withdraws money in one account and deposits into another).
//from is the account that is being withdrawn from
//to is the account that is receiving the deposit
//amount is the amount of money being transfered
bool transfer(BankAccount* from, BankAccount* to, double amount)
{
    bool worked1 = from->withdraw(amount);
    bool worked2 = false;

    if (worked1)
    {
        worked2 = to->deposit(amount);
    }

    if (worked1 && worked2)
    {
        return true;
    }
    return false;
}
