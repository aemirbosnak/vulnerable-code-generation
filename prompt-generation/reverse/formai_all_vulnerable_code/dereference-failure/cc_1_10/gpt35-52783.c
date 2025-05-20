//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void fractal(int level, int row, int col, int size, char** grid) {
    if (level == 0) { // base case to fill in center cell
        grid[row][col] = '*';
        return;
    }
    
    int subsize = size / 3;
    fractal(level - 1, row, col, subsize, grid); // top left
    fractal(level - 1, row, col + subsize, subsize, grid); // top center
    fractal(level - 1, row, col + 2 * subsize, subsize, grid); // top right
    fractal(level - 1, row + subsize, col, subsize, grid); // middle left
    // middle center is skipped since it should be blank
    fractal(level - 1, row + subsize, col + 2 * subsize, subsize, grid); // middle right
    fractal(level - 1, row + 2 * subsize, col, subsize, grid); // bottom left
    fractal(level - 1, row + 2 * subsize, col + subsize, subsize, grid); // bottom center
    fractal(level - 1, row + 2 * subsize, col + 2 * subsize, subsize, grid); // bottom right
}

int main() {
    int n;
    printf("Enter the level of the fractal (1 - 5): ");
    scanf("%d", &n);

    int size = 1;
    for (int i = 0; i < n; i++) size *= 3;

    char** grid = (char**)malloc(size * sizeof(char*)); // create grid
    for (int i = 0; i < size; i++) {
        grid[i] = (char*)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            grid[i][j] = ' ';
        }
    }

    fractal(n, 0, 0, size, grid);

    // print out grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}