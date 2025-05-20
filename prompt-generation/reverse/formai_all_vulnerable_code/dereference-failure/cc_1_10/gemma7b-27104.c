//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PATH 2

void generateMaze(int **maze, int w, int h) {
    int i, j, r, c;
    srand(time(NULL));

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            maze[i][j] = EMPTY;
        }
    }

    r = rand() % h;
    c = rand() % w;

    maze[r][c] = PATH;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (maze[i][j] == EMPTY && (i == r || j == c)) {
                maze[i][j] = WALL;
            }
        }
    }
}

int main() {
    int **maze;
    maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}