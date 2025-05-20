//FormAI DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40    // Width of the grid
#define HEIGHT 20   // Height of the grid

void printGrid(char *grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", *(grid + (i * WIDTH) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int countAliveNeighbors(char *grid, int x, int y) {
    int i, j, count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if (neighbor_x >= 0 && neighbor_y >= 0 && neighbor_x < HEIGHT && neighbor_y < WIDTH) {
                count += *(grid + (neighbor_x * WIDTH) + neighbor_y);
            }
        }
    }
    count -= *(grid + (x * WIDTH) + y);
    return count;
}

void updateGrid(char *grid) {
    char *newGrid = malloc(WIDTH * HEIGHT * sizeof(char));
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int numNeighborsAlive = countAliveNeighbors(grid, i, j);
            if (*(grid + (i * WIDTH) + j) == 1) {
                if (numNeighborsAlive < 2) {
                    *(newGrid + (i * WIDTH) + j) = 0;
                } else if (numNeighborsAlive == 2 || numNeighborsAlive == 3) {
                    *(newGrid + (i * WIDTH) + j) = 1;
                } else if (numNeighborsAlive > 3) {
                    *(newGrid + (i * WIDTH) + j) = 0;
                }
            } else {
                if (numNeighborsAlive == 3) {
                    *(newGrid + (i * WIDTH) + j) = 1;
                }
            }
        }
    }
    for (i = 0; i < HEIGHT * WIDTH; i++) {
        *(grid + i) = *(newGrid + i);
    }
    free(newGrid);
}

void randomizeGrid(char *grid) {
    int i;
    srand(time(NULL));
    for (i = 0; i < HEIGHT * WIDTH; i++) {
        *(grid + i) = rand() % 2;
    }
}

int main() {
    char *grid = malloc(WIDTH * HEIGHT * sizeof(char));
    randomizeGrid(grid);
    while (1) {
        printf("\033[H\033[J"); // Clear the screen
        printGrid(grid);
        updateGrid(grid);
        usleep(100000); // Sleep for 100 milliseconds
    }
    free(grid);
    return 0;
}