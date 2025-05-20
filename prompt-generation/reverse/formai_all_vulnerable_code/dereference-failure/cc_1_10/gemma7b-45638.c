//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h) {
    int x, y;
    srand(time(NULL));
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            maze[x][y] = EMPTY_CHAR + rand() % 2;
        }
    }
}

void printMaze(int **maze, int w, int h) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int **maze;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int **)malloc(w * sizeof(int *));
    for (int i = 0; i < w; i++) {
        maze[i] = (int *)malloc(h * sizeof(int));
    }

    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    for (int i = 0; i < w; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}