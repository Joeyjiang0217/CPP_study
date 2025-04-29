/*
This is header file.

Study the structs that are defined in this file.
You will implement a doubly linked list (DLL) using these structs:
* Node data structure to store data within our DLL.
* Team data structure that is a doubly linked list.

The rest of this file is a list of functions that you will implement in my_dll.c.

Do NOT modify this file!
*/

#ifndef MYDLL_H
#define MYDLL_H

// The node data structure to store data within
// our DLL. In our case, we will store a hockey player in each player struct.
// num is the player's roster number; roster numbers are always greater than 0
// The longest player name ever in the NHL is 14 characters so far, so you can
// assume the longest name you'll have to deal with is 20 character long
// we are only using family names
typedef struct player {
    int rosterNum;
    char* name;
    struct player* next;
    struct player* previous;
} player_t;

// The Team data structure that is a doubly linked list
// Our Team DLL holds a pointer to the first player node in our Team dll called head,
// and a pointer to the last player node in our Team called tail.
// It also keeps count of how many active players we have on our Team
typedef struct Team {
    int activePlayers; // count keeps track of how many active players are on the Team.
    player_t* head;    // head points to the first player node in our DLL.
    player_t* tail;    //tail points to the last player node in our DLL.
} team_t;

/*
Below, the functions prototypes are provided. You will implement these functions in my_dll.c.
Do NOT modify the function prototypes.
*/

// Create a new Team
team_t* create_team();

// Check if the team is empty
int team_empty(team_t* l);

// Create a new player
player_t* makePlayer(int roster, char* name);

// Push a new player to the front of the DLL
int team_push_front(team_t* l, int roster, char* name);

// Push a new player to the end of the team DLL
int team_push_back(team_t* l, int roster, char* name);

// Pop a player from the front of the DLL
player_t* team_pop_front(team_t* t);

// Pop a player from the end of the DLL
player_t* team_pop_back(team_t* t);

// Get the player at position pos
int team_insert(team_t* t, int pos, int roster, char* name);

// Get the player at position pos
int team_list_get(team_t* t, int pos);

// Remove the player at position pos
player_t* team_list_remove(team_t* t, int pos);

// Get the number of players in the team
int team_size(team_t* t);

// OPTIONAL
void team_sort(team_t* t);

// Free the memory associated with the player
void free_team(team_t* t);

#endif
