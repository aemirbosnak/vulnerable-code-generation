//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
    int x, y;
    char **description;
    struct Room **connections;
} Room;

typedef struct Item {
    char name;
    int quantity;
} Item;

Room **generateRooms(int numRooms) {
    Room **rooms = malloc(numRooms * sizeof(Room));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % 10;
        rooms[i]->y = rand() % 10;
        rooms[i]->description = malloc(20 * sizeof(char));
        rooms[i]->connections = NULL;
    }
    return rooms;
}

Item **generateItems(int numItems) {
    Item **items = malloc(numItems * sizeof(Item));
    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->name = rand() % MAX_ITEMS + 'a';
        items[i]->quantity = rand() % 5 + 1;
    }
    return items;
}

int main() {
    srand(time(NULL));

    // Generate the rooms and items
    Room **rooms = generateRooms(MAX_ROOMS);
    Item **items = generateItems(MAX_ITEMS);

    // Print the room descriptions
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("You are in %s.\n", rooms[i]->description);
    }

    // Free the memory
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i]->description);
        free(rooms[i]);
    }
    free(rooms);
    free(items);

    return 0;
}