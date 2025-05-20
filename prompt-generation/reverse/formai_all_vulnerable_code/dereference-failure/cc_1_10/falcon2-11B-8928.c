//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 100
#define MAX_ROOM_SIZE 20
#define MAX_ROOM_NAME 20
#define MAX_ITEM 100
#define MAX_ITEM_NAME 20
#define MAX_ITEM_WEIGHT 10

typedef struct Room {
    char name[MAX_ROOM_NAME];
    struct Room* next;
} Room;

typedef struct Item {
    char name[MAX_ITEM_NAME];
    int weight;
} Item;

typedef struct Map {
    Room* rooms[MAX_ROOM];
    int num_rooms;
    Item* items[MAX_ROOM];
    int num_items;
} Map;

void generate_map(Map* map) {
    int num_rooms = rand() % MAX_ROOM;
    int num_items = rand() % MAX_ITEM;
    
    for (int i = 0; i < num_rooms; i++) {
        Room* room = (Room*)malloc(sizeof(Room));
        room->next = NULL;
        strcpy(room->name, "Room ");
        strcat(room->name, i+1);
        map->rooms[i] = room;
    }
    
    for (int i = 0; i < num_items; i++) {
        Item* item = (Item*)malloc(sizeof(Item));
        item->weight = rand() % MAX_ITEM_WEIGHT;
        strcpy(item->name, "Item ");
        strcat(item->name, i+1);
        map->items[i] = item;
    }
    
    map->num_rooms = num_rooms;
    map->num_items = num_items;
}

int main() {
    Map map;
    generate_map(&map);
    
    printf("Map\n");
    printf("------------------\n");
    printf("Number of Rooms: %d\n", map.num_rooms);
    printf("Number of Items: %d\n", map.num_items);
    printf("Rooms\n");
    for (int i = 0; i < map.num_rooms; i++) {
        printf("  Room %d: %s\n", i+1, map.rooms[i]->name);
    }
    printf("Items\n");
    for (int i = 0; i < map.num_items; i++) {
        printf("  Item %d: %s (Weight: %d)\n", i+1, map.items[i]->name, map.items[i]->weight);
    }
    
    return 0;
}