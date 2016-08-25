/* File: room.h
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This file contains the class definition of a room
*/

#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Agent;

class Room
{
private:
    string name;
    string description;
    int numLinks;
    map<string, Room*> connections;
    set<Agent*> occupants;

public:
    Room(string _name, string _description);
    string getName();
    string getDescription();
    void link(string direction, Room *r);
    Room* getLinked(string direction);
    void printLinked();
    void printOccupants(Agent* current_player);
    int numGhosts();
    int numPlayers();
    void enter(Agent* a);
    void leave(Agent* a);
};

#endif

