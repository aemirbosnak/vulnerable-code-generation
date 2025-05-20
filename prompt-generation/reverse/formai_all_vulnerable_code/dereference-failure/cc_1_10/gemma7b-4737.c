//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
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
    int monsters;
    struct Room* next;
} Room;

// Create a new room
Room* new_room() {
    Room* room = malloc(sizeof(Room));
    room->x = rand() % MAX_ROOMS;
    room->y = rand() % MAX_ROOMS;
    room->monsters = rand() % MAX_MONSTERS;
    room->next = NULL;
    return room;
}

// Link rooms together
void link_rooms(Room* room1, Room* room2) {
    room1->next = room2;
}

// Print the map
void print_map(Room* room) {
    while (room) {
        printf("(%d, %d) - %d monsters\n", room->x, room->y, room->monsters);
        room = room->next;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the first room
    Room* room1 = new_room();

    // Create the remaining rooms
    Room* room2 = new_room();
    Room* room3 = new_room();
    Room* room4 = new_room();

    // Link the rooms together
    link_rooms(room1, room2);
    link_rooms(room2, room3);
    link_rooms(room3, room4);

    // Print the map
    print_map(room1);

    return 0;
}