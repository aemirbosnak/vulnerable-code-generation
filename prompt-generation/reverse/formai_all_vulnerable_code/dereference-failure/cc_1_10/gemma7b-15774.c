//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complex
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

// Print the map
void print_map(Room* room) {
    for (int y = 0; y < MAX_ROOMS; y++) {
        for (int x = 0; x < MAX_ROOMS; x++) {
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
    // Generate the first room
    Room* room1 = generate_room();

    // Generate the remaining rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room* room2 = generate_room();
        connect_rooms(room1, room2);
        room1 = room2;
    }

    // Print the map
    print_map(room1);

    return 0;
}