//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD ' '

void allocate_grid(char ***grid, int rows, int cols) {
    *grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        (*grid)[i] = malloc(cols * sizeof(char));
        memset((*grid)[i], DEAD, cols * sizeof(char));
    }
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

void display_grid(char **grid, int rows, int cols) {
    printf("\nCurrent Generation:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char **grid, int rows, int cols, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i, nj = y + j;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void evolve(char **grid, char **new_grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(grid, rows, cols, i, j);
            if (grid[i][j] == ALIVE) {
                new_grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int main(void) {
    int rows, cols, generations;

    printf("Enter the number of rows for the grid: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the grid: ");
    scanf("%d", &cols);
    printf("Enter the number of generations to evolve: ");
    scanf("%d", &generations);

    char **grid = NULL;
    char **new_grid = NULL;

    allocate_grid(&grid, rows, cols);
    allocate_grid(&new_grid, rows, cols);

    // Initial configuration
    printf("Enter the initial configuration (O for alive, space for dead):\n");
    for (int i = 0; i < rows; i++) {
        getchar(); // Clear newline from input buffer
        for (int j = 0; j < cols; j++) {
            new_grid[i][j] = getchar();
        }
    }

    display_grid(new_grid, rows, cols);

    for (int gen = 0; gen < generations; gen++) {
        evolve(new_grid, grid, rows, cols);
        display_grid(grid, rows, cols);
        // Swap grids for next iteration
        char **temp = grid;
        grid = new_grid;
        new_grid = temp;
        usleep(500000); // Pause for 0.5 seconds
    }

    free_grid(grid, rows);
    free_grid(new_grid, rows);
    
    return 0;
}