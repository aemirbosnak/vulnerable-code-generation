//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_INVENTORY_LENGTH 10

// Room structure
typedef struct Room {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Item structure
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} Item;

// Player structure
typedef struct Player {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct Room* currentRoom;
    Item inventory[MAX_INVENTORY_LENGTH];
    int inventoryCount;
} Player;

// Function to display the current room
void displayCurrentRoom(Player* player) {
    Room* room = player->currentRoom;
    printf("You are in %s.\n%s\n", room->name, room->description);
    if (room->north != NULL) {
        printf("To the north is %s.\n", room->north->name);
    }
    if (room->east != NULL) {
        printf("To the east is %s.\n", room->east->name);
    }
    if (room->south != NULL) {
        printf("To the south is %s.\n", room->south->name);
    }
    if (room->west != NULL) {
        printf("To the west is %s.\n", room->west->name);
    }
    printf("\n");
}

// Function to add item to player's inventory
void addItemToInventory(Player* player, Item item) {
    if (player->inventoryCount < MAX_INVENTORY_LENGTH) {
        player->inventory[player->inventoryCount++] = item;
        printf("Added %s to your inventory.\n\n", item.name);
    }
    else {
        printf("Your inventory is full.\n\n");
    }
}

// Function to remove item from player's inventory
void removeItemFromInventory(Player* player, char* itemName) {
    int i, found = 0;
    for (i = 0; i < player->inventoryCount; i++) {
        if (strcmp(player->inventory[i].name, itemName) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        player->inventoryCount--;
        for (; i < player->inventoryCount; i++) {
            player->inventory[i] = player->inventory[i+1];
        }
        printf("Removed %s from your inventory.\n\n", itemName);
        return;
    }
    printf("You don't have %s in your inventory.\n\n", itemName);
}

// Function to get player's input
void getPlayerInput(char* input, int length) {
    printf("> ");
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
}

// Main function
int main() {

    // Initialize items
    Item key = {"key", "A rusty old key."};
    Item sword = {"sword", "A sharp steel sword."};
    Item potion = {"potion", "A vial of red liquid."};

    // Initialize rooms
    Room* hallway = malloc(sizeof(Room));
    strcpy(hallway->name, "the hallway");
    strcpy(hallway->description, "You are in a dimly lit hallway. There are doors to the north, east, south, and west.");
    hallway->north = NULL;
    hallway->east = NULL;
    hallway->south = NULL;
    hallway->west = NULL;

    Room* bedroom = malloc(sizeof(Room));
    strcpy(bedroom->name, "the bedroom");
    strcpy(bedroom->description, "You are in a cozy bedroom. There is a bed and a chest of drawers. There is a door to the west.");
    bedroom->north = NULL;
    bedroom->east = NULL;
    bedroom->south = NULL;
    bedroom->west = hallway;
    addItemToInventory(NULL, key);

    Room* kitchen = malloc(sizeof(Room));
    strcpy(kitchen->name, "the kitchen");
    strcpy(kitchen->description, "You are in a brightly lit kitchen. There is a stove, a refrigerator, and a sink. There is a door to the north.");
    kitchen->north = bedroom;
    kitchen->east = NULL;
    kitchen->south = NULL;
    kitchen->west = NULL;

    Room* garden = malloc(sizeof(Room));
    strcpy(garden->name, "the garden");
    strcpy(garden->description, "You are in a lush garden. There are flowers and trees all around you. There is a door to the east.");
    garden->north = NULL;
    garden->east = hallway;
    garden->south = NULL;
    garden->west = NULL;
    addItemToInventory(NULL, sword);

    Room* cellar = malloc(sizeof(Room));
    strcpy(cellar->name, "the cellar");
    strcpy(cellar->description, "You are in a dark cellar. There are shelves filled with jars and boxes. There is a door to the south.");
    cellar->north = NULL;
    cellar->east = NULL;
    cellar->south = kitchen;
    cellar->west = NULL;
    addItemToInventory(NULL, potion);

    // Initialize player
    Player player;
    printf("What is your name?\n");
    getPlayerInput(player.name, MAX_NAME_LENGTH);
    strcpy(player.description, "You are a brave adventurer seeking treasure.");
    player.currentRoom = hallway;
    player.inventoryCount = 0;

    // Game loop
    printf("\nWelcome, %s! Let the adventure begin!\n\n", player.name);
    while (true) {
        displayCurrentRoom(&player);

        // Get player's input
        char input[MAX_DESCRIPTION_LENGTH];
        getPlayerInput(input, MAX_DESCRIPTION_LENGTH);

        // Handle player's input
        if (strcmp(input, "north") == 0) {
            if (player.currentRoom->north == NULL) {
                printf("You can't go that way.\n\n");
            }
            else {
                player.currentRoom = player.currentRoom->north;
            }
        }
        else if (strcmp(input, "east") == 0) {
            if (player.currentRoom->east == NULL) {
                printf("You can't go that way.\n\n");
            }
            else {
                player.currentRoom = player.currentRoom->east;
            }
        }
        else if (strcmp(input, "south") == 0) {
            if (player.currentRoom->south == NULL) {
                printf("You can't go that way.\n\n");
            }
            else {
                player.currentRoom = player.currentRoom->south;
            }
        }
        else if (strcmp(input, "west") == 0) {
            if (player.currentRoom->west == NULL) {
                printf("You can't go that way.\n\n");
            }
            else {
                player.currentRoom = player.currentRoom->west;
            }
        }
        else if (strcmp(input, "look") == 0) {
            displayCurrentRoom(&player);
        }
        else if (strcmp(input, "inventory") == 0) {
            printf("Your inventory:\n");
            if (player.inventoryCount == 0) {
                printf("Empty\n");
            }
            else {
                int i;
                for (i = 0; i < player.inventoryCount; i++) {
                    printf("%s - %s\n", player.inventory[i].name, player.inventory[i].description);
                }
            }
            printf("\n");
        }
        else if (strcmp(input, "take key") == 0) {
            addItemToInventory(&player, key);
        }
        else if (strcmp(input, "take sword") == 0) {
            addItemToInventory(&player, sword);
        }
        else if (strcmp(input, "take potion") == 0) {
            addItemToInventory(&player, potion);
        }
        else if (strcmp(input, "drop") == 0) {
            printf("What do you want to drop?\n");
            getPlayerInput(input, MAX_DESCRIPTION_LENGTH);
            removeItemFromInventory(&player, input);
        }
        else {
            printf("I don't understand.\n\n");
        }
    }

    // Free resources
    free(hallway);
    free(bedroom);
    free(kitchen);
    free(garden);
    free(cellar);

    return 0;
}