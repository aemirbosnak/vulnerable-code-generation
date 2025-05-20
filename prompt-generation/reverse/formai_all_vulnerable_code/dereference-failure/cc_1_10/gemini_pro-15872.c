//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room structure
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Create a new room
Room* createRoom(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Connect two rooms
void connectRooms(Room* room1, Room* room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

// Print the description of a room
void printRoomDescription(Room* room) {
    printf("%s\n", room->description);
}

// Get the user's input
char* getInput() {
    char* input = malloc(256);
    fgets(input, 256, stdin);
    return input;
}

// Play the game
void playGame() {
    // Create the rooms
    Room* room1 = createRoom("Room 1", "This is room 1.");
    Room* room2 = createRoom("Room 2", "This is room 2.");
    Room* room3 = createRoom("Room 3", "This is room 3.");

    // Connect the rooms
    connectRooms(room1, room2, 'e');
    connectRooms(room2, room3, 'e');

    // Start the player in room 1
    Room* currentRoom = room1;

    // Game loop
    while (1) {
        // Print the description of the current room
        printRoomDescription(currentRoom);

        // Get the user's input
        char* input = getInput();

        // Check the user's input
        if (strcmp(input, "n\n") == 0) {
            if (currentRoom->north != NULL) {
                currentRoom = currentRoom->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "e\n") == 0) {
            if (currentRoom->east != NULL) {
                currentRoom = currentRoom->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "s\n") == 0) {
            if (currentRoom->south != NULL) {
                currentRoom = currentRoom->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "w\n") == 0) {
            if (currentRoom->west != NULL) {
                currentRoom = currentRoom->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "quit\n") == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    // Free the memory allocated for the rooms
    free(room1);
    free(room2);
    free(room3);
}

int main() {
    playGame();
    return 0;
}