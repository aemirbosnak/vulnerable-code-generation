//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Room {
    int x;
    int y;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room* createRoom(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void connectRooms(Room* room1, Room* room2) {
    room1->north = room2;
    room2->south = room1;
}

void generateMap() {
    int x, y;
    srand(time(NULL));

    // Create the map
    Room* rooms = createRoom(0, 0);
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            rooms = createRoom(x, y);
            connectRooms(rooms, rooms);
        }
    }

    // Connect the rooms
    connectRooms(rooms, rooms);
}

int main() {
    generateMap();
    return 0;
}