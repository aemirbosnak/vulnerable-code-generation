//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
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

void generateMap() {
    int x, y;
    srand(time(NULL));

    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            int type = rand() % 3;
            switch (type) {
                case 0:
                    createRoom(x, y);
                    break;
                case 1:
                    createRoom(x, y);
                    break;
                case 2:
                    createRoom(x, y);
                    break;
            }
        }
    }
}

int main() {
    generateMap();

    return 0;
}