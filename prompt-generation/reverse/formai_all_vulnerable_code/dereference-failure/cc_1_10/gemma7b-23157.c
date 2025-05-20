//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the room structure
typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

// Generate a random room
Room* generateRoom() {
    Room* room = malloc(sizeof(Room));
    room->x = rand() % MAX_ROOMS;
    room->y = rand() % MAX_ROOMS;
    room->next = NULL;
    return room;
}

// Connect rooms
void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

// Create a dungeon
Room* createDungeon() {
    // Generate the first room
    Room* room1 = generateRoom();

    // Generate the remaining rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room* room2 = generateRoom();
        connectRooms(room1, room2);
        room1 = room2;
    }

    return room1;
}

int main() {
    // Create the dungeon
    Room* room = createDungeon();

    // Print the dungeon
    for (room = room; room; room = room->next) {
        printf("(%d, %d)\n", room->x, room->y);
    }

    return 0;
}