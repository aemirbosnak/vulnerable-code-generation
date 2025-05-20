//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game states
#define STATE_INTRO 0
#define STATE_ROOM1 1
#define STATE_ROOM2 2
#define STATE_ROOM3 3
#define STATE_ROOM4 4
#define STATE_ROOM5 5
#define STATE_WIN 6
#define STATE_LOSE 7

// Directions
#define DIR_N 0
#define DIR_E 1
#define DIR_S 2
#define DIR_W 3

// Room descriptions
char *room_descriptions[] = {
    "You are in a dark and musty room. There is a door to the north.",
    "You are in a small room with a window to the east. There is a door to the south.",
    "You are in a large room with a fireplace to the north. There are doors to the east and west.",
    "You are in a dark and narrow hallway. There are doors to the north and south.",
    "You are in a small room with a bed to the south. There is a door to the west.",
    "You are in a large and opulent room. There is a door to the east."
};

// Room exits
int room_exits[][4] = {
    { 1, 0, 0, 0 },
    { 0, 2, 1, 0 },
    { 0, 3, 0, 1 },
    { 2, 0, 4, 0 },
    { 0, 3, 0, 5 },
    { 0, 6, 0, 0 }
};

// Player inventory
char *inventory[] = { "Sword", "Shield", "Health Potion" };

// Game state
int state = STATE_INTRO;
int room = 0;
int hp = 100;

// Main game loop
int main() {
    // Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the lost treasure.\n");
    printf("You start in a dark and musty room.\n");

    // Game loop
    while (state != STATE_WIN && state != STATE_LOSE) {
        // Display the room description
        printf("%s\n", room_descriptions[room]);

        // Display the player inventory
        printf("Inventory: ");
        for (int i = 0; i < sizeof(inventory) / sizeof(char *); i++) {
            printf("%s ", inventory[i]);
        }
        printf("\n");

        // Display the health points
        printf("HP: %d\n", hp);

        // Get the player's input
        char input[256];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the player's input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Handle the player's input
        if (strcmp(command, "go") == 0) {
            // Go in a direction
            int direction = -1;
            if (strcmp(argument, "north") == 0) {
                direction = DIR_N;
            } else if (strcmp(argument, "east") == 0) {
                direction = DIR_E;
            } else if (strcmp(argument, "south") == 0) {
                direction = DIR_S;
            } else if (strcmp(argument, "west") == 0) {
                direction = DIR_W;
            }

            if (direction != -1 && room_exits[room][direction] != 0) {
                room = room_exits[room][direction];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            // Look around the room
            printf("%s\n", room_descriptions[room]);
        } else if (strcmp(command, "use") == 0) {
            // Use an item from the inventory
            int item = -1;
            for (int i = 0; i < sizeof(inventory) / sizeof(char *); i++) {
                if (strcmp(argument, inventory[i]) == 0) {
                    item = i;
                    break;
                }
            }

            if (item != -1) {
                // Use the item
                if (strcmp(inventory[item], "Sword") == 0) {
                    // Attack an enemy
                    printf("You attack an enemy with your sword.\n");
                    hp += 10;
                } else if (strcmp(inventory[item], "Shield") == 0) {
                    // Defend against an enemy attack
                    printf("You defend against an enemy attack with your shield.\n");
                    hp -= 10;
                } else if (strcmp(inventory[item], "Health Potion") == 0) {
                    // Heal yourself
                    printf("You heal yourself with a health potion.\n");
                    hp += 20;
                }
            } else {
                printf("You don't have that item.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            return 0;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }

        // Check if the player has won or lost
        if (hp <= 0) {
            state = STATE_LOSE;
        } else if (room == 5) {
            state = STATE_WIN;
        }
    }

    // Display the game over message
    if (state == STATE_WIN) {
        printf("You win!\n");
    } else if (state == STATE_LOSE) {
        printf("You lose!\n");
    }

    return 0;
}