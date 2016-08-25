/* File: ghost.h
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the class definition of a ghost
*/

#ifndef GHOST_H
#define GHOST_H

using namespace std;

#include "agent.h"

class Ghost : public Agent
{
public:
    Ghost(string _name, Room* _current_room);
    bool act();
};

#endif

