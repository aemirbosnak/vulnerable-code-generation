//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's struct
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Player;

// Define the room struct
typedef struct {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

// Create the player
Player *createPlayer(char *name) {
    Player *player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
    return player;
}

// Create a room
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

// Connect two rooms
void connectRooms(Room *room1, Room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

// Print the room description
void printRoomDescription(Room *room) {
    printf("%s\n", room->description);
}

// Get the player's input
char *getPlayerInput() {
    char *input = malloc(1024);
    fgets(input, 1024, stdin);
    return input;
}

// Process the player's input
void processPlayerInput(Player *player, Room *room) {
    char *input = getPlayerInput();
    if (strcmp(input, "n\n") == 0) {
        if (room->north != NULL) {
            room = room->north;
            printRoomDescription(room);
        } else {
            printf("There is no door to the north.\n");
        }
    } else if (strcmp(input, "s\n") == 0) {
        if (room->south != NULL) {
            room = room->south;
            printRoomDescription(room);
        } else {
            printf("There is no door to the south.\n");
        }
    } else if (strcmp(input, "e\n") == 0) {
        if (room->east != NULL) {
            room = room->east;
            printRoomDescription(room);
        } else {
            printf("There is no door to the east.\n");
        }
    } else if (strcmp(input, "w\n") == 0) {
        if (room->west != NULL) {
            room = room->west;
            printRoomDescription(room);
        } else {
            printf("There is no door to the west.\n");
        }
    } else if (strcmp(input, "look\n") == 0) {
        printRoomDescription(room);
    } else if (strcmp(input, "quit\n") == 0) {
        exit(0);
    } else {
        printf("I don't understand that command.\n");
    }
}

// The main game loop
void gameLoop(Player *player, Room *room) {
    while (1) {
        processPlayerInput(player, room);
    }
}

// The main function
int main() {
    // Create the player
    Player *player = createPlayer("John");

    // Create the rooms
    Room *room1 = createRoom("The Forest", "You are standing in a forest. The trees are tall and the air is thick with the smell of pine needles.");
    Room *room2 = createRoom("The Cave", "You are standing in a cave. The walls are covered in stalactites and stalagmites. The air is cool and damp.");
    Room *room3 = createRoom("The Castle", "You are standing in a castle. The walls are made of stone and the windows are stained glass. The air is warm and inviting.");

    // Connect the rooms
    connectRooms(room1, room2, 'n');
    connectRooms(room1, room3, 'e');

    // Start the game loop
    gameLoop(player, room1);

    return 0;
}