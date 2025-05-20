//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Paths 5

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int numRooms) {
    srand(time(NULL));
    Room** maze = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->x = rand() % MAX_Rooms;
        maze[i]->y = rand() % MAX_Rooms;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < numRooms - 1; i++) {
        int roomA = rand() % numRooms;
        int roomB = rand() % numRooms;
        if (roomA != roomB) {
            maze[roomA]->east = maze[roomB];
            maze[roomB]->west = maze[roomA];
        }
    }

    return maze;
}

int main() {
    Room** maze = generateMaze(MAX_Rooms);
    for (int i = 0; i < MAX_Rooms; i++) {
        printf("Room (%d, %d)\n", maze[i]->x, maze[i]->y);
        if (maze[i]->north) {
            printf("North: Room (%d, %d)\n", maze[i]->north->x, maze[i]->north->y);
        }
        if (maze[i]->south) {
            printf("South: Room (%d, %d)\n", maze[i]->south->x, maze[i]->south->y);
        }
        if (maze[i]->east) {
            printf("East: Room (%d, %d)\n", maze[i]->east->x, maze[i]->east->y);
        }
        if (maze[i]->west) {
            printf("West: Room (%d, %d)\n", maze[i]->west->x, maze[i]->west->y);
        }
    }

    return 0;
}