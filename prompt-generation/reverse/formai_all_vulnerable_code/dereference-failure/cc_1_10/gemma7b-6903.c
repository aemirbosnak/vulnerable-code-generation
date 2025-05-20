//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int numRooms) {
    srand(time(NULL));

    Room** maze = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->x = rand() % 20;
        maze[i]->y = rand() % 20;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < numRooms; i++) {
        int randDir = rand() % 4;
        switch (randDir) {
            case 0:
                maze[i]->north = maze[rand() % numRooms];
                break;
            case 1:
                maze[i]->south = maze[rand() % numRooms];
                break;
            case 2:
                maze[i]->east = maze[rand() % numRooms];
                break;
            case 3:
                maze[i]->west = maze[rand() % numRooms];
                break;
        }
    }

    return maze;
}

int main() {
    int numRooms = MAX_Rooms;
    Room** maze = generateMaze(numRooms);

    // Print the maze
    for (int i = 0; i < numRooms; i++) {
        printf("(%d, %d) --> ", maze[i]->x, maze[i]->y);
        if (maze[i]->north) printf("N ");
        if (maze[i]->south) printf("S ");
        if (maze[i]->east) printf("E ");
        if (maze[i]->west) printf("W\n");
    }

    return 0;
}