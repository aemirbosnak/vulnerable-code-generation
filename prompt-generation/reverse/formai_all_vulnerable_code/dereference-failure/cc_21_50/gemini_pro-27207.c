//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define NUM_ROOMS 5
#define MAX_ROOM_NAME_LENGTH 20
#define MAX_ITEM_NAME_LENGTH 20

typedef struct {
    char name[MAX_ROOM_NAME_LENGTH];
    char description[256];
    int north;
    int east;
    int south;
    int west;
    int items[5];
} Room;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[64];
} Item;

// Define the player
typedef struct {
    int location;
    int inventory[5];
} Player;

// Create the game world
Room rooms[NUM_ROOMS] = {
    { "The Foyer", "You are standing in the foyer of a large house. There is a door to the north and a door to the east.", 1, 2, -1, -1, {} },
    { "The Living Room", "You are standing in the living room. There is a door to the south and a door to the west.", -1, -1, 0, 3, {} },
    { "The Dining Room", "You are standing in the dining room. There is a door to the north and a door to the east.", 0, 4, -1, -1, {} },
    { "The Kitchen", "You are standing in the kitchen. There is a door to the south and a door to the west.", -1, -1, 2, 0, {} },
    { "The Master Bedroom", "You are standing in the master bedroom. There is a door to the north and a door to the east.", 3, -1, -1, -1, {} }
};

Item items[5] = {
    { "Key", "A small, silver key." },
    { "Sword", "A sharp, steel sword." },
    { "Potion", "A healing potion." },
    { "Gold", "A bag of gold coins." },
    { "Map", "A map of the house." }
};

// Create the player
Player player = { 0, {} };

// Main game loop
int main() {
    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");

    // Game loop
    while (1) {
        // Print the current room
        printf("\nYou are in the %s.\n", rooms[player.location].name);
        printf("%s\n", rooms[player.location].description);

        // Print the exits
        if (rooms[player.location].north != -1) {
            printf("There is a door to the north.\n");
        }
        if (rooms[player.location].east != -1) {
            printf("There is a door to the east.\n");
        }
        if (rooms[player.location].south != -1) {
            printf("There is a door to the south.\n");
        }
        if (rooms[player.location].west != -1) {
            printf("There is a door to the west.\n");
        }

        // Print the items
        if (rooms[player.location].items[0] != -1) {
            printf("There is a %s here.\n", items[rooms[player.location].items[0]].name);
        }
        if (rooms[player.location].items[1] != -1) {
            printf("There is a %s here.\n", items[rooms[player.location].items[1]].name);
        }
        if (rooms[player.location].items[2] != -1) {
            printf("There is a %s here.\n", items[rooms[player.location].items[2]].name);
        }
        if (rooms[player.location].items[3] != -1) {
            printf("There is a %s here.\n", items[rooms[player.location].items[3]].name);
        }
        if (rooms[player.location].items[4] != -1) {
            printf("There is a %s here.\n", items[rooms[player.location].items[4]].name);
        }

        // Get the player's input
        char input[256];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the player's input
        char *command = strtok(input, " \n");
        char *argument = strtok(NULL, " \n");

        // Execute the player's command
        if (strcmp(command, "go") == 0) {
            if (strcmp(argument, "north") == 0) {
                if (rooms[player.location].north != -1) {
                    player.location = rooms[player.location].north;
                } else {
                    printf("You cannot go north.\n");
                }
            } else if (strcmp(argument, "east") == 0) {
                if (rooms[player.location].east != -1) {
                    player.location = rooms[player.location].east;
                } else {
                    printf("You cannot go east.\n");
                }
            } else if (strcmp(argument, "south") == 0) {
                if (rooms[player.location].south != -1) {
                    player.location = rooms[player.location].south;
                } else {
                    printf("You cannot go south.\n");
                }
            } else if (strcmp(argument, "west") == 0) {
                if (rooms[player.location].west != -1) {
                    player.location = rooms[player.location].west;
                } else {
                    printf("You cannot go west.\n");
                }
            }
        } else if (strcmp(command, "get") == 0) {
            int item_index = -1;
            for (int i = 0; i < 5; i++) {
                if (strcmp(argument, items[rooms[player.location].items[i]].name) == 0) {
                    item_index = i;
                    break;
                }
            }
            if (item_index != -1) {
                player.inventory[item_index] = rooms[player.location].items[item_index];
                rooms[player.location].items[item_index] = -1;
                printf("You got the %s.\n", items[item_index].name);
            } else {
                printf("There is no %s here.\n", argument);
            }
        } else if (strcmp(command, "inventory") == 0) {
            printf("You are carrying:\n");
            for (int i = 0; i < 5; i++) {
                if (player.inventory[i] != -1) {
                    printf(" - %s\n", items[player.inventory[i]].name);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            return 0;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}