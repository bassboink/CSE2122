/* File: player.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the member functions of the player class
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

#include "room.h"
#include "thing.h"
#include "agent.h"
#include "player.h"
#include "ghost.h"

Player::Player(string _name, Room* _current_room) 
: Agent(_name, _current_room)
{
    name = _name;
    type = "player";
    health = 5;
    current_room = _current_room;
    dead = false;
}

bool Player::getDead()
{
    return dead;
}

void Player::die()
{
    dead = true;
}

bool Player::hasKey()
{
    return has_key;
}

void Player::obtainKey()
{
    has_key = true;
}

void Player::loseKey()
{
    has_key = false;
}

string Player::getInput()
{
    return input;
}

void Player::setHealth(int _health)
{
    health = _health;
}

int Player::getHealth()
{
    return health;
}

bool Player::act()
{
    //Prompt
    cout << "Which exit? (or 'quit', 'look for key', or 'unlock door'): ";
    getline(cin, input);
    cout << endl;

    //Reprompt until valid input is found
    while(!((input == "quit") || (input == "look for key") || (input == "unlock door") || (input == "north") || (input == "south") || (input == "east") || (input == "west")))
    {
        cout << "Sorry, I did not understand you." << endl << endl;
        cout << "Which exit? (or 'quit', 'look for key', or 'unlock door'): ";
        getline(cin, input);
        cout << endl;
    }

    if (input == "quit") 
    {
        cout << "Game Quits." << endl << endl;
        return false;
    }

    return true;
}

void Player::printHealth()
{
    cout << "You have " << health << " health left..." << endl << endl;
    if (health <= 0)
    {
        dead = true;
        loseKey();
    }
}


