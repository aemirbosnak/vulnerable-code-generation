//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h) {
    int i, j;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            maze[i][j] = EMPTY_CHAR;
        }
    }

    // Generate walls randomly
    for (i = 0; i < w * h; i++) {
        int x = rand() % w;
        int y = rand() % h;

        if (maze[y][x] == EMPTY_CHAR) {
            maze[y][x] = WALL_CHAR;
        }
    }
}

int main() {
    int **maze;
    int w, h;

    // Initialize the maze dimensions
    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    // Allocate memory for the maze
    maze = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        maze[i] = (int *)malloc(w * sizeof(int));
    }

    // Generate the maze
    generate_maze(maze, w, h);

    // Print the maze
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}