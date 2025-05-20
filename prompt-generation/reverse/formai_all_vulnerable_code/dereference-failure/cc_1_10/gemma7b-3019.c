//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

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
    room1->east = room2;
    room2->west = room1;
}

void generateMap() {
    srand(time(NULL));
    int map[MAP_WIDTH][MAP_HEIGHT] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (map[x][y] == 0) {
                map[x][y] = createRoom(x, y);
            }
        }
    }

    connectRooms(map[0][0], map[0][1]);
    connectRooms(map[0][1], map[1][1]);
    connectRooms(map[1][1], map[1][0]);
    connectRooms(map[1][0], map[0][0]);
}

int main() {
    generateMap();
    return 0;
}