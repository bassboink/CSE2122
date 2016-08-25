/* File: homework-3.cpp
   Created by: Mitchell Wendt
   Created on: 6/10/16
   Synopsis: This program simulates Conway's game of life. The game grid starts out with text that writes out "GAME OF LIFE" and then proceeds with the following rules of Conway's Game of Life: All living cells die unless they have 2 or 3 neighbor cells, and Dead cells become alive again when there are exactly 3 neighbor cells
*/

#include<iostream>
#include<vector>
#include<unistd.h>
#include<cstdlib>
using namespace std;

//Rows and Columns of the game grid (wraps around)
#define ROWS 40
#define COLS 80

//Characters that indicate dead and alive cells
#define DEAD  '.'
#define ALIVE '@'

//Function Prototypes
void generation(vector< vector<char> > &world, vector< vector<char> > &world_copy);
void display(vector< vector<char> > &world);
int numNeighbors(vector< vector<char> > &world_copy, int i, int j);

int main()
{
    //Matrix that stores the current generation of cells
    vector< vector<char> > world(ROWS, vector<char>(COLS, DEAD));

    //Matrix that stores the previous generation of cells that is used to determine the number of neighbor cells
    vector< vector<char> > copy(ROWS, vector<char>(COLS, DEAD));

    // set some cells of world to ALIVE for initial configuration (Write "GAME OF LIFE")

    //G
    world[3][3] = ALIVE;
    world[3][4] = ALIVE;
    world[3][5] = ALIVE;
    world[3][6] = ALIVE;
    world[3][7] = ALIVE;
    world[4][3] = ALIVE;
    world[5][3] = ALIVE;
    world[6][3] = ALIVE;
    world[7][3] = ALIVE;
    world[7][4] = ALIVE;
    world[7][5] = ALIVE;
    world[7][6] = ALIVE;
    world[7][7] = ALIVE;
    world[6][7] = ALIVE;
    world[5][7] = ALIVE;
    world[5][6] = ALIVE;
    world[5][5] = ALIVE;

    //A
    world[3][9] = ALIVE;
    world[3][10] = ALIVE;
    world[3][11] = ALIVE;
    world[3][12] = ALIVE;
    world[3][13] = ALIVE;
    world[4][9] = ALIVE;
    world[5][9] = ALIVE;
    world[6][9] = ALIVE;
    world[7][9] = ALIVE;
    world[4][13] = ALIVE;
    world[5][13] = ALIVE;
    world[6][13] = ALIVE;
    world[7][13] = ALIVE;
    world[5][10] = ALIVE;
    world[5][11] = ALIVE;
    world[5][12] = ALIVE;

    //M
    world[3][15] = ALIVE;
    world[4][15] = ALIVE;
    world[5][15] = ALIVE;
    world[6][15] = ALIVE;
    world[7][15] = ALIVE;
    world[3][19] = ALIVE;
    world[4][19] = ALIVE;
    world[5][19] = ALIVE;
    world[6][19] = ALIVE;
    world[7][19] = ALIVE;
    world[4][16] = ALIVE;
    world[5][17] = ALIVE;
    world[4][18] = ALIVE;

    //E
    world[3][21] = ALIVE;
    world[4][21] = ALIVE;
    world[5][21] = ALIVE;
    world[6][21] = ALIVE;
    world[7][21] = ALIVE;
    world[3][22] = ALIVE;
    world[3][23] = ALIVE;
    world[3][24] = ALIVE;
    world[3][25] = ALIVE;
    world[5][22] = ALIVE;
    world[5][23] = ALIVE;
    world[5][24] = ALIVE;
    world[5][25] = ALIVE;
    world[7][22] = ALIVE;
    world[7][23] = ALIVE;
    world[7][24] = ALIVE;
    world[7][25] = ALIVE;

    //O
    world[3][32] = ALIVE;
    world[3][33] = ALIVE;
    world[3][34] = ALIVE;
    world[3][35] = ALIVE;
    world[3][36] = ALIVE;
    world[4][36] = ALIVE;
    world[5][36] = ALIVE;
    world[6][36] = ALIVE;
    world[7][36] = ALIVE;
    world[7][35] = ALIVE;
    world[7][34] = ALIVE;
    world[7][33] = ALIVE;
    world[7][32] = ALIVE;
    world[6][32] = ALIVE;
    world[5][32] = ALIVE;
    world[4][32] = ALIVE;

    //F
    world[3][38] = ALIVE;
    world[4][38] = ALIVE;
    world[5][38] = ALIVE;
    world[6][38] = ALIVE;
    world[7][38] = ALIVE;
    world[3][39] = ALIVE;
    world[3][40] = ALIVE;
    world[3][41] = ALIVE;
    world[3][42] = ALIVE;
    world[5][39] = ALIVE;
    world[5][40] = ALIVE;
    world[5][41] = ALIVE;
    world[5][42] = ALIVE;

    //L
    world[3][48] = ALIVE;
    world[4][48] = ALIVE;
    world[5][48] = ALIVE;
    world[6][48] = ALIVE;
    world[7][48] = ALIVE;
    world[7][49] = ALIVE;
    world[7][50] = ALIVE;
    world[7][51] = ALIVE;
    world[7][52] = ALIVE;

    //I
    world[3][54] = ALIVE;
    world[3][55] = ALIVE;
    world[3][56] = ALIVE;
    world[3][57] = ALIVE;
    world[3][58] = ALIVE;
    world[7][54] = ALIVE;
    world[7][55] = ALIVE;
    world[7][56] = ALIVE;
    world[7][57] = ALIVE;
    world[7][58] = ALIVE;
    world[4][56] = ALIVE;
    world[5][56] = ALIVE;
    world[6][56] = ALIVE;

    //F
    world[3][60] = ALIVE;
    world[3][61] = ALIVE;
    world[3][62] = ALIVE;
    world[3][63] = ALIVE;
    world[3][64] = ALIVE;
    world[4][60] = ALIVE;
    world[5][60] = ALIVE;
    world[6][60] = ALIVE;
    world[7][60] = ALIVE;
    world[5][61] = ALIVE;
    world[5][62] = ALIVE;
    world[5][63] = ALIVE;
    world[5][64] = ALIVE;

    //E
    world[3][66] = ALIVE;
    world[4][66] = ALIVE;
    world[5][66] = ALIVE;
    world[6][66] = ALIVE;
    world[7][66] = ALIVE;
    world[3][67] = ALIVE;
    world[3][68] = ALIVE;
    world[3][69] = ALIVE;
    world[3][70] = ALIVE;
    world[5][67] = ALIVE;
    world[5][68] = ALIVE;
    world[5][69] = ALIVE;
    world[5][70] = ALIVE;
    world[7][67] = ALIVE;
    world[7][68] = ALIVE;
    world[7][69] = ALIVE;
    world[7][70] = ALIVE;

    //Underline "GAME OF LIFE" with a bunch of blinkers, because why not?
    for (int i = 1; i < 76; i++) {
       if (i % 4 != 0) {
           world[30][i] = ALIVE;
       }
    }

    //Make a gilder, becuase they're cool
    world[15][3] = ALIVE;
    world[16][4] = ALIVE;
    world[16][5] = ALIVE;
    world[15][5] = ALIVE;
    world[14][5] = ALIVE;

    //Execute the game
    while(true)
    {
        // clear the screen and display the world
        system("clear");
        display(world);

        // wait for some time
        usleep(300000);

        // update the world
        generation(world, copy);

        // update copy of world for next generation
        copy = world;
    }
    return 0;
}

//This function determines which cells die and which cells are alive in the nex generation
//world is the matrix of the next generation, which is generated after the function is completed
//world_copy is a copy of the previous generation which is used in determining neighbor cells
void generation(vector< vector<char> > &world, vector< vector<char> > &world_copy)
{
    //This loop iterates through each row, indicated by i - 1  
    for(int i = 0; i < ROWS; i++) {

        //This loop iterates through each row, indicated by j - 1
        for(int j = 0; j < COLS; j++) {

            //look at world_copy[i][j]'s neighbors and count ones that are alive

            //Neighbors indicates the number of neighbor cells for each cell
            int Neighbors = numNeighbors(world_copy, i, j);

            //update world[i][j] based on it

            //ALIVE cells
            if (world_copy[i][j] == ALIVE) {
                if (Neighbors < 2) {
                    world[i][j] = DEAD;
                }
                else if (Neighbors > 3) {
                    world[i][j] = DEAD;
                }
            }

            //DEAD cells
            else {
                if (Neighbors == 3) {
                    world[i][j] = ALIVE;
                }
            }
        }
    }
}


//This function displays the current world on the terminal display
//world is the matrix of the world
void display(vector< vector<char> > &world)
{
    // display the 2D matrix

    //This loop iterates through each row, indicated by i - 1
    for(int i = 0; i < ROWS; i++) {

        //This loop iterates through each column, indicated by j - 1
        for(int j = 0; j < COLS; j++) {
            cout << world[i][j];
        }

        cout << endl;
    }
}

//This function calculates the number of neighbor cells a given cell has
//world_copy is the copy of the world from the previous generation
//i is the row number of the cell
//j is the column number of the cell
int numNeighbors(vector< vector<char> > &world_copy, int i, int j)
{
    //Neighbors is the number of neighbor cells the cell has
    int Neighbors = 0;

    //NOTE: Edges will "wrap around", creating an essentially infinite field

    //Check corners first

    //Top Left
    if (i == 0 && j == 0) {
        if (world_copy[ROWS-1][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    //Top Right
    else if (i == 0 && j == COLS-1) {
        if (world_copy[ROWS-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][0] == ALIVE) {
            Neighbors++;
        }
    }

    //Bottom Left
    else if (i == ROWS-1 && j == 0) {
        if (world_copy[i-1][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    //Bottom Right
    else if (i == ROWS-1 && j == COLS-1) {
        if (world_copy[i-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][0] == ALIVE) {
            Neighbors++;
        }
    }

    //Now check the edges

    //Top
    else if (i == 0) {
        if (world_copy[ROWS-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[ROWS-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    //Left
    else if (j == 0) {
        if (world_copy[i-1][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][COLS-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    //Right
    else if (j == COLS-1) {
        if (world_copy[i-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][0] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][0] == ALIVE) {
            Neighbors++;
        }
    }

    //Bottom
    else if (i == ROWS-1) {
        if (world_copy[i-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[0][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    //Finally, check the interior points
    else {
        if (world_copy[i-1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i-1][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i][j+1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j-1] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j] == ALIVE) {
            Neighbors++;
        }
        if (world_copy[i+1][j+1] == ALIVE) {
            Neighbors++;
        }
    }

    return Neighbors;
}

