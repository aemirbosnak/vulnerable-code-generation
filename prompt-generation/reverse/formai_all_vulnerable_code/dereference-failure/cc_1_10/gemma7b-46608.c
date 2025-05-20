//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void generateMaze(int **maze, int size) {
    int i, j, x, y;
    srand(time(NULL));

    for (i = 0; i < size; i++) {
        maze[i] = (int *)malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            maze[i][j] = 0;
        }
    }

    x = rand() % size;
    y = rand() % size;
    maze[x][y] = 1;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (maze[i][j] == 0) {
                if (i > 0 && maze[i - 1][j] == 1) {
                    maze[i][j] = 2;
                } else if (j > 0 && maze[i][j - 1] == 1) {
                    maze[i][j] = 2;
                } else if (i < size - 1 && maze[i + 1][j] == 1) {
                    maze[i][j] = 2;
                } else if (j < size - 1 && maze[i][j + 1] == 1) {
                    maze[i][j] = 2;
                }
            }
        }
    }
}

int main() {
    int size = MAX_SIZE;
    int **maze = NULL;

    generateMaze(&maze, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}