/* File: homework-1.cpp
   Created by: Mitchell Wendt
   Created on: 6/7/2016
   Synopsis: This program calculates the score of a blackjack hand. The user is first prompted for a number of cards (2 thru 5) and is then prompted to enter each card (2-9, t, j, q, k, a). Finally, the blackjack score is calculated.
*/

#include <iostream>
using namespace std;

int main()
{
   //Variable declarations
   int numCards = 0;               //number of cards given by user
   char card;                      //user input of cards
   int score = 0;                  //blackjack score
   int numAces = 0;                //number of aces input by the user
   bool keepGoing = true;          //boolean that stores whether the user wants to keep playing or not
   char keepGoingInput;            //user input that determines whether to continue the program after a calculation or not

   //Loop until the user says they're done
   while (keepGoing) {

      //Prompt user for number of cards
      cout << "Enter number of cards (2-5): ";
      cin >> numCards;

      //Prompt user for cards
      for (int i = 0; i < numCards; i++) {
         cout << "Enter a card (2-9, t (ten), j (jack), q (queen), k (king), or a (ace)): ";
         cin >> card;

         //Add to score 
         switch (card) {
            case '2':
               score += 2;
               break;
            case '3':
               score += 3;
               break;
            case '4':
               score += 4;
               break;
            case '5':
               score += 5;
               break;
            case '6':
               score += 6;
               break;
            case '7':
               score += 7;
               break;
            case '8':
               score += 8; 
               break;
            case '9':
               score += 9;
               break;
            case 't': case 'T':
               score += 10;
               break;
            case 'j': case 'J':
               score += 10;
               break;
            case 'q': case 'Q':
               score += 10;
               break;
            case 'k': case 'K':
               score += 10;
               break;
            case 'a': case 'A':           //Aces must be considered last
               numAces++;
               break;
         }
      }

      //Now consider aces
      for (int i = 0; i < numAces; i++) {
         if (score + 11 <= 21) {
            score += 11;
         }
         else {
            score += 1;
         }
      }    

      //Display score
      cout << endl;
      if (score > 21) {
         cout << "Busted" << endl;
      }
      else {
         cout << "Your score is " << score << endl;
      }

      //Reset scores
      score = 0;
      numAces = 0;

      //Ask user to keep going
      cout << endl;
      cout << "Would you like to play again? Y or y for yes, N or n for no: ";
      cin >> keepGoingInput;

      //Check for valid input
      while (!(keepGoingInput == 'Y' || keepGoingInput == 'y' || keepGoingInput == 'N' || keepGoingInput == 'n')) {
         cout << "Invalid input, please enter Y, y, N, or n: ";
         cin >> keepGoingInput;
      }

      //Update keepGoing if user is done
      if (keepGoingInput == 'N' || keepGoingInput == 'n') {
         keepGoing = false;
      }
      else {
         cout << endl;
      }

   }

   return 0;
}

