//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constant values
#define MAX_INPUT_LENGTH 100
#define MAX_ROOMS 10
#define MAX_ITEMS 3

// Structure for a room
typedef struct {
    char* name;
    char* description;
    int north;
    int south;
    int east;
    int west;
} Room;

// Structure for an item
typedef struct {
    char* name;
    char* description;
    int room;
} Item;

// Define the rooms
Room rooms[MAX_ROOMS] = {
    {"Outside", "You are standing outside a mysterious house.", 1, -1, -1, -1},
    {"Foyer", "You are standing in the foyer of the house.", 2, 0, -1, -1},
    {"Kitchen", "You are standing in the kitchen of the house.", -1, -1, 1, -1},
    {"Living Room", "You are standing in the living room of the house.", 3, 1, -1, 0},
    {"Bedroom", "You are standing in the bedroom of the house.", -1, -1, -1, 3},
    {"Bathroom", "You are standing in the bathroom of the house.", -1, 3, -1, -1}
};

// Define the items
Item items[MAX_ITEMS] = {
    {"Key", "A small key.", 0},
    {"Map", "A map of the house.", 2},
    {"Potion", "A mysterious potion.", 5}
};

// Function to get input from the user
char* getInput() {
    char* input = (char*)malloc(MAX_INPUT_LENGTH * sizeof(char));
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input)-1] = '\0';
    return input;
}

// Function to print room description
void printRoomDesc(int roomNum) {
    printf("%s\n", rooms[roomNum].description);
    
    // Print items in the room
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].room == roomNum) {
            printf("There is a %s here.\n", items[i].name);
        }
    }
}

// Function to move the player
void movePlayer(int* roomNum, char* direction) {
    if (strcmp(direction, "north") == 0 && rooms[*roomNum].north != -1) {
        *roomNum = rooms[*roomNum].north;
        printf("You move north.\n");
    } else if (strcmp(direction, "south") == 0 && rooms[*roomNum].south != -1) {
        *roomNum = rooms[*roomNum].south;
        printf("You move south.\n");
    } else if (strcmp(direction, "east") == 0 && rooms[*roomNum].east != -1) {
        *roomNum = rooms[*roomNum].east;
        printf("You move east.\n");
    } else if (strcmp(direction, "west") == 0 && rooms[*roomNum].west != -1) {
        *roomNum = rooms[*roomNum].west;
        printf("You move west.\n");
    } else {
        printf("You cannot move that way.\n");
    }
}

// Function to pick up an item
void pickUpItem(int* roomNum, char* itemName) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(itemName, items[i].name) == 0 && items[i].room == *roomNum) {
            printf("You pick up the %s.\n", items[i].name);
            items[i].room = -1;
            return;
        }
    }
    printf("There is no %s to pick up.\n", itemName);
}

int main() {
    int currentRoom = 0;
    char* input;
    printf("Welcome to the house adventure game!\n");
    printRoomDesc(currentRoom);
    
    // Loop for game control
    while (1) {
        printf("What would you like to do?\n");
        input = getInput();
        if (strcmp(input, "quit") == 0) { // Quit the game
            printf("Quitting game.\n");
            break;
        } else if (strcmp(input, "look") == 0) { // Look at current room
            printRoomDesc(currentRoom);
        } else if (strcmp(input, "map") == 0) { // Look at house map
            printf("Map of the house:\n");
            int i;
            for (i = 0; i < MAX_ROOMS; i++) {
                printf("%d: %s\n", i, rooms[i].name);
            }
        } else if (strncmp(input, "go ", 3) == 0) { // Move the player
            movePlayer(&currentRoom, input+3);
            printRoomDesc(currentRoom);
        } else if (strncmp(input, "pick up ", 8) == 0) { // Pick up an item
            pickUpItem(&currentRoom, input+8);
            printRoomDesc(currentRoom);
        } else { // Unknown command
            printf("Unknown command: %s.\n", input);
        }
        free(input);
    }
    return 0;
}