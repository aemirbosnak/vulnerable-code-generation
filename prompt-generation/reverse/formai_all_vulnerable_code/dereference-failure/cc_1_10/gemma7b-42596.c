//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

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

void generateMaze(int numRooms) {
    srand(time(NULL));

    // Create a list of rooms
    Room* rooms = NULL;
    for (int i = 0; i < numRooms; i++) {
        rooms = createRoom(rand() % MAX_ROOMS, rand() % MAX_ROOMS);
        if (rooms) {
            rooms->north = rand() % MAX_PATHS ? rooms : NULL;
            rooms->south = rand() % MAX_PATHS ? rooms : NULL;
            rooms->east = rand() % MAX_PATHS ? rooms : NULL;
            rooms->west = rand() % MAX_PATHS ? rooms : NULL;
        }
    }

    // Connect the rooms
    for (Room* room = rooms; room; room = room->north) {
        if (room->north) {
            room->north->south = room;
        }
        if (room->south) {
            room->south->north = room;
        }
        if (room->east) {
            room->east->west = room;
        }
        if (room->west) {
            room->west->east = room;
        }
    }
}

int main() {
    generateMaze(20);
    return 0;
}