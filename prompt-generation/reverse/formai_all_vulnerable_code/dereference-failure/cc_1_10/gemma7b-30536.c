//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 20
#define MAX_ITEM_COUNT 10

typedef struct Room {
    int x, y;
    char description[255];
    struct Room* north, *south, *east, *west;
} Room;

typedef struct Item {
    char name[255];
    int quantity;
    struct Item* next;
} Item;

Room** generateRooms() {
    srand(time(NULL));
    int numRooms = rand() % MAX_ROOM_COUNT + 1;

    Room** rooms = malloc(numRooms * sizeof(Room));

    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % 10 + 1;
        rooms[i]->y = rand() % 10 + 1;
        rooms[i]->description[0] = '\0';
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
    }

    return rooms;
}

Item** generateItems() {
    srand(time(NULL));
    int numItems = rand() % MAX_ITEM_COUNT + 1;

    Item** items = malloc(numItems * sizeof(Item));

    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->name[0] = '\0';
        items[i]->quantity = rand() % 10 + 1;
        items[i]->next = NULL;
    }

    return items;
}

int main() {
    Room** rooms = generateRooms();
    Item** items = generateItems();

    // Play the game
    // ...

    // Free memory
    for (int i = 0; rooms[i]; i++) free(rooms[i]);
    free(rooms);
    for (int i = 0; items[i]; i++) free(items[i]);
    free(items);

    return 0;
}