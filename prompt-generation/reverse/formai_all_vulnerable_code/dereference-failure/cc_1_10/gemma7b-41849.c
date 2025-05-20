//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

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

Room* create_room(int x, int y, char* name) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    strcpy(room->name, name);
    room->next = NULL;
    return room;
}

Item* create_item(char* name, int quantity) {
    Item* item = malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void generate_map(int width, int height) {
    // Create a map of rooms
    Room* head = create_room(0, 0, "Starting Room");
    Room* current = head;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            char name[20];
            sprintf(name, "Room %d", current->next ? current->next->x : 1);
            current = create_room(x, y, name);
            current->next = head;
            head = current;
        }
    }

    // Connect rooms
    current = head;
    while (current) {
        if (current->next) {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            current->next->x = current->x + dx;
            current->next->y = current->y + dy;
        }
        current = current->next;
    }
}

void main() {
    generate_map(10, 10);
}