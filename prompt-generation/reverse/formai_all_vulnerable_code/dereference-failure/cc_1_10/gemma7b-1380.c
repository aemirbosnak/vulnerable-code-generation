//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: enthusiastic
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

// Function to generate a room
Room* generateRoom() {
    Room* room = malloc(sizeof(Room));
    room->x = rand() % MAX_ROOMS;
    room->y = rand() % MAX_ROOMS;
    room->next = NULL;
    return room;
}

// Function to link rooms
void linkRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

// Function to generate a dungeon
void generateDungeon() {
    // Create the first room
    Room* room1 = generateRoom();

    // Create the remaining rooms
    Room* room2 = generateRoom();
    Room* room3 = generateRoom();

    // Link the rooms
    linkRooms(room1, room2);
    linkRooms(room2, room3);

    // Print the dungeon
    for (room1 = room1; room1; room1 = room1->next) {
        printf("(%d, %d)\n", room1->x, room1->y);
    }
}

int main() {
    generateDungeon();
    return 0;
}