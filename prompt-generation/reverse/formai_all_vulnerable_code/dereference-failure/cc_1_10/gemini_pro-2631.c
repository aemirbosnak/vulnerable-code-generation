//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 20
#define NEIGHBORS 8

typedef struct {
    int x;
    int y;
} point;

// Create a new grid
int** create_grid() {
    int** grid = (int**)malloc(GRID_SIZE * sizeof(int*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (int*)malloc(GRID_SIZE * sizeof(int));
    }
    return grid;
}

// Free the grid
void free_grid(int** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Initialize the grid with random values
void init_grid(int** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid
void print_grid(int** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

// Count the number of neighbors of a cell
int count_neighbors(int** grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}

// Update the grid according to the rules of the Game of Life
void update_grid(int** grid) {
    int** new_grid = create_grid();
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    free_grid(grid);
    grid = new_grid;
}

int main() {
    srand(time(NULL));
    int** grid = create_grid();
    init_grid(grid);
    print_grid(grid);
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    free_grid(grid);
    return 0;
}