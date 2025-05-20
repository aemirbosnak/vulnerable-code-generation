//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
    char name[20];
    struct Room* nextRoom;
    struct Item* items;
} Room;

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* nextItem;
} Item;

void generateRooms(Room** rooms, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->name[0] = 'A' + i;
        rooms[i]->nextRoom = NULL;
        rooms[i]->items = NULL;
    }
}

void generateItems(Item** items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->name[0] = 'a' + i;
        items[i]->quantity = rand() % 5 + 1;
        items[i]->nextItem = NULL;
    }
}

int main() {
    srand(time(NULL));

    Room* rooms = NULL;
    generateRooms(&rooms, MAX_ROOMS);

    Item* items = NULL;
    generateItems(&items, MAX_ITEMS);

    // Play the game
    // ...

    // Free memory
    free(rooms);
    free(items);

    return 0;
}