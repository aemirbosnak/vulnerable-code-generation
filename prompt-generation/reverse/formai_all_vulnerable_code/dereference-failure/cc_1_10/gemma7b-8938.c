//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_ITEM_COUNT 5

typedef struct Room {
    int x, y;
    char description[256];
    struct Room* north, *south, *east, *west;
} Room;

typedef struct Item {
    char name[64];
    int quantity;
    struct Item* next;
} Item;

Room** generateRooms() {
    int numRooms = rand() % MAX_ROOM_COUNT + 1;
    Room** rooms = malloc(numRooms * sizeof(Room*));

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
    int numItems = rand() % MAX_ITEM_COUNT + 1;
    Item** items = malloc(numItems * sizeof(Item*));

    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->name[0] = '\0';
        items[i]->quantity = rand() % 10 + 1;
        items[i]->next = NULL;
    }

    return items;
}

int main() {
    srand(time(NULL));

    Room** rooms = generateRooms();
    Item** items = generateItems();

    // Traverse the rooms and items, etc.

    for (int i = 0; rooms[i] != NULL; i++) {
        printf("Room: (%d, %d)\n", rooms[i]->x, rooms[i]->y);
        printf("Description: %s\n", rooms[i]->description);
    }

    for (int i = 0; items[i] != NULL; i++) {
        printf("Item: %s, Quantity: %d\n", items[i]->name, items[i]->quantity);
    }

    return 0;
}