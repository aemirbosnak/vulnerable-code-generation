//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
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
Room* generate_room() {
    Room* room = malloc(sizeof(Room));
    room->x = rand() % MAX_ROOMS;
    room->y = rand() % MAX_ROOMS;
    room->next = NULL;
    return room;
}

// Function to connect rooms
void connect_rooms(Room* room1, Room* room2) {
    room1->next = room2;
    room2->next = room1;
}

// Function to print the map
void print_map(Room* room) {
    int x, y;
    for (x = 0; x < MAX_ROOMS; x++) {
        for (y = 0; y < MAX_ROOMS; y++) {
            if (room->x == x && room->y == y) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the rooms
    Room* rooms = generate_room();
    connect_rooms(rooms, generate_room());
    connect_rooms(rooms, generate_room());

    // Print the map
    print_map(rooms);

    return 0;
}