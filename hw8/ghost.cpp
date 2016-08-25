/* File: ghost.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the member functions of the ghost class
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

Ghost::Ghost(string _name, Room* _current_room) 
: Agent(_name, _current_room)
{
    name = _name;
    type = "ghost";
    current_room = _current_room;
}

bool Ghost::act()
{
    int n = rand() % 4;
    string direction;
    switch(n)
    {
        case 0: direction = "north"; break;
        case 1: direction = "south"; break;
        case 2: direction = "west"; break;
        case 3: direction = "east"; break;
    }
    //Repeat if the direction doesn't go anywhere
    while((current_room->getLinked(direction)->getName() == "empty") || (current_room->getLinked(direction)->getName() == "Outside, locked"))
    {
        n = rand() % 4;
        switch(n)
        {
            case 0: direction = "north"; break;
            case 1: direction = "south"; break;
            case 2: direction = "west"; break;
            case 3: direction = "east"; break;
        }
    }
    Room* last_room = current_room;
    current_room = current_room->getLinked(direction);
    //leave room, enter room

    return true;
}
