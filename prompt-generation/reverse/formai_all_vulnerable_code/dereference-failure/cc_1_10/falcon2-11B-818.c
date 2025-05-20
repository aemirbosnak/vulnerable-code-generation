//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_maze(int rows, int cols) {
    int i, j, k;
    int* maze = (int*)malloc(rows * cols * sizeof(int));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            maze[i * cols + j] = 0;
        }
    }
    srand(time(NULL));
    for (k = 0; k < rows * cols; k++) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (maze[r * cols + c] == 0) {
            maze[r * cols + c] = 1;
            for (i = r - 1; i >= 0; i--) {
                for (j = c - 1; j >= 0; j--) {
                    maze[i * cols + j] = 1;
                }
            }
            for (i = r + 1; i < rows; i++) {
                for (j = c - 1; j >= 0; j--) {
                    maze[i * cols + j] = 1;
                }
            }
            for (i = r - 1; i >= 0; i--) {
                for (j = c + 1; j < cols; j++) {
                    maze[i * cols + j] = 1;
                }
            }
            for (i = r + 1; i < rows; i++) {
                for (j = c + 1; j < cols; j++) {
                    maze[i * cols + j] = 1;
                }
            }
        }
    }
    printf("Maze: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", maze[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 10, cols = 10;
    generate_maze(rows, cols);
    return 0;
}