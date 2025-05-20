//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(int **maze, int w, int h) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            maze[i][j] = EMPTY;
        }
    }

    for (i = 0; i < 10; i++) {
        int x = rand() % w;
        int y = rand() % h;
        maze[y][x] = WALL;
    }
}

void printMaze(int **maze, int w, int h) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = NULL;
    int w = MAZE_WIDTH;
    int h = MAZE_HEIGHT;

    maze = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        maze[i] = (int*)malloc(w * sizeof(int));
    }

    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    free(maze);
    return 0;
}