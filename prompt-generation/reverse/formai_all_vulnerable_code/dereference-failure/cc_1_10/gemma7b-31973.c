//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the room structure
typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

// Generate a room
Room* generate_room() {
    int x = rand() % MAX_ROOMS;
    int y = rand() % MAX_ROOMS;
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->next = NULL;
    return room;
}

// Connect rooms
void connect_rooms(Room* room1, Room* room2) {
    room1->next = room2;
}

// Create the dungeon
Room* create_dungeon() {
    // Generate the first room
    Room* room1 = generate_room();

    // Generate the remaining rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room* room2 = generate_room();
        connect_rooms(room1, room2);
        room1 = room2;
    }

    return room1;
}

int main() {
    // Create the dungeon
    Room* room = create_dungeon();

    // Print the dungeon
    for (room = room; room; room = room->next) {
        printf("(%d, %d)\n", room->x, room->y);
    }

    return 0;
}