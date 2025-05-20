//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void generateMaze(int **maze, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

int findPath(int **maze, int x, int y, int **path, int size) {
    if (x < 0 || x >= size || y < 0 || y >= size || maze[x][y] == 1 || path[x][y] == 1) {
        return 0;
    }

    path[x][y] = 1;

    if (x == size - 1 && y == size - 1) {
        return 1;
    }

    int direction = rand() % 4;

    switch (direction) {
        case 0:
            return findPath(maze, x - 1, y, path, size);
        case 1:
            return findPath(maze, x, y - 1, path, size);
        case 2:
            return findPath(maze, x + 1, y, path, size);
        case 3:
            return findPath(maze, x, y + 1, path, size);
    }
}

int main() {
    int size = MAX_SIZE;
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    generateMaze(maze, size);

    int **path = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        path[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            path[i][j] = 0;
        }
    }

    findPath(maze, 0, 0, path, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);
    free(path);

    return 0;
}