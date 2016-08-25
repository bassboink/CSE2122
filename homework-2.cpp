/* File: homework-2.cpp
   Created by: Mitchell Wendt
   Created on: 6/9/2016
   Synopsis: This program calculates the coin amounts (pennies, dimes, and quarters) needed to give a specific amount of change (from 1 cent to 99 cents). The user is first asked to enter an amount and then the program calculates and displays the number of pennies, dimes, and quarters needed to give the specific amount of change. The user will be asked if they wish to make a calculation again until the user says that they are done. 
*/

#include <iostream>
using namespace std;

//Function Prototype
void compute_coin(int coin_value, int& number, int& amount_left);

int main()
{
   //Initialize variables
   bool keepGoing = true;      //boolean that stores whether the user wants to keep making calculations or not
   char keepGoingInput;        //user input to assign keepGoing
   int change_to_give = 0;     //user input for change to give
   int amount_left;            //amount left to give in change    
   int numPennies = 0;         //number of pennies needed
   int numDimes = 0;           //number of dimes needed
   int numQuarters = 0;        //number of quarters needed

   while (keepGoing) {

      //Prompt user for an amount of change
      cout << "Enter an amount of change to give (from 1 to 99 cents): ";
      cin >> change_to_give;

      //Check to see if the input is valid
      while (change_to_give < 1 || change_to_give > 99) {
         cout << "Invalid input. Enter a number from 1 to 99: ";
         cin >> change_to_give;
      }

      cout << endl;
      amount_left = change_to_give;

      //Calculate coin amounts
      compute_coin(25, numQuarters, amount_left);    //Quarters
      compute_coin(10, numDimes, amount_left);       //Dimes
      compute_coin(1, numPennies, amount_left);      //Pennies

      //Display coin amounts
      cout << change_to_give << " cents can be given as" << endl;
      cout << numQuarters << " quarter(s) " << numDimes << " dime(s) and " << numPennies << " penny(pennies)" << endl << endl; 

      //Ask user if they want to continue
      cout << "Would you like to make another calculation? Y or y for yes, N or n for no: ";
      cin >> keepGoingInput;
      while (!(keepGoingInput == 'Y' || keepGoingInput == 'y' || keepGoingInput == 'N' || keepGoingInput == 'n')) {
         cout << "Invalid input. Enter Y or y for yes, or N or n for no: ";
         cin >> keepGoingInput;
      }
      if (keepGoingInput == 'N' || keepGoingInput == 'n') {
         keepGoing = false;
      }
      else {
         //Reset values for next loop
         numPennies = 0;
         numDimes = 0;
         numQuarters = 0;
         
         cout << endl << endl << endl;
      }
   }

   return 0;
}

//Function Definitions

//This function calculates the amount of each coin type that is needed as well as the remaining amount of change remaining
//coin_value is the value of the coin being counted (ie 25 for quarters, 10 for dimes, and 1 for pennies)
//number is the number of the type of coin that is needed
//amount_left is the amount of change that still needs to be given
void compute_coin(int coin_value, int& number, int& amount_left) {
   
   number = amount_left/coin_value;
   amount_left = amount_left % coin_value;

}
