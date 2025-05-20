//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdlib.h>
#include <time.h>

// Define the Percolation Simulation Function
void percolate(int **grid, int size) {
    int x, y;
    srand(time(NULL));
    // Randomly activate cells
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (rand() % 2 == 0) {
                grid[x][y] = 1;
            }
        }
    }

    // Spread water upward
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (grid[x][y] == 1) {
                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < size && ny < size && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int size = 20;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    percolate(grid, size);

    // Print the grid
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    return 0;
}