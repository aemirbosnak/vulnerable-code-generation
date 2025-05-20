//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_ROOM_SIZE 10

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

typedef struct Room {
    int x, y;
    struct Room *north, *east, *south, *west;
} Room;

Room **generate_maze(int seed, int room_count) {
    srand(seed);
    int i, j, n;
    Room **rooms = malloc(room_count * sizeof(Room *));
    for (i = 0; i < room_count; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % MAX_ROOM_SIZE;
        rooms[i]->y = rand() % MAX_ROOM_SIZE;
        rooms[i]->north = NULL;
        rooms[i]->east = NULL;
        rooms[i]->south = NULL;
        rooms[i]->west = NULL;
    }

    for (n = 0; n < room_count - 1; n++) {
        i = rand() % room_count;
        j = rand() % room_count;
        if (i != j) {
            rooms[i]->north = rooms[j];
            rooms[j]->south = rooms[i];
        }
    }

    return rooms;
}

int main() {
    int seed = time(NULL);
    int room_count = 20;
    Room **maze = generate_maze(seed, room_count);

    // Print the maze
    for (int i = 0; i < room_count; i++) {
        printf("(%d, %d) ", maze[i]->x, maze[i]->y);
        if (maze[i]->north) printf("N ");
        if (maze[i]->east) printf("E ");
        if (maze[i]->south) printf("S ");
        if (maze[i]->west) printf("W ");
        printf("\n");
    }

    return 0;
}