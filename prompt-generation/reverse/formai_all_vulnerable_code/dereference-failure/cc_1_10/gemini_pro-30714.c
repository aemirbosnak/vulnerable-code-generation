//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define NUM_ROOMS 5
char *room_names[] = {"The Foyer", "The Living Room", "The Dining Room", "The Kitchen", "The Attic"};
char *room_descriptions[] = {
    "You are in the foyer of a large house. A grand staircase leads up to the second floor.",
    "You are in the living room of the house. There is a large fireplace and a comfortable couch.",
    "You are in the dining room of the house. There is a long table with chairs arranged around it.",
    "You are in the kitchen of the house. There is a stove, oven, and refrigerator.",
    "You are in the attic of the house. There are boxes and old furniture stored here."};

// Define the player's inventory
#define MAX_INVENTORY_SIZE 10
char *inventory[MAX_INVENTORY_SIZE];
int inventory_size = 0;

// Define the game's state
int current_room = 0;
int game_over = 0;

// Function to print the game's introduction
void print_introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a guest at a large house. You have been invited to explore the house and find a hidden treasure.\n");
    printf("To move around the house, type 'go' followed by the name of the room you want to go to.\n");
    printf("To examine an object, type 'examine' followed by the name of the object.\n");
    printf("To pick up an object, type 'pick up' followed by the name of the object.\n");
    printf("To drop an object, type 'drop' followed by the name of the object.\n");
    printf("To quit the game, type 'quit'.\n");
}

// Function to print the current room's description
void print_current_room_description() {
    printf("You are in %s.\n", room_names[current_room]);
    printf("%s\n", room_descriptions[current_room]);
}

// Function to handle the player's input
void handle_input() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Parse the input
    char *verb = strtok(input, " ");
    char *object = strtok(NULL, " ");

    // Execute the command
    if (strcmp(verb, "go") == 0) {
        // Move to the specified room
        int new_room = -1;
        for (int i = 0; i < NUM_ROOMS; i++) {
            if (strcmp(object, room_names[i]) == 0) {
                new_room = i;
                break;
            }
        }

        if (new_room != -1) {
            current_room = new_room;
            print_current_room_description();
        } else {
            printf("I don't know that room.\n");
        }
    } else if (strcmp(verb, "examine") == 0) {
        // Examine the specified object
        if (object == NULL) {
            printf("What do you want to examine?\n");
        } else {
            printf("You examine the %s.\n", object);
        }
    } else if (strcmp(verb, "pick up") == 0) {
        // Pick up the specified object
        if (object == NULL) {
            printf("What do you want to pick up?\n");
        } else {
            // Add the object to the player's inventory
            if (inventory_size < MAX_INVENTORY_SIZE) {
                inventory[inventory_size] = object;
                inventory_size++;
                printf("You pick up the %s.\n", object);
            } else {
                printf("Your inventory is full.\n");
            }
        }
    } else if (strcmp(verb, "drop") == 0) {
        // Drop the specified object
        if (object == NULL) {
            printf("What do you want to drop?\n");
        } else {
            // Remove the object from the player's inventory
            int index = -1;
            for (int i = 0; i < inventory_size; i++) {
                if (strcmp(object, inventory[i]) == 0) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                // Shift the remaining objects down to fill the gap
                for (int i = index; i < inventory_size - 1; i++) {
                    inventory[i] = inventory[i + 1];
                }

                // Decrement the inventory size
                inventory_size--;

                printf("You drop the %s.\n", object);
            } else {
                printf("You don't have that object.\n");
            }
        }
    } else if (strcmp(verb, "quit") == 0) {
        // Quit the game
        game_over = 1;
    } else {
        // Print an error message
        printf("I don't understand that command.\n");
    }
}

// Main game loop
int main() {
    // Print the game's introduction
    print_introduction();

    // Print the current room's description
    print_current_room_description();

    // Main game loop
    while (!game_over) {
        // Handle the player's input
        handle_input();
    }

    return 0;
}