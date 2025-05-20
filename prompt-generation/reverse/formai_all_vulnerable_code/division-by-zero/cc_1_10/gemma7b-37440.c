//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_ITEM_NUM 5

typedef struct Room {
    int x, y;
    char name[20];
    struct Room* next;
} Room;

typedef struct Item {
    int id;
    char name[20];
    struct Item* next;
} Item;

void generate_map(Room** rooms) {
    int i, j, r, n, m;
    n = rand() % MAX_ROOM_NUM;
    m = rand() % MAX_ROOM_NUM;
    rooms = malloc(n * sizeof(Room));
    for (r = 0; r < n; r++) {
        rooms[r] = malloc(sizeof(Room));
        rooms[r]->x = rand() % m;
        rooms[r]->y = rand() % m;
        rooms[r]->name[0] = 'A' + r;
        rooms[r]->next = NULL;
    }
}

void generate_items(Item** items) {
    int i, n;
    n = rand() % MAX_ITEM_NUM;
    items = malloc(n * sizeof(Item));
    for (i = 0; i < n; i++) {
        items[i] = malloc(sizeof(Item));
        items[i]->id = rand() % MAX_ITEM_NUM;
        items[i]->name[0] = 'a' + i;
        items[i]->next = NULL;
    }
}

int main() {
    Room* rooms;
    Item* items;
    generate_map(&rooms);
    generate_items(&items);
    return 0;
}