//LLAMA2-13B DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

void print_grid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** grid;
    int rows, cols;

    // Initialize grid with random values
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        grid = (int**)realloc(grid, (i + 1) * sizeof(int*) + (i + 1) * sizeof(int));
        for (int j = 0; j < i + 1; j++) {
            grid[j] = (int*)calloc(i + 1, sizeof(int));
            for (int k = 0; k < i + 1; k++) {
                grid[j][k] = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
            }
        }
    }

    // Print grid
    print_grid(grid, 10, 10);

    // Get user input
    printf("Enter row and column: ");
    int row, col;
    scanf("%d%d", &row, &col);

    // Check if input is valid
    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Get value at specified position
    int value = grid[row][col];

    // Increment value by 10
    value += 10;

    // Check if value is now negative
    if (value < 0) {
        value = 0;
    }

    // Set value at specified position to new value
    grid[row][col] = value;

    // Print updated grid
    print_grid(grid, 10, 10);

    // Free memory
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}