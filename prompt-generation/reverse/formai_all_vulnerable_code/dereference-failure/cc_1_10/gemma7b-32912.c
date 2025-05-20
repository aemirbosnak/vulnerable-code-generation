//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL 1
#define EMPTY 0

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void generateMaze(int** maze, int w, int h) {
    srand(time(NULL));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maze[y][x] = EMPTY;
        }
    }

    for (int i = 0; i < 10; i++) {
        int x = rand() % w;
        int y = rand() % h;
        maze[y][x] = WALL;
    }
}

void printMaze(int** maze, int w, int h) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    generateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
    printMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    free(maze);
    return 0;
}