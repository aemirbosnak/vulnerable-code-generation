//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room struct
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Player struct
typedef struct Player {
    char* name;
    int health;
    int sanity;
    Room* currentRoom;
} Player;

// Create a new room
Room* createRoom(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = name;
    room->description = description;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Create a new player
Player* createPlayer(char* name) {
    Player* player = malloc(sizeof(Player));
    player->name = name;
    player->health = 100;
    player->sanity = 100;
    player->currentRoom = NULL;
    return player;
}

// Set the north room of a room
void setNorthRoom(Room* room, Room* north) {
    room->north = north;
}

// Set the east room of a room
void setEastRoom(Room* room, Room* east) {
    room->east = east;
}

// Set the south room of a room
void setSouthRoom(Room* room, Room* south) {
    room->south = south;
}

// Set the west room of a room
void setWestRoom(Room* room, Room* west) {
    room->west = west;
}

// Set the current room of a player
void setPlayerCurrentRoom(Player* player, Room* room) {
    player->currentRoom = room;
}

// Get the name of a room
char* getRoomName(Room* room) {
    return room->name;
}

// Get the description of a room
char* getRoomDescription(Room* room) {
    return room->description;
}

// Get the north room of a room
Room* getRoomNorth(Room* room) {
    return room->north;
}

// Get the east room of a room
Room* getRoomEast(Room* room) {
    return room->east;
}

// Get the south room of a room
Room* getRoomSouth(Room* room) {
    return room->south;
}

// Get the west room of a room
Room* getRoomWest(Room* room) {
    return room->west;
}

// Get the current room of a player
Room* getPlayerCurrentRoom(Player* player) {
    return player->currentRoom;
}

// Get the name of a player
char* getPlayerName(Player* player) {
    return player->name;
}

// Get the health of a player
int getPlayerHealth(Player* player) {
    return player->health;
}

// Get the sanity of a player
int getPlayerSanity(Player* player) {
    return player->sanity;
}

// Print the description of a room
void printRoomDescription(Room* room) {
    printf("%s\n", getRoomDescription(room));
}

// Print the name of a room
void printRoomName(Room* room) {
    printf("%s\n", getRoomName(room));
}

// Print the name of the current room of a player
void printPlayerCurrentRoom(Player* player) {
    printf("%s\n", getRoomName(getPlayerCurrentRoom(player)));
}

// Print the health of a player
void printPlayerHealth(Player* player) {
    printf("Health: %d\n", getPlayerHealth(player));
}

// Print the sanity of a player
void printPlayerSanity(Player* player) {
    printf("Sanity: %d\n", getPlayerSanity(player));
}

// Move the player to a new room
void movePlayer(Player* player, Room* room) {
    setPlayerCurrentRoom(player, room);
}

// Take damage
void takeDamage(Player* player, int damage) {
    player->health -= damage;
}

// Lose sanity
void loseSanity(Player* player, int sanity) {
    player->sanity -= sanity;
}

// Main game loop
int main() {
    // Create the player
    Player* player = createPlayer("Player 1");

    // Create the rooms
    Room* livingRoom = createRoom("Living Room", "A dark and dusty room with a single window.");
    Room* kitchen = createRoom("Kitchen", "A small and cramped room with a sink, stove, and refrigerator.");
    Room* bedroom = createRoom("Bedroom", "A small and cozy room with a bed, dresser, and nightstand.");
    Room* bathroom = createRoom("Bathroom", "A small and windowless room with a toilet, sink, and bathtub.");
    Room* attic = createRoom("Attic", "A large and dusty room with a single window.");

    // Set the connections between the rooms
    setNorthRoom(livingRoom, kitchen);
    setEastRoom(livingRoom, bedroom);
    setSouthRoom(livingRoom, bathroom);
    setWestRoom(livingRoom, attic);

    setNorthRoom(kitchen, livingRoom);
    setEastRoom(kitchen, bedroom);

    setNorthRoom(bedroom, livingRoom);
    setEastRoom(bedroom, bathroom);

    setNorthRoom(bathroom, livingRoom);
    setWestRoom(bathroom, bedroom);

    setSouthRoom(attic, livingRoom);

    // Set the player's current room
    setPlayerCurrentRoom(player, livingRoom);

    // Print the welcome message
    printf("Welcome to the Haunted House Simulator!\n");

    // Main game loop
    while (player->health > 0 && player->sanity > 0) {
        // Print the current room description
        printRoomDescription(getPlayerCurrentRoom(player));

        // Get the player's input
        char input[256];
        printf("> ");
        fgets(input, 256, stdin);

        // Parse the player's input
        char command[256];
        char argument[256];
        sscanf(input, "%s %s", command, argument);

        // Execute the player's command
        if (strcmp(command, "go") == 0) {
            // Move the player to a new room
            if (strcmp(argument, "north") == 0) {
                movePlayer(player, getRoomNorth(getPlayerCurrentRoom(player)));
            } else if (strcmp(argument, "east") == 0) {
                movePlayer(player, getRoomEast(getPlayerCurrentRoom(player)));
            } else if (strcmp(argument, "south") == 0) {
                movePlayer(player, getRoomSouth(getPlayerCurrentRoom(player)));
            } else if (strcmp(argument, "west") == 0) {
                movePlayer(player, getRoomWest(getPlayerCurrentRoom(player)));
            } else {
                printf("Invalid direction.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            // Print the current room description
            printRoomDescription(getPlayerCurrentRoom(player));
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Print the game over message
    if (player->health <= 0) {
        printf("Game over! You died.\n");
    } else if (player->sanity <= 0) {
        printf("Game over! You went insane.\n");
    }

    return 0;
}