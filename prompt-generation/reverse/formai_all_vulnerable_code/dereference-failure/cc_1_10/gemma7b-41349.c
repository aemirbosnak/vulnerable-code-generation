//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_ITEM_NUM 5

typedef struct Room {
    int x, y;
    char description[256];
    struct Room* north, *south, *east, *west;
} Room;

typedef struct Item {
    char name[256];
    int quantity;
    struct Item* next;
} Item;

Room** generateRooms(int numRooms) {
    Room** rooms = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % MAX_ROOM_NUM;
        rooms[i]->y = rand() % MAX_ROOM_NUM;
        rooms[i]->description[0] = '\0';
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
    }
    return rooms;
}

Item** generateItems(int numItems) {
    Item** items = malloc(numItems * sizeof(Item*));
    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->name[0] = '\0';
        items[i]->quantity = rand() % MAX_ITEM_NUM;
        items[i]->next = NULL;
    }
    return items;
}

int main() {
    srand(time(NULL));

    int numRooms = 10;
    Room** rooms = generateRooms(numRooms);

    int numItems = 5;
    Item** items = generateItems(numItems);

    // Use the rooms and items to create your game logic here

    // Free the allocated memory
    for (int i = 0; i < numRooms; i++) {
        free(rooms[i]);
    }
    free(rooms);

    for (int i = 0; i < numItems; i++) {
        free(items[i]);
    }
    free(items);

    return 0;
}