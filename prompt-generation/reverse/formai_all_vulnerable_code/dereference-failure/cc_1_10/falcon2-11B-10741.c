//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NAME_LENGTH 16
#define MAX_ROOMS 100

typedef struct {
    char name[MAX_ROOM_NAME_LENGTH];
    char description[MAX_ROOM_NAME_LENGTH];
    struct room* next;
} room_t;

void add_room(room_t** rooms, const char* name, const char* description) {
    room_t* new_room = malloc(sizeof(room_t));
    strncpy(new_room->name, name, MAX_ROOM_NAME_LENGTH);
    strncpy(new_room->description, description, MAX_ROOM_NAME_LENGTH);
    new_room->next = NULL;

    if (*rooms == NULL) {
        *rooms = new_room;
        return;
    }

    room_t* current = *rooms;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_room;
}

void print_rooms(room_t* rooms) {
    room_t* current = rooms;
    while (current!= NULL) {
        printf("%s: %s\n", current->name, current->description);
        current = current->next;
    }
}

int main() {
    room_t* rooms = NULL;
    add_room(&rooms, "Kitchen", "A cozy kitchen where you can find some food and a stove.");
    add_room(&rooms, "Living Room", "A comfortable living room with a TV and a couch.");
    add_room(&rooms, "Bedroom", "A peaceful bedroom with a bed and some nightstands.");
    add_room(&rooms, "Bathroom", "A small bathroom with a shower and a sink.");
    add_room(&rooms, "Attic", "An abandoned attic filled with old furniture and memories.");

    print_rooms(rooms);

    return 0;
}