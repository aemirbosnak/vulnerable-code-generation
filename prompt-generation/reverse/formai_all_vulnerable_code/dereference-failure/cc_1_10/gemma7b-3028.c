//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

int main() {
    int x, y, seed;

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Create the maze
    int **maze = (int **)malloc(MAZE_HEIGHT * sizeof(int *));
    for (x = 0; x < MAZE_HEIGHT; x++) {
        maze[x] = (int *)malloc(MAZE_WIDTH * sizeof(int));
        for (y = 0; y < MAZE_WIDTH; y++) {
            maze[x][y] = EMPTY_CHAR;
        }
    }

    // Dig the maze
    for (x = 0; x < MAZE_HEIGHT; x++) {
        for (y = 0; y < MAZE_WIDTH; y++) {
            if (rand() % 2 == 0) {
                maze[x][y] = WALL_CHAR;
            }
        }
    }

    // Print the maze
    for (x = 0; x < MAZE_HEIGHT; x++) {
        for (y = 0; y < MAZE_WIDTH; y++) {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    // Free the maze
    for (x = 0; x < MAZE_HEIGHT; x++) {
        free(maze[x]);
    }
    free(maze);

    return 0;
}