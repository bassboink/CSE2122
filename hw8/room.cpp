/* File: room.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the member functions of the room class
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

Room empty("empty", "empty");

Room::Room(string _name, string _description)
{
    name = _name;
    description = _description;
    numLinks = 0;
}

string Room::getName()
{
    return name;
}

string Room::getDescription()
{
    return description;
}

void Room::link(string direction, Room *r)
{
    numLinks++;
    connections[direction] = r;
}

Room* Room::getLinked(string direction)
{
    map<string, Room*>::iterator it = connections.find(direction);

    if (it != connections.end())
    {
        return connections[direction];
    }
    else 
    {
        return &empty;
    }
}

void Room::printLinked()
{
    map<string, Room*>::iterator it;
    int numRooms = connections.size();
    int index = 1;

    cout << "There is an exit ";

    for (it = connections.begin(); it != connections.end(); ++it)
    {
        if ((numRooms == index) && (numRooms != 1))
        {
            cout << "and ";
        }
        cout << it->first << " (" << it->second->name << ")";
        if (!(numRooms == index) && (numRooms != 1))
        {
            cout << ", ";
        }
        index += 1;
    }

    cout << "." << endl << endl;
}


void Room::printOccupants(Agent* current_player)
{
    set<Agent*>::iterator it;
    int numPeople = occupants.size() - 1;
    int index = 1;

    cout << "You see ";

    if (numPeople == 0)
    {
        cout << "nobody else";
    }

    else
    {
        for (it = occupants.begin(); it != occupants.end(); ++it)
        {
            if ((*it) != current_player)
            {
                if ((numPeople == index) && (numPeople != 1))
                {
                    cout << "and ";
                }
                cout << (*it)->getName();
                if (!(numPeople == index) && (numPeople != 1) && (numPeople != 2))
                {
                    cout << ", ";
                }
                else if (!(numPeople == index) && (numPeople == 2))
                {
                    cout << " ";
                }
                index += 1;
            }
        }
    }

    cout << " in the room with you." << endl << endl;
} 

int Room::numGhosts()
{
    int ghosts = 0;
    set<Agent*>::iterator it;
    for (it = occupants.begin(); it != occupants.end(); ++it)
    {
        if ((*it)->getType() == "ghost")
        {
            ghosts++;
        }
    }
    return ghosts;
}

int Room::numPlayers()
{
    int players = 0;
    set<Agent*>::iterator it;
    for (it = occupants.begin(); it != occupants.end(); ++it)
    {
        if ((*it)->getType() == "player")
        {
            players++;
        }
    }
    return players;
}

void Room::enter(Agent* a)
{
    occupants.insert(a);
}

void Room::leave(Agent* a)
{
    occupants.erase(a);
}
