//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateRooms(int numRooms) {
    srand(time(NULL));
    Room** rooms = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % 10 + 1;
        rooms[i]->y = rand() % 10 + 1;
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
    }

    return rooms;
}

void connectRooms(Room** rooms) {
    for (int i = 0; i < MAX_Rooms; i++) {
        int r1 = rand() % MAX_Rooms;
        int r2 = rand() % MAX_Rooms;
        if (r1 != r2) {
            rooms[r1]->east = rooms[r2];
            rooms[r2]->west = rooms[r1];
        }
    }
}

void printRooms(Room** rooms) {
    for (int i = 0; i < MAX_Rooms; i++) {
        printf("Room (%d, %d)\n", rooms[i]->x, rooms[i]->y);
        if (rooms[i]->north) {
            printf("  North: Room (%d, %d)\n", rooms[i]->north->x, rooms[i]->north->y);
        }
        if (rooms[i]->south) {
            printf("  South: Room (%d, %d)\n", rooms[i]->south->x, rooms[i]->south->y);
        }
        if (rooms[i]->east) {
            printf("  East: Room (%d, %d)\n", rooms[i]->east->x, rooms[i]->east->y);
        }
        if (rooms[i]->west) {
            printf("  West: Room (%d, %d)\n", rooms[i]->west->x, rooms[i]->west->y);
        }
    }
}

int main() {
    Room** rooms = generateRooms(MAX_Rooms);
    connectRooms(rooms);
    printRooms(rooms);

    return 0;
}