/* File: main.cpp
   This file was created by: Mitchell Wendt
   Created on: 7/16/16
   Synopsis: This program allows a player to wander through a maze. This program must be compiled with room.cpp and needs the room.h header file.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

#include "room.h"

int main()
{
    cout << endl << "Welcome!" << endl << endl;

    cout << "Instructions: Your goal is to find the key lost somewhere in this house and escape first. Valid commands are directions ('north', 'south', 'east', and 'west') to move to a different room, 'quit' to quit the game, 'look for key' which lets you look for the key in your current room, and 'unlock door' which lets you open the locked door, escape, and win the game." << endl << endl << endl;

    //Make Rooms
    Room great_hall("Great Hall", "A giant statue of the home owner lies in the middle of the large room. You wonder where he went.");
    Room kitchen("Kitchen", "Dirty dishes lie all over the counters and table. Fresh smells of spaghetti and garlic bread linger. It makes you hungry.");
    Room bedroom("Bedroom", "The bed, decorated with a beach theme, is neaty made. It makes you sleepy, but you stay awake as there are ghosts around.");
    Room den("Den", "The TV is playing Family Feud, but nobody else is around to watch it. You want to watch for a while, but cannot due to the ghosts.");
    Room bathroom("Bathroom", "The bathtub is filled with luke warm soapy water. You wonder why the water wasn't drained when whoever was bathing left.");
    Room garage("Garage", "Yard tools surround the area. An old Jeep Wrangler is sitting in the garage unlocked. You guess that the car hasn't been serviced in years.");
    Room laundry_room("Laundry Room", "There are clothes in the washer and the dryer, both of which were running. You politely allow the machines to continue running.");
    Room dining_room("Dining Room", "A large collection of China overlooks the cherry wood table. You admire the antique grandfather clock in the corner.");
    Room living_room("Living Room", "A huge couch lies in front of a gargantuan plasma screen TV. Antiques are in shelves around the room.");
    Room swimming_pool("Swimming Pool", "A large inground pool with a diving board taunts you on a warm summer day. The pool cleaner is running, but the pool still looks dirty anyway.");
    Room wine_cellar("Wine Cellar", "Bottles of aged wine surround you, as you constantly run into cobwebs. You feel that you could use a drink after being chased around by ghosts all day.");
    Room tool_shed("Tool Shed", "Shovels, Rakes, Chainsaws and Lawn Mowers are crowded in the tiny shed. You feel like you could fend off any other monster other than ghosts with 'weapons' like these.");
    Room man_cave("'Man Cave'", "Dozens of gaming consoles are stacked on top of each other in the entertainment center. Football Jerseys decorate the walls. Old pizza boxes are scattered around the room.");
    Room closet("Closet", "Coats and hats flood out of the closet and immediately into your face. You replace all the coats haphazardly back into the closet, noting that these clothes look like they're from a hundred years ago or something.");
    Room pantry("Pantry", "Enough canned to survive the apocalypse is in one corner of the room. A few frozen TV dinners and cans of pop are in the minifridge and minifreezer. The rest of the pantry is filled with junkfood.");
    Room win("Outside, locked", "You win! Press Control + Z to end the game.");
    Room empty("empty", "empty");

    //Make Connections
    great_hall.link("north", &living_room);
    great_hall.link("south", &win);
    great_hall.link("east", &den);
    great_hall.link("west", &dining_room);

    den.link("west", &great_hall);

    living_room.link("north", &swimming_pool);
    living_room.link("south", &great_hall);
    living_room.link("east", &bedroom);
    living_room.link("west", &kitchen);

    dining_room.link("north", &kitchen);
    dining_room.link("south", &man_cave);
    dining_room.link("east", &great_hall);

    man_cave.link("north", &dining_room);

    kitchen.link("north", &pantry);
    kitchen.link("south", &dining_room);
    kitchen.link("east", &living_room);
    kitchen.link("west", &laundry_room);

    pantry.link("south", &kitchen);

    laundry_room.link("south", &garage);
    laundry_room.link("east", &kitchen);

    garage.link("north", &laundry_room);

    bedroom.link("north", &closet);
    bedroom.link("south", &bathroom);
    bedroom.link("west", &living_room);

    bathroom.link("north", &bedroom);

    closet.link("south", &bedroom);

    swimming_pool.link("north", &wine_cellar);
    swimming_pool.link("south", &living_room);
    swimming_pool.link("east", &tool_shed);

    wine_cellar.link("south", &swimming_pool);

    tool_shed.link("west", &swimming_pool);

/*
    //Make Players
    string name1;
    string name2;

    cout << "Enter the name of Player 1: ";
    getline(cin, name1);
    cout << endl;

    cout << "Enter the name of Player 2: ";
    getline(cin, name2);
    cout << endl << endl << endl;
*/

    //Initialize Variables
    Room* current_room = &great_hall;
    string input = "start";

    //Play the game until the user says to quit
    while(input != "quit")
    {
        //Display current info
        cout << "You are in the " << current_room->getName() << ". " << current_room->getDescription() << endl << endl;

        //Print connected rooms
        current_room->printLinked();

        //Print room occupants
        //current_room->printOccupants();

        //Print health...

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

        //Display where the user is going
        if (input == "unlock door")
        {
/*
            if (player indeed has key and is at the locked door)
            {
                cout << "You pray that the key fits the locked door and try to insert it. Success! You open the door leading outside with a loud creak, and slam the door behind you , breathing heavily with a sigh of relief. You call an Uber and get yourself home. You win!" << endl << endl;
                return 2;
            }
            else 
            {
                cout << "You can't do that! "
                if (no locked door nearby)
                {
                    cout << "There's no door to unlock." << endl << endl;
                }
                else 
                {
                    cout << "You need a key." << endl << endl;
                }
            }

            //Reprompt
            cout << "Which exit? (or 'quit', 'look for key', or 'unlock door'): ";
            getline(cin, input);
            cout << endl;

            //Reprompt until valid input is found
            while(!((input == "quit") || (input == "look for key") || (input == "north") || (input == "south") || (input == "east") || (input == "west")))
            {
                cout << "Sorry, I did not understand you." << endl << endl;
                cout << "Which exit? (or 'quit', 'look for key', or 'unlock door'): ";
                getline(cin, input);
                cout << endl;
            }
*/
        }

        else if (input == "look for key")
        {
/*
            if (key is in current room (or possibly player is in garage, either or))
            {
                player has key
                cout << "You find the key nuzzled in the cracks of the passenger seat, alongside 3 quarters, 2 dimes, 6 pennies, and a bunch of crumbs. Looks like you can do laundry next week! But getting back to business now, it's time to get out of here!" << endl << endl;
            }
            else 
            {
                cout << "You tear down the whole room and look in every possible crevice, but fail to find the key. The key must be in some other room..." << endl << endl;
            }
*/
        }

        //A direction
        else if ((input != "quit") && (input != "look for key") && (input != "unlock door"))
        {
            while (current_room->getLinked(input)->getName() == "empty")
            {
                cout << "There is nothing there." << endl << endl;
                cout << "Enter a valid direction: ";
                getline(cin, input);
                cout << endl;
            }

            current_room = current_room->getLinked(input);
/*
            if (player has key)
            {
                key.current_room = current_room;
            }
*/
            if ((input == "north") || (input == "south") || (input == "east") || (input == "west"))
            {
                cout << "You move to the " << input << "..." << endl << endl;
            }
            else
            {
                cout << "You move " << input << "..." << endl << endl;
            }

        }

        else 
        {
            cout << "Game Quits." << endl << endl;
            return 1;
        }

    }

    return 0;
}
