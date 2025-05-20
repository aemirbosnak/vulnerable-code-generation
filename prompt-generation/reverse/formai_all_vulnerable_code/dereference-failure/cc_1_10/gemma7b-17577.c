//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
    int x, y;
    char name[20];
    struct Room* next;
} Room;

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Room* generate_rooms(int num_rooms) {
    srand(time(NULL));
    Room* rooms = NULL;
    for (int i = 0; i < num_rooms; i++) {
        rooms = malloc(sizeof(Room));
        rooms->x = rand() % 10 + 1;
        rooms->y = rand() % 10 + 1;
        rooms->name[0] = 'A' + i;
        rooms->next = rooms;
    }
    return rooms;
}

Item* generate_items(int num_items) {
    srand(time(NULL));
    Item* items = NULL;
    for (int i = 0; i < num_items; i++) {
        items = malloc(sizeof(Item));
        items->name[0] = 'a' + i;
        items->quantity = rand() % 5 + 1;
        items->next = items;
    }
    return items;
}

void explore(Room* rooms, Item* items) {
    // Traverse the rooms and items
    // ...
}

int main() {
    Room* rooms = generate_rooms(MAX_ROOMS);
    Item* items = generate_items(MAX_ITEMS);
    explore(rooms, items);
    return 0;
}