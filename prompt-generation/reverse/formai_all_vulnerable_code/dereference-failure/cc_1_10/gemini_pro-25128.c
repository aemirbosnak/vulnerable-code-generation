//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the struct for a room
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

// Define the struct for a player
typedef struct player {
    int health;
    int energy;
    int sanity;
    room* currentRoom;
} player;

// Define the function to create a new room
room* createRoom(char* name, char* description) {
    room* newRoom = (room*)malloc(sizeof(room));
    newRoom->name = name;
    newRoom->description = description;
    newRoom->north = NULL;
    newRoom->east = NULL;
    newRoom->south = NULL;
    newRoom->west = NULL;
    return newRoom;
}

// Define the function to create a new player
player* createPlayer(room* startingRoom) {
    player* newPlayer = (player*)malloc(sizeof(player));
    newPlayer->health = 100;
    newPlayer->energy = 100;
    newPlayer->sanity = 100;
    newPlayer->currentRoom = startingRoom;
    return newPlayer;
}

// Define the function to print the description of a room
void printRoomDescription(room* room) {
    printf("%s\n", room->description);
}

// Define the function to move the player in a given direction
void movePlayer(player* player, char* direction) {
    if (strcmp(direction, "north") == 0) {
        if (player->currentRoom->north != NULL) {
            player->currentRoom = player->currentRoom->north;
        } else {
            printf("You can't go north from here.\n");
        }
    } else if (strcmp(direction, "east") == 0) {
        if (player->currentRoom->east != NULL) {
            player->currentRoom = player->currentRoom->east;
        } else {
            printf("You can't go east from here.\n");
        }
    } else if (strcmp(direction, "south") == 0) {
        if (player->currentRoom->south != NULL) {
            player->currentRoom = player->currentRoom->south;
        } else {
            printf("You can't go south from here.\n");
        }
    } else if (strcmp(direction, "west") == 0) {
        if (player->currentRoom->west != NULL) {
            player->currentRoom = player->currentRoom->west;
        } else {
            printf("You can't go west from here.\n");
        }
    } else {
        printf("Invalid direction.\n");
    }
}

// Define the function to handle the player's input
void handlePlayerInput(player* player) {
    char input[256];
    printf("> ");
    fgets(input, 256, stdin);

    // Parse the input
    char* command = strtok(input, " ");
    char* argument = strtok(NULL, " ");

    // Execute the command
    if (strcmp(command, "quit") == 0) {
        exit(0);
    } else if (strcmp(command, "look") == 0) {
        printRoomDescription(player->currentRoom);
    } else if (strcmp(command, "move") == 0) {
        movePlayer(player, argument);
    } else {
        printf("Invalid command.\n");
    }
}

// Define the main function
int main() {
    // Create the rooms
    room* room1 = createRoom("The Foyer", "You enter a dimly lit foyer. The air is thick with the smell of dust and decay. A single light bulb flickers overhead, casting eerie shadows on the walls.");
    room* room2 = createRoom("The Living Room", "You enter a spacious living room. The furniture is covered in sheets, and the walls are lined with dusty portraits. A fireplace sits in the corner, but the fire has long since gone out.");
    room* room3 = createRoom("The Dining Room", "You enter a formal dining room. The table is set for a feast, but the food has long since rotted. The walls are covered in bloodstains, and the air is thick with the smell of death.");
    room* room4 = createRoom("The Master Bedroom", "You enter a large master bedroom. The bed is unmade, and the sheets are stained with blood. A dresser stands in the corner, its drawers hanging open.");
    room* room5 = createRoom("The Attic", "You climb a narrow staircase to the attic. The air is cold and damp, and the walls are covered in cobwebs. A single window lets in a dim light, revealing piles of old boxes and forgotten treasures.");

    // Connect the rooms
    room1->north = room2;
    room2->east = room3;
    room3->south = room4;
    room4->west = room5;

    // Create the player
    player* player = createPlayer(room1);

    // Handle the player's input
    while (1) {
        handlePlayerInput(player);
    }

    return 0;
}