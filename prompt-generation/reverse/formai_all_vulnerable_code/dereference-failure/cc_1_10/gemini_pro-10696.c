//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rooms
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Define the player
typedef struct Player {
    char* name;
    Room* currentRoom;
    int health;
} Player;

// Create the rooms
Room room1 = {"Room 1", "This is room 1.", NULL, NULL, NULL, NULL};
Room room2 = {"Room 2", "This is room 2.", &room1, NULL, NULL, NULL};
Room room3 = {"Room 3", "This is room 3.", &room2, NULL, NULL, NULL};
Room room4 = {"Room 4", "This is room 4.", &room3, NULL, NULL, NULL};
Room room5 = {"Room 5", "This is room 5.", &room4, NULL, NULL, NULL};

// Create the player
Player player = {"Player", &room1, 100};

// Define the commands
typedef struct Command {
    char* name;
    void (*function)(Player*, char*);
} Command;

// Define the command functions
void goNorth(Player* player, char* args) {
    if (player->currentRoom->north != NULL) {
        player->currentRoom = player->currentRoom->north;
        printf("You go north to %s.\n", player->currentRoom->name);
    } else {
        printf("You can't go north from here.\n");
    }
}

void goEast(Player* player, char* args) {
    if (player->currentRoom->east != NULL) {
        player->currentRoom = player->currentRoom->east;
        printf("You go east to %s.\n", player->currentRoom->name);
    } else {
        printf("You can't go east from here.\n");
    }
}

void goSouth(Player* player, char* args) {
    if (player->currentRoom->south != NULL) {
        player->currentRoom = player->currentRoom->south;
        printf("You go south to %s.\n", player->currentRoom->name);
    } else {
        printf("You can't go south from here.\n");
    }
}

void goWest(Player* player, char* args) {
    if (player->currentRoom->west != NULL) {
        player->currentRoom = player->currentRoom->west;
        printf("You go west to %s.\n", player->currentRoom->name);
    } else {
        printf("You can't go west from here.\n");
    }
}

void look(Player* player, char* args) {
    printf("%s\n", player->currentRoom->description);
}

void quit(Player* player, char* args) {
    exit(0);
}

// Create the command table
Command commands[] = {
    {"go north", goNorth},
    {"go east", goEast},
    {"go south", goSouth},
    {"go west", goWest},
    {"look", look},
    {"quit", quit},
    {NULL, NULL}
};

// Get the player's input
char* getInput() {
    char* input = malloc(256);
    fgets(input, 256, stdin);
    return input;
}

// Parse the player's input
Command* parseInput(char* input) {
    char* command = strtok(input, " ");
    char* args = strtok(NULL, "\n");
    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            return &commands[i];
        }
    }
    return NULL;
}

// Run the game
void runGame() {
    while (1) {
        printf("> ");
        char* input = getInput();
        Command* command = parseInput(input);
        if (command != NULL) {
            command->function(&player, input);
        } else {
            printf("Invalid command.\n");
        }
        free(input);
    }
}

// Main function
int main() {
    runGame();
    return 0;
}