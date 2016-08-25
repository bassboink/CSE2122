/* File: agent.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the member functions of the agent class
*/

#include<string>
#include<map>
#include<set>
#include "room.h"
#include "agent.h"

Agent::Agent(string _name, Room* _current_room) 
: Thing(_current_room)
{
    name = _name;
    current_room = _current_room;
}

string Agent::getName()
{
    return name;
}

string Agent::getType()
{
    return type;
}


