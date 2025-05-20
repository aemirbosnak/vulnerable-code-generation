//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a room
typedef struct Room {
    char* description; // Description of the room
    struct Room* north; // Pointer to the north room
    struct Room* east;  // Pointer to the east room
    struct Room* south; // Pointer to the south room
    struct Room* west;  // Pointer to the west room
} Room;

// Structure to represent a player
typedef struct Player {
    char* name;        // Player's name
    Room* currentRoom; // Pointer to the current room the player is in
    int health;         // Player's health
} Player;

// Function to create a new room
Room* createRoom(char* description) {
    Room* room = malloc(sizeof(Room));
    room->description = strdup(description);
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Function to create a new player
Player* createPlayer(char* name, Room* startingRoom) {
    Player* player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->currentRoom = startingRoom;
    player->health = 100;
    return player;
}

// Function to print the description of the current room
void printRoomDescription(Player* player) {
    printf("%s\n", player->currentRoom->description);
}

// Function to move the player in a given direction
void movePlayer(Player* player, char direction) {
    switch (direction) {
        case 'n':
            if (player->currentRoom->north != NULL) {
                player->currentRoom = player->currentRoom->north;
            }
            break;
        case 'e':
            if (player->currentRoom->east != NULL) {
                player->currentRoom = player->currentRoom->east;
            }
            break;
        case 's':
            if (player->currentRoom->south != NULL) {
                player->currentRoom = player->currentRoom->south;
            }
            break;
        case 'w':
            if (player->currentRoom->west != NULL) {
                player->currentRoom = player->currentRoom->west;
            }
            break;
        default:
            printf("Invalid direction.\n");
    }
}

// Main function
int main() {
    // Create the rooms
    Room* room1 = createRoom("You are in the first room.");
    Room* room2 = createRoom("You are in the second room.");
    Room* room3 = createRoom("You are in the third room.");

    // Connect the rooms
    room1->north = room2;
    room2->south = room1;
    room2->east = room3;
    room3->west = room2;

    // Create the player
    Player* player = createPlayer("Player 1", room1);

    // Main game loop
    while (player->health > 0) {
        // Print the room description
        printRoomDescription(player);

        // Get the player's input
        char input[10];
        printf("> ");
        scanf("%s", input);

        // Check if the player wants to move
        if (strcmp(input, "n") == 0 || strcmp(input, "e") == 0 || strcmp(input, "s") == 0 || strcmp(input, "w") == 0) {
            movePlayer(player, input[0]);
        }

        // Check if the player wants to quit
        else if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    // Game over
    printf("Game over.\n");

    // Free the memory
    free(room1);
    free(room2);
    free(room3);
    free(player);

    return 0;
}