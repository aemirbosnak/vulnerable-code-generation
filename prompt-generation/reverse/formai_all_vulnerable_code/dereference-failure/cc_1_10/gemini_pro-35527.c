//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define NUM_ROOMS 5
char* room_names[] = {"The Foyer", "The Kitchen", "The Dining Room", "The Living Room", "The Master Bedroom"};
char* room_descriptions[] = {
    "You are standing in the foyer of a large house. A grand staircase leads up to the second floor.",
    "You are in the kitchen. A large oven and stove take up one wall, and a refrigerator and sink take up the other.",
    "You are in the dining room. A large table with chairs surrounds a fireplace.",
    "You are in the living room. A large couch and armchair face a fireplace.",
    "You are in the master bedroom. A large bed takes up most of the room, and a dresser and wardrobe stand against the walls."
};
int room_connections[NUM_ROOMS][NUM_ROOMS] = {
    {1, 2, 3, 4, 0},
    {1, 0, 3, 0, 0},
    {1, 2, 0, 4, 0},
    {1, 2, 3, 0, 0},
    {1, 2, 3, 0, 0}
};

// Define the player's inventory
char* inventory[10];
int inventory_size = 0;

// Define the game state
int current_room = 0;
int game_over = 0;

// Function to display the current room
void display_room() {
    printf("You are in %s.\n", room_names[current_room]);
    printf("%s\n", room_descriptions[current_room]);
}

// Function to handle player input
void handle_input() {
    char input[100];
    printf("> ");
    fgets(input, 100, stdin);
    
    // Parse the input
    char* command = strtok(input, " ");
    char* argument = strtok(NULL, " ");
    
    // Execute the command
    if (strcmp(command, "go") == 0) {
        if (argument == NULL) {
            printf("Go where?\n");
        } else {
            int new_room = atoi(argument);
            if (new_room >= 0 && new_room < NUM_ROOMS && room_connections[current_room][new_room] == 1) {
                current_room = new_room;
                display_room();
            } else {
                printf("You can't go there.\n");
            }
        }
    } else if (strcmp(command, "examine") == 0) {
        if (argument == NULL) {
            printf("Examine what?\n");
        } else {
            printf("You examine the %s.\n", argument);
        }
    } else if (strcmp(command, "take") == 0) {
        if (argument == NULL) {
            printf("Take what?\n");
        } else {
            int i;
            for (i = 0; i < inventory_size; i++) {
                if (strcmp(inventory[i], argument) == 0) {
                    printf("You already have that item.\n");
                    return;
                }
            }
            if (inventory_size < 10) {
                inventory[inventory_size] = argument;
                inventory_size++;
                printf("You take the %s.\n", argument);
            } else {
                printf("Your inventory is full.\n");
            }
        }
    } else if (strcmp(command, "drop") == 0) {
        if (argument == NULL) {
            printf("Drop what?\n");
        } else {
            int i;
            for (i = 0; i < inventory_size; i++) {
                if (strcmp(inventory[i], argument) == 0) {
                    for (int j = i; j < inventory_size - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }
                    inventory_size--;
                    printf("You drop the %s.\n", argument);
                    return;
                }
            }
            printf("You don't have that item.\n");
        }
    } else if (strcmp(command, "quit") == 0) {
        game_over = 1;
    } else {
        printf("I don't understand that command.\n");
    }
}

// Main game loop
int main() {
    display_room();
    while (!game_over) {
        handle_input();
    }
    return 0;
}