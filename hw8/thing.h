/* File: thing.h
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the class definition of a thing
*/

#ifndef THING_H
#define THING_H

#include <string>
#include "room.h"
using namespace std;

class Thing
{
public:
    Thing(Room* _current_room);
    Room* current_room;
};

#endif

