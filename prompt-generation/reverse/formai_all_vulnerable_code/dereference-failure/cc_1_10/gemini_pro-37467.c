//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a room
typedef struct {
    char* name;
    char* description;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Variables for the game
Room* currentRoom;
char* inventory[100];
int numInventoryItems = 0;

// Function to create a new room
Room* createRoom(char* name, char* description) {
    Room* room = (Room*)malloc(sizeof(Room));
    room->name = (char*)malloc(strlen(name) + 1);
    strcpy(room->name, name);
    room->description = (char*)malloc(strlen(description) + 1);
    strcpy(room->description, description);
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Function to add a new room to the game
void addRoom(Room* room) {
    if (currentRoom == NULL) {
        currentRoom = room;
    } else {
        currentRoom->north = room;
    }
}

// Function to get the current room
Room* getCurrentRoom() {
    return currentRoom;
}

// Function to move the player to a new room
void movePlayer(char* direction) {
    if (strcmp(direction, "north") == 0) {
        currentRoom = currentRoom->north;
    } else if (strcmp(direction, "east") == 0) {
        currentRoom = currentRoom->east;
    } else if (strcmp(direction, "south") == 0) {
        currentRoom = currentRoom->south;
    } else if (strcmp(direction, "west") == 0) {
        currentRoom = currentRoom->west;
    }
}

// Function to add an item to the player's inventory
void addItem(char* item) {
    inventory[numInventoryItems++] = (char*)malloc(strlen(item) + 1);
    strcpy(inventory[numInventoryItems - 1], item);
}

// Function to print the current room
void printRoom() {
    printf("%s\n", currentRoom->name);
    printf("%s\n", currentRoom->description);
}

// Function to print the player's inventory
void printInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < numInventoryItems; i++) {
        printf("%s\n", inventory[i]);
    }
}

// Main function
int main() {
    // Create the rooms
    Room* room1 = createRoom("Room 1", "This is the first room.");
    Room* room2 = createRoom("Room 2", "This is the second room.");
    Room* room3 = createRoom("Room 3", "This is the third room.");
    Room* room4 = createRoom("Room 4", "This is the fourth room.");

    // Add the rooms to the game
    addRoom(room1);
    addRoom(room2);
    addRoom(room3);
    addRoom(room4);

    // Set the current room to the first room
    currentRoom = room1;

    // Print the welcome message
    printf("Welcome to the text-based adventure game!\n");

    // Game loop
    while (1) {
        // Print the current room
        printRoom();

        // Get the player's input
        char input[100];
        printf("> ");
        scanf("%s", input);

        // Parse the player's input
        if (strcmp(input, "north") == 0) {
            movePlayer("north");
        } else if (strcmp(input, "east") == 0) {
            movePlayer("east");
        } else if (strcmp(input, "south") == 0) {
            movePlayer("south");
        } else if (strcmp(input, "west") == 0) {
            movePlayer("west");
        } else if (strcmp(input, "inventory") == 0) {
            printInventory();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    // Print the goodbye message
    printf("Goodbye!\n");

    return 0;
}