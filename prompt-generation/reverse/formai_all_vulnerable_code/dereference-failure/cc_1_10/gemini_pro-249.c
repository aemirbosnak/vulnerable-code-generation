//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room struct
typedef struct Room {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

// Player struct
typedef struct Player {
    char *name;
    int health;
    Room *currentRoom;
} Player;

// Item struct
typedef struct Item {
    char *name;
    char *description;
} Item;

// Create a new room
Room *createRoom(char *name, char *description) {
    Room *room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

// Create a new player
Player *createPlayer(char *name) {
    Player *player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->health = 100;
    player->currentRoom = NULL;
    return player;
}

// Create a new item
Item *createItem(char *name, char *description) {
    Item *item = malloc(sizeof(Item));
    item->name = strdup(name);
    item->description = strdup(description);
    return item;
}

// Print the room description
void printRoomDescription(Room *room) {
    printf("%s\n", room->description);
    printf("Exits: ");
    if (room->north) printf("north ");
    if (room->south) printf("south ");
    if (room->east) printf("east ");
    if (room->west) printf("west ");
    printf("\n");
}

// Print the player's stats
void printPlayerStats(Player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Current Room: %s\n", player->currentRoom->name);
}

// Get the player's input
char *getPlayerInput() {
    char *input = malloc(1024);
    fgets(input, 1024, stdin);
    input[strlen(input) - 1] = '\0';
    return input;
}

// Parse the player's input
void parsePlayerInput(char *input, Player *player) {
    char *verb = strtok(input, " ");
    char *noun = strtok(NULL, " ");

    if (!strcmp(verb, "go")) {
        if (!strcmp(noun, "north") && player->currentRoom->north) {
            player->currentRoom = player->currentRoom->north;
        } else if (!strcmp(noun, "south") && player->currentRoom->south) {
            player->currentRoom = player->currentRoom->south;
        } else if (!strcmp(noun, "east") && player->currentRoom->east) {
            player->currentRoom = player->currentRoom->east;
        } else if (!strcmp(noun, "west") && player->currentRoom->west) {
            player->currentRoom = player->currentRoom->west;
        } else {
            printf("Invalid direction.\n");
        }
    } else if (!strcmp(verb, "look")) {
        printRoomDescription(player->currentRoom);
    } else if (!strcmp(verb, "quit")) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    // Create the rooms
    Room *room1 = createRoom("The Foyer", "A large, open room with a grand staircase.");
    Room *room2 = createRoom("The Living Room", "A cozy room with a fireplace and comfortable chairs.");
    Room *room3 = createRoom("The Dining Room", "A large room with a long table and chairs.");
    Room *room4 = createRoom("The Kitchen", "A small room with a stove, oven, and refrigerator.");
    Room *room5 = createRoom("The Master Bedroom", "A large room with a king-size bed and a dresser.");
    Room *room6 = createRoom("The Guest Bedroom", "A small room with a twin bed and a dresser.");
    Room *room7 = createRoom("The Bathroom", "A small room with a toilet, sink, and shower.");

    // Connect the rooms
    room1->north = room2;
    room1->south = room3;
    room1->east = room4;
    room1->west = room5;
    room2->south = room1;
    room3->north = room1;
    room3->east = room6;
    room3->west = room7;
    room4->west = room1;
    room5->east = room1;
    room6->west = room3;
    room7->east = room3;

    // Create the player
    Player *player = createPlayer("John");
    player->currentRoom = room1;

    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are playing as %s.\n", player->name);
    printf("Your goal is to explore the house and find the hidden treasure.\n");

    // Game loop
    while (1) {
        // Print the room description
        printRoomDescription(player->currentRoom);

        // Get the player's input
        char *input = getPlayerInput();

        // Parse the player's input
        parsePlayerInput(input, player);
    }

    return 0;
}