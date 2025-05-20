//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new player
struct Player* createPlayer(char* name);

// Function to create a new room
struct Room* createRoom(char* name, char* description);

// Function to move player to another room
void movePlayer(struct Player* player, struct Room* room);

// Function to add connections between rooms
void addConnection(struct Room* room1, struct Room* room2);

// Function to display player's current room and available connections
void displayPlayerInfo(struct Player* player);

// Define Player struct
struct Player {
    char* name;
    struct Room* currentRoom;
};

// Define Room struct
struct Room {
    char* name;
    char* description;
    struct Room** connectedRooms;
    int numConnectedRooms;
};

int main() {
    // Create player
    struct Player* player = createPlayer("John");

    // Create rooms
    struct Room* room1 = createRoom("Room 1", "A small room with a door to the north.");
    struct Room* room2 = createRoom("Room 2", "A large room with a door to the south and west.");
    struct Room* room3 = createRoom("Room 3", "A dimly lit room with a door to the east.");

    // Add connections between rooms
    addConnection(room1, room2);
    addConnection(room2, room1);
    addConnection(room2, room3);
    addConnection(room3, room2);

    // Move player to room 1
    movePlayer(player, room1);

    // Game loop
    while (1) {
        // Display player info
        displayPlayerInfo(player);

        // Get user input
        char input[50];
        printf("\n> ");
        scanf("%s", input);

        // Handle user input
        if (strcmp(input, "north") == 0 && player->currentRoom->connectedRooms[0] != NULL) {
            movePlayer(player, player->currentRoom->connectedRooms[0]);
        } else if (strcmp(input, "south") == 0 && player->currentRoom->connectedRooms[1] != NULL) {
            movePlayer(player, player->currentRoom->connectedRooms[1]);
        } else if (strcmp(input, "west") == 0 && player->currentRoom->connectedRooms[2] != NULL) {
            movePlayer(player, player->currentRoom->connectedRooms[2]);
        } else if (strcmp(input, "east") == 0 && player->currentRoom->connectedRooms[3] != NULL) {
            movePlayer(player, player->currentRoom->connectedRooms[3]);
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

struct Player* createPlayer(char* name) {
    struct Player* player = malloc(sizeof(struct Player));
    player->name = name;
    player->currentRoom = NULL;
    return player;
}

struct Room* createRoom(char* name, char* description) {
    struct Room* room = malloc(sizeof(struct Room));
    room->name = name;
    room->description = description;
    room->connectedRooms = malloc(sizeof(struct Room*) * 4);
    for (int i = 0; i < 4; i++) {
        room->connectedRooms[i] = NULL;
    }
    room->numConnectedRooms = 0;
    return room;
}

void movePlayer(struct Player* player, struct Room* room) {
    player->currentRoom = room;
}

void addConnection(struct Room* room1, struct Room* room2) {
    for (int i = 0; i < 4; i++) {
        if (room1->connectedRooms[i] == NULL) {
            room1->connectedRooms[i] = room2;
            room1->numConnectedRooms++;
            break;
        }
    }
}

void displayPlayerInfo(struct Player* player) {
    printf("\nYou are in %s. %s\n", player->currentRoom->name, player->currentRoom->description);
    printf("You can go: ");
    for (int i = 0; i < 4; i++) {
        if (player->currentRoom->connectedRooms[i] != NULL) {
            if (i == 0) {
                printf("north ");
            } else if (i == 1) {
                printf("south ");
            } else if (i == 2) {
                printf("west ");
            } else if (i == 3) {
                printf("east ");
            }
        }
    }
    printf("\n");
}