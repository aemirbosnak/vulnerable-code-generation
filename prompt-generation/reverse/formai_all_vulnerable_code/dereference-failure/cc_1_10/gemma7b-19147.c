//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h) {
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            maze[r][c] = EMPTY_CHAR;
        }
    }

    // Create a random number generator
    srand(time(NULL));

    // Generate the walls
    for (int i = 0; i < 20; i++) {
        int r = rand() % h;
        int c = rand() % w;

        if (maze[r][c] == EMPTY_CHAR) {
            maze[r][c] = WALL_CHAR;
        }
    }

    // Create the exit
    maze[0][0] = EMPTY_CHAR;
}

int main() {
    int **maze = NULL;
    maze = (int **)malloc(MAZE_HEIGHT * sizeof(int *));
    for (int r = 0; r < MAZE_HEIGHT; r++) {
        maze[r] = (int *)malloc(MAZE_WIDTH * sizeof(int));
    }

    generateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    for (int r = 0; r < MAZE_HEIGHT; r++) {
        for (int c = 0; c < MAZE_WIDTH; c++) {
            printf("%c ", maze[r][c]);
        }
        printf("\n");
    }

    return 0;
}