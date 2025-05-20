//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room* createRoom() {
    Room* room = malloc(sizeof(Room));
    room->x = rand() % MAP_SIZE;
    room->y = rand() % MAP_SIZE;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void connectRooms(Room* a, Room* b) {
    a->east = b;
    b->west = a;
}

int main() {
    Room* rooms = NULL;
    int numRooms = 0;

    // Create a number of rooms
    for (int i = 0; i < 10; i++) {
        rooms = createRoom();
        numRooms++;
        connectRooms(rooms, rooms);
    }

    // Print the map
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            Room* room = rooms;
            while (room) {
                if (room->x == x && room->y == y) {
                    printf("%c ", 'A' + numRooms - 1);
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}