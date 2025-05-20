//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL 1
#define EMPTY 0

void generateMaze(int **maze, int w, int h) {
    srand(time(NULL));
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            maze[r][c] = EMPTY;
        }
    }

    int numWalls = 50;
    for (int i = 0; i < numWalls; i++) {
        int x1 = rand() % w;
        int y1 = rand() % h;
        int x2 = rand() % w;
        int y2 = rand() % h;

        if (x1 == x2) {
            maze[y1][x1] = WALL;
        } else if (y1 == y2) {
            maze[y1][x2] = WALL;
        } else {
            maze[y1][x2] = WALL;
            maze[y2][x1] = WALL;
        }
    }
}

int main() {
    int **maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++) {
        maze[r] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}