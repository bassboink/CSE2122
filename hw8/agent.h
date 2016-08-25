/* File: agent.h
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the abstract class definition of an agent
*/

#ifndef AGENT_H
#define AGENT_H

#include<string>
#include "room.h"
#include "thing.h"
using namespace std;

class Agent : public Thing
{
protected:
    string name;
    string type;
public:
    Agent(string _name, Room* _current_room);
    virtual bool act()=0;
    string getName();
    string getType();
};

#endif

