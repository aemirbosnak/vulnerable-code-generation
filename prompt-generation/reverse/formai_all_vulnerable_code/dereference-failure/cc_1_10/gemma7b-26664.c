//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

int main() {
    int **maze = NULL;
    int x, y, seed;

    seed = time(NULL);
    srand(seed);

    maze = malloc(MAZE_HEIGHT * sizeof(int *));
    for (y = 0; y < MAZE_HEIGHT; y++) {
        maze[y] = malloc(MAZE_WIDTH * sizeof(int));
        for (x = 0; x < MAZE_WIDTH; x++) {
            maze[y][x] = EMPTY;
        }
    }

    // Generate the maze
    for (y = 0; y < MAZE_HEIGHT; y++) {
        for (x = 0; x < MAZE_WIDTH; x++) {
            if (rand() % 2 == 0) {
                maze[y][x] = WALL;
            }
        }
    }

    // Print the maze
    for (y = 0; y < MAZE_HEIGHT; y++) {
        for (x = 0; x < MAZE_WIDTH; x++) {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (y = 0; y < MAZE_HEIGHT; y++) {
        free(maze[y]);
    }
    free(maze);

    return 0;
}