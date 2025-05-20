//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void generateMaze(int size) {
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        maze[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            maze[i][j] = 0;
        }
    }

    // Create the maze
    int x = size / 2;
    int y = size / 2;
    maze[x][y] = 1;

    // Randomly choose a direction
    int direction = rand() % 4;

    // Dig the tunnel
    switch (direction) {
        case 0:
            while (maze[x][y - 1] != 1) {
                maze[x][y - 1] = 1;
                y--;
            }
            break;
        case 1:
            while (maze[x + 1][y] != 1) {
                maze[x + 1][y] = 1;
                x++;
            }
            break;
        case 2:
            while (maze[x][y + 1] != 1) {
                maze[x][y + 1] = 1;
                y++;
            }
            break;
        case 3:
            while (maze[x - 1][y] != 1) {
                maze[x - 1][y] = 1;
                x--;
            }
            break;
    }

    // Free the memory
    for (int i = 0; i < size; i++) {
        free(maze[i]);
    }
    free(maze);
}

int main() {
    generateMaze(MAX_SIZE);

    return 0;
}