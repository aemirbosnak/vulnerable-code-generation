//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_ITEMS 5

typedef struct {
    char name[30];
    int power;
} Item;

typedef struct {
    char description[100];
    int difficulty;
    Item *item;
} Room;

void startGame();
void displayRoom(Room *room);
void takeAction(Room *room, Item *inventory, int *itemCount);
void showInventory(Item *inventory, int itemCount);

int main() {
    srand(time(0));
    startGame();
    return 0;
}

void startGame() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0;

    Room rooms[3] = {
        {"You are in a dark forest. Sounds of owls echo around you. You see a path to the north.", 2, NULL},
        {"You've entered a mystical cave. Glowing crystals light the walls. You can go east or west.", 3, NULL},
        {"You stand before an ancient temple. The entrance is guarded by a fierce dragon. You can flee south.", 5, NULL}
    };

    printf("Welcome to the Quest for the Legendary Artifact!\n");
    printf("Your journey begins...\n");

    for (int i = 0; i < 3; i++) {
        printf("\nRoom %d:\n", i + 1);
        displayRoom(&rooms[i]);
        if (rooms[i].difficulty <= 4) {
            rooms[i].item = (Item *)malloc(sizeof(Item));
            strcpy(rooms[i].item->name, "Shiny Gem");
            rooms[i].item->power = rand() % 10 + 1;
            printf("You found an item: %s with power %d\n", rooms[i].item->name, rooms[i].item->power);
        }
        takeAction(&rooms[i], inventory, &itemCount);
    }
    printf("\nYour adventure comes to an end. Thank you for playing!\n");
}

void displayRoom(Room *room) {
    printf("%s\n", room->description);
}

void takeAction(Room *room, Item *inventory, int *itemCount) {
    char action[MAX_INPUT];

    printf("What would you like to do? (take/show/escape)\n");
    fgets(action, MAX_INPUT, stdin);
    action[strcspn(action, "\n")] = 0; // Remove trailing newline

    if (strcmp(action, "take") == 0 && room->item != NULL) {
        if (*itemCount < MAX_ITEMS) {
            inventory[*itemCount] = *(room->item);
            printf("You took the %s!\n", room->item->name);
            (*itemCount)++;
            free(room->item); // Free the item after taking it
            room->item = NULL; // Indicate that the item has been taken
        } else {
            printf("Your inventory is full!\n");
        }
    } else if (strcmp(action, "show") == 0) {
        showInventory(inventory, *itemCount);
    } else if (strcmp(action, "escape") == 0) {
        printf("You escaped from the room!\n");
    } else {
        printf("Invalid action. Please try again.\n");
        takeAction(room, inventory, itemCount);
    }
}

void showInventory(Item *inventory, int itemCount) {
    if (itemCount == 0) {
        printf("Your inventory is empty.\n");
    } else {
        printf("Inventory:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("%d: %s (Power: %d)\n", i + 1, inventory[i].name, inventory[i].power);
        }
    }
}