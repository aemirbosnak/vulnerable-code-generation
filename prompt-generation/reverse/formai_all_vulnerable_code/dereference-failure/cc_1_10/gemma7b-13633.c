//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOM_NUM 5
#define MAX_ITEM_NUM 3

typedef struct room {
    int x, y;
    char name[20];
    struct room* next;
} room;

typedef struct item {
    char name[20];
    int quantity;
} item;

room* create_room(int x, int y, char* name) {
    room* new_room = malloc(sizeof(room));
    new_room->x = x;
    new_room->y = y;
    strcpy(new_room->name, name);
    new_room->next = NULL;
    return new_room;
}

item* create_item(char* name, int quantity) {
    item* new_item = malloc(sizeof(item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    return new_item;
}

void generate_map(room** map) {
    time_t t = time(NULL);
    srand(t);

    int num_rooms = rand() % MAX_ROOM_NUM + 1;
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        char name[20] = "Room ";
        name[strlen(name)] = i + 1;
        *map = create_room(x, y, name);
        map = (*map)->next;
    }
}

int main() {
    room* map = NULL;
    generate_map(&map);

    // Explore the map and interact with rooms and items
    return 0;
}