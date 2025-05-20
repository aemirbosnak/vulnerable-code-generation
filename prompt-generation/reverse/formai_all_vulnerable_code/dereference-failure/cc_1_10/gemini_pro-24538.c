//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

// Structure to store room data
struct Room {
    char* description;
    int num_exits;
    int exits[MAX_ROOMS];
};

// Array of rooms
struct Room rooms[MAX_ROOMS];

// Current room index
int current_room = 0;

// Function to initialize the game world
void init_world() {
    // Create the first room
    rooms[0].description = "You are in a small, dark room. There is a door to the north.";
    rooms[0].num_exits = 1;
    rooms[0].exits[0] = 1;

    // Create the second room
    rooms[1].description = "You are in a larger room with two doors, one to the east and one to the south.";
    rooms[1].num_exits = 2;
    rooms[1].exits[0] = 2;
    rooms[1].exits[1] = 0;

    // Create the third room
    rooms[2].description = "You are in a small, windowless room. There is a door to the west.";
    rooms[2].num_exits = 1;
    rooms[2].exits[0] = 1;
}

// Function to print the current room description
void print_room() {
    printf("%s", rooms[current_room].description);
}

// Function to handle user input
void process_input() {
    char input[100];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse the user input
    char* command = strtok(input, " ");
    char* argument = strtok(NULL, " ");

    // Handle the command
    if (strcmp(command, "go") == 0) {
        if (argument == NULL) {
            printf("Go where?\n");
        } else {
            int direction;
            if (strcmp(argument, "north") == 0) {
                direction = 0;
            } else if (strcmp(argument, "east") == 0) {
                direction = 1;
            } else if (strcmp(argument, "south") == 0) {
                direction = 2;
            } else if (strcmp(argument, "west") == 0) {
                direction = 3;
            } else {
                printf("Invalid direction.\n");
                return;
            }

            // Check if the exit is valid
            if (direction < 0 || direction >= rooms[current_room].num_exits) {
                printf("There is no exit in that direction.\n");
                return;
            }

            // Move to the next room
            current_room = rooms[current_room].exits[direction];
            print_room();
        }
    } else if (strcmp(command, "look") == 0) {
        print_room();
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

// Main game loop
int main() {
    // Initialize the game world
    init_world();

    // Print the initial room description
    print_room();

    // Main game loop
    while (1) {
        process_input();
    }

    return 0;
}