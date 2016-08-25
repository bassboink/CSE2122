/* File: player.h
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the class definition of a player
*/

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "agent.h"

class Player : public Agent
{
private:
    int health;
    bool dead;
    bool has_key;
    string input;
public:
    Player(string _name, Room* _current_room);
    bool getDead();
    void die();
    bool hasKey();
    void obtainKey();
    void loseKey();
    string getInput();
    void setHealth(int _health);
    int getHealth();
    bool act();
    void printHealth();
};

#endif

