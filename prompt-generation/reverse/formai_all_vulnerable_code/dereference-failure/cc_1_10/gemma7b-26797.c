//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the maximum number of monsters per room
#define MAX_MONSTERS 3

// Define the room structure
typedef struct Room {
    int x, y;
    char type;
    struct Room* next;
} Room;

// Generate a random room
Room* generate_room() {
    int x = rand() % MAX_ROOMS;
    int y = rand() % MAX_ROOMS;
    char type = 'a' + rand() % 3;
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->type = type;
    room->next = NULL;
    return room;
}

// Connect rooms
void connect_rooms(Room* room1, Room* room2) {
    room1->next = room2;
}

// Create a dungeon
void create_dungeon() {
    // Generate the first room
    Room* room1 = generate_room();

    // Generate the remaining rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room* room2 = generate_room();
        connect_rooms(room1, room2);
        room1 = room2;
    }

    // Print the dungeon
    for (room1 = room1; room1; room1 = room1->next) {
        printf("Room (%d, %d): %c\n", room1->x, room1->y, room1->type);
    }
}

int main() {
    create_dungeon();
    return 0;
}