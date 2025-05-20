//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare variables
    char *name;
    char *room;
    char *direction;
    char *exit;

    // Initialize variables
    name = (char *)malloc(50 * sizeof(char));
    room = (char *)malloc(50 * sizeof(char));
    direction = (char *)malloc(50 * sizeof(char));
    exit = (char *)malloc(50 * sizeof(char));

    // Set up rooms
    strcpy(room, "You are standing in an empty room.");
    strcpy(exit, "There is a door to the north.");

    // Set up direction
    direction = "n";

    // Main game loop
    while (1) {
        // Print current room
        printf("%s\n", room);

        // Get user input
        fgets(name, 50, stdin);

        // Check if user input is "quit"
        if (strcmp(name, "quit") == 0) {
            break;
        }

        // Check if user input is a valid direction
        if (strlen(name) > 0 &&!isalpha(name[0])) {
            printf("Invalid direction.\n");
            continue;
        }

        // Check if user input is a valid direction
        if (strcmp(name, "n") == 0) {
            if (strcmp(exit, "There is a door to the south.") == 0) {
                strcpy(room, "You are standing in a small room.");
                strcpy(exit, "There is a door to the north.");
            }
            else if (strcmp(exit, "There is a door to the east.") == 0) {
                strcpy(room, "You are standing in a hallway.");
                strcpy(exit, "There is a door to the south.");
            }
            else if (strcmp(exit, "There is a door to the west.") == 0) {
                strcpy(room, "You are standing in a large room.");
                strcpy(exit, "There is a door to the south.");
            }
            else {
                printf("You cannot go that way.\n");
                continue;
            }
        }
        else if (strcmp(name, "s") == 0) {
            if (strcmp(exit, "There is a door to the north.") == 0) {
                strcpy(room, "You are standing in a small room.");
                strcpy(exit, "There is a door to the south.");
            }
            else if (strcmp(exit, "There is a door to the east.") == 0) {
                strcpy(room, "You are standing in a hallway.");
                strcpy(exit, "There is a door to the north.");
            }
            else if (strcmp(exit, "There is a door to the west.") == 0) {
                strcpy(room, "You are standing in a large room.");
                strcpy(exit, "There is a door to the north.");
            }
            else {
                printf("You cannot go that way.\n");
                continue;
            }
        }
        else if (strcmp(name, "e") == 0) {
            if (strcmp(exit, "There is a door to the north.") == 0) {
                strcpy(room, "You are standing in a small room.");
                strcpy(exit, "There is a door to the south.");
            }
            else if (strcmp(exit, "There is a door to the south.") == 0) {
                strcpy(room, "You are standing in a hallway.");
                strcpy(exit, "There is a door to the north.");
            }
            else if (strcmp(exit, "There is a door to the west.") == 0) {
                strcpy(room, "You are standing in a large room.");
                strcpy(exit, "There is a door to the north.");
            }
            else {
                printf("You cannot go that way.\n");
                continue;
            }
        }
        else if (strcmp(name, "w") == 0) {
            if (strcmp(exit, "There is a door to the north.") == 0) {
                strcpy(room, "You are standing in a small room.");
                strcpy(exit, "There is a door to the south.");
            }
            else if (strcmp(exit, "There is a door to the south.") == 0) {
                strcpy(room, "You are standing in a hallway.");
                strcpy(exit, "There is a door to the north.");
            }
            else if (strcmp(exit, "There is a door to the east.") == 0) {
                strcpy(room, "You are standing in a large room.");
                strcpy(exit, "There is a door to the north.");
            }
            else {
                printf("You cannot go that way.\n");
                continue;
            }
        }
        else {
            printf("Invalid direction.\n");
            continue;
        }

        // Print new room
        printf("%s\n", room);

        // Print exit
        printf("You see a %s to the %s.\n", exit, direction);

        // Get user input for next direction
        fgets(name, 50, stdin);

        // Check if user input is "quit"
        if (strcmp(name, "quit") == 0) {
            break;
        }

        // Check if user input is a valid direction
        if (strlen(name) > 0 &&!isalpha(name[0])) {
            printf("Invalid direction.\n");
            continue;
        }

        // Check if user input is a valid direction
        if (strcmp(name, "n") == 0) {
            direction = "n";
        }
        else if (strcmp(name, "s") == 0) {
            direction = "s";
        }
        else if (strcmp(name, "e") == 0) {
            direction = "e";
        }
        else if (strcmp(name, "w") == 0) {
            direction = "w";
        }
        else {
            printf("Invalid direction.\n");
            continue;
        }

        // Print new room
        printf("%s\n", room);

        // Print exit
        printf("You see a %s to the %s.\n", exit, direction);
    }

    // Free memory
    free(name);
    free(room);
    free(direction);
    free(exit);

    return 0;
}