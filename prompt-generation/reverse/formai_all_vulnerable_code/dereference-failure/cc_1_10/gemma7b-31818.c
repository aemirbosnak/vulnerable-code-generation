//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

void generateMaze(Room* room) {
    int i, j, n, m;
    n = rand() % MAX_Rooms;
    m = rand() % MAX_Rooms;
    room->x = n;
    room->y = m;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;

    if (n > 0) {
        room->north = malloc(sizeof(Room));
        generateMaze(room->north);
    }

    if (m > 0) {
        room->south = malloc(sizeof(Room));
        generateMaze(room->south);
    }

    if (n < MAX_Rooms - 1) {
        room->east = malloc(sizeof(Room));
        generateMaze(room->east);
    }

    if (m < MAX_Rooms - 1) {
        room->west = malloc(sizeof(Room));
        generateMaze(room->west);
    }
}

int main() {
    Room* start = malloc(sizeof(Room));
    generateMaze(start);

    printf("Start at: (%d, %d)\n", start->x, start->y);

    return 0;
}