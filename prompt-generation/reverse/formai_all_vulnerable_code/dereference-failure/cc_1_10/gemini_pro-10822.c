//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room data structure
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

// Player data structure
typedef struct player {
    char* name;
    struct room* current_room;
    int health;
} player;

// Create a new room
room* create_room(char* name, char* description) {
    room* r = malloc(sizeof(room));
    r->name = name;
    r->description = description;
    r->north = NULL;
    r->east = NULL;
    r->south = NULL;
    r->west = NULL;
    return r;
}

// Create a new player
player* create_player(char* name) {
    player* p = malloc(sizeof(player));
    p->name = name;
    p->current_room = NULL;
    p->health = 100;
    return p;
}

// Initialize the game world
void init_game(player* p, room* r) {
    // Create the rooms
    room* room1 = create_room("Room 1", "This is the first room.");
    room* room2 = create_room("Room 2", "This is the second room.");
    room* room3 = create_room("Room 3", "This is the third room.");

    // Link the rooms together
    room1->north = room2;
    room1->east = room3;
    room2->south = room1;
    room3->west = room1;

    // Set the player's starting room
    p->current_room = room1;
}

// Print the current room's description
void look(player* p) {
    printf("%s\n", p->current_room->description);
}

// Move the player in a given direction
void move(player* p, char* direction) {
    if (strcmp(direction, "north") == 0) {
        if (p->current_room->north != NULL) {
            p->current_room = p->current_room->north;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(direction, "east") == 0) {
        if (p->current_room->east != NULL) {
            p->current_room = p->current_room->east;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(direction, "south") == 0) {
        if (p->current_room->south != NULL) {
            p->current_room = p->current_room->south;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(direction, "west") == 0) {
        if (p->current_room->west != NULL) {
            p->current_room = p->current_room->west;
        } else {
            printf("You cannot go that way.\n");
        }
    } else {
        printf("Invalid direction.\n");
    }
}

// Quit the game
void quit(player* p) {
    printf("Goodbye, %s.\n", p->name);
    exit(0);
}

// Main game loop
int main() {
    // Create the player
    player* p = create_player("John");

    // Initialize the game world
    init_game(p, NULL);

    // Main game loop
    while (1) {
        // Print the current room's description
        look(p);

        // Get the player's input
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);

        // Parse the input
        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");

        // Execute the command
        if (strcmp(command, "look") == 0) {
            look(p);
        } else if (strcmp(command, "move") == 0) {
            move(p, argument);
        } else if (strcmp(command, "quit") == 0) {
            quit(p);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}