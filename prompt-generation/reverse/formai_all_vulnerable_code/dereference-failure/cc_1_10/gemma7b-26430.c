//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 20
#define MAX_PATHS 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
    srand(time(NULL));
    Room** maze = malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->x = rand() % size;
        maze[i]->y = rand() % size;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < size; i++) {
        int numPaths = rand() % MAX_PATHS;
        for (int j = 0; j < numPaths; j++) {
            switch (rand() % 4) {
                case 0:
                    maze[i]->north = maze[rand() % MAX_ROOMS];
                    break;
                case 1:
                    maze[i]->south = maze[rand() % MAX_ROOMS];
                    break;
                case 2:
                    maze[i]->east = maze[rand() % MAX_ROOMS];
                    break;
                case 3:
                    maze[i]->west = maze[rand() % MAX_ROOMS];
                    break;
            }
        }
    }

    return maze;
}

int main() {
    int size = 10;
    Room** maze = generateMaze(size);

    // Print the maze
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%p ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}