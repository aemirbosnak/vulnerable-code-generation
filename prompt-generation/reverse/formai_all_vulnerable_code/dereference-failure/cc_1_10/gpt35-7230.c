//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 20

// Room structure definition
typedef struct Room {
    char name[20];
    char description[100];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Function prototypes
void printRoom(Room* currentRoom);
void move(char* direction, Room** currentRoom);

int main() {
    // Creating rooms
    Room* livingRoom = (Room*) malloc(sizeof(Room));
    Room* kitchen = (Room*) malloc(sizeof(Room));
    Room* bedroom = (Room*) malloc(sizeof(Room));
    Room* bathroom = (Room*) malloc(sizeof(Room));

    // Setting up room details
    strcpy(livingRoom->name, "Living Room");
    strcpy(livingRoom->description, "You are in the living room. There is a sofa and a TV in front of you.");
    livingRoom->north = NULL;
    livingRoom->south = bedroom;
    livingRoom->east = kitchen;
    livingRoom->west = NULL;

    strcpy(kitchen->name, "Kitchen");
    strcpy(kitchen->description, "You are in the kitchen. There is a sink, a refrigerator, and a stove here.");
    kitchen->north = NULL;
    kitchen->south = bathroom;
    kitchen->east = NULL;
    kitchen->west = livingRoom;

    strcpy(bedroom->name, "Bedroom");
    strcpy(bedroom->description, "You are in the bedroom. There is a bed, a dresser, and a closet here.");
    bedroom->north = livingRoom;
    bedroom->south = NULL;
    bedroom->east = bathroom;
    bedroom->west = NULL;

    strcpy(bathroom->name, "Bathroom");
    strcpy(bathroom->description, "You are in the bathroom. There is a shower, a sink, and a toilet here.");
    bathroom->north = kitchen;
    bathroom->south = NULL;
    bathroom->east = NULL;
    bathroom->west = bedroom;

    // Starting the game in the living room
    Room* currentRoom = livingRoom;

    // Game loop
    while(true) {
        // Print current room and ask for user input
        printRoom(currentRoom);
        printf("What direction do you want to move in? (north, south, east, or west)\n");

        // Get user input
        char input[MAX_INPUT_LENGTH];
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        // Move to the next room based on user input
        move(input, &currentRoom);
    }

    return 0;
}

// Function definition to print a room's details
void printRoom(Room* currentRoom) {
    printf("You are in the %s.\n", currentRoom->name);
    printf("%s\n", currentRoom->description);
}

// Function definition to move to a new room based on user input
void move(char* direction, Room** currentRoom) {
    // Check if input is valid
    if(strcmp(direction, "north") != 0 && strcmp(direction, "south") != 0
        && strcmp(direction, "east") != 0 && strcmp(direction, "west") != 0) {

        printf("Invalid input. Please enter either 'north', 'south', 'east', or 'west'.\n");
        return; // Return without changing current room if input is invalid
    }

    // Move to the next room based on user input
    if(strcmp(direction, "north") == 0 && (*currentRoom)->north != NULL) {
        *currentRoom = (*currentRoom)->north;
    }
    else if(strcmp(direction, "south") == 0 && (*currentRoom)->south != NULL) {
        *currentRoom = (*currentRoom)->south;
    }
    else if(strcmp(direction, "east") == 0 && (*currentRoom)->east != NULL) {
        *currentRoom = (*currentRoom)->east;
    }
    else if(strcmp(direction, "west") == 0 && (*currentRoom)->west != NULL) {
        *currentRoom = (*currentRoom)->west;
    }
    else {
        printf("You cannot move in that direction.\n");
    }
}