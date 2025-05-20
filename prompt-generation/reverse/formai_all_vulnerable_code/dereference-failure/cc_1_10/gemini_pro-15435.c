//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game state
typedef enum {
    START,
    ROOM1,
    ROOM2,
    ROOM3,
    END
} GameState;

// Room descriptions
const char *room_descriptions[] = {
    "You are in the starting room.",
    "You are in room 1.",
    "You are in room 2.",
    "You are in room 3.",
    "You have reached the end of the game."
};

// Room exits
const int room_exits[][4] = {
    { ROOM1, -1, -1, -1 },
    { ROOM2, ROOM3, -1, -1 },
    { -1, -1, ROOM3, -1 },
    { -1, -1, -1, END }
};

// Player inventory
typedef struct {
    int lamp;
    int key;
} Inventory;

// Game function prototypes
void print_room_description(GameState state);
GameState process_input(GameState state, Inventory *inventory);

int main() {
    // Initialize game state
    GameState state = START;

    // Initialize player inventory
    Inventory inventory = { 0, 0 };

    // Main game loop
    while (state != END) {
        // Print room description
        print_room_description(state);

        // Process player input
        state = process_input(state, &inventory);
    }

    // Print game over message
    printf("Thank you for playing!\n");

    return 0;
}

void print_room_description(GameState state) {
    printf("%s\n", room_descriptions[state]);
}

GameState process_input(GameState state, Inventory *inventory) {
    // Get player input
    char input[100];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse player input
    char *command = strtok(input, " ");
    char *argument = strtok(NULL, " ");

    // Process player command
    if (strcmp(command, "go") == 0) {
        int exit = atoi(argument);
        if (room_exits[state][exit] != -1) {
            state = room_exits[state][exit];
        } else {
            printf("Invalid exit.\n");
        }
    } else if (strcmp(command, "take") == 0) {
        if (strcmp(argument, "lamp") == 0 && state == ROOM1) {
            inventory->lamp = 1;
        } else if (strcmp(argument, "key") == 0 && state == ROOM2) {
            inventory->key = 1;
        } else {
            printf("Invalid item.\n");
        }
    } else if (strcmp(command, "use") == 0) {
        if (strcmp(argument, "lamp") == 0 && inventory->lamp) {
            printf("You use the lamp to light up the room.\n");
        } else if (strcmp(argument, "key") == 0 && inventory->key) {
            if (state == ROOM3) {
                state = END;
            } else {
                printf("Invalid use of key.\n");
            }
        } else {
            printf("Invalid use of item.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    return state;
}