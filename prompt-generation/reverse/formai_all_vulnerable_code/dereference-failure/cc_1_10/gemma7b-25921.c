//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the room structure
typedef struct room {
    char name[20];
    struct room* next;
    int treasures;
} room;

// Generate a random room
room* generate_room() {
    room* new_room = malloc(sizeof(room));
    new_room->name[0] = '\0';
    new_room->next = NULL;
    new_room->treasures = rand() % MAX_ROOMS;
    return new_room;
}

// Connect rooms
void connect_rooms(room* a, room* b) {
    a->next = b;
}

// Main game loop
int main() {
    // Create a list of rooms
    room* rooms = NULL;

    // Generate the first room
    room* new_room = generate_room();
    rooms = new_room;

    // Generate the remaining rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        new_room = generate_room();
        connect_rooms(rooms, new_room);
        rooms = new_room;
    }

    // Print the room list
    for (room* current_room = rooms; current_room; current_room = current_room->next) {
        printf("Room: %s, Treasures: %d\n", current_room->name, current_room->treasures);
    }

    return 0;
}