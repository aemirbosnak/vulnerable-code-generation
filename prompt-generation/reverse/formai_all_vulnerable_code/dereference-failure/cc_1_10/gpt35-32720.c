//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// function to print the current state of the grid
void printGrid(int** grid, int rows, int cols) {
    printf("Current State of the Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// function to count the number of alive neighbors for a given cell
int countNeighbors(int** grid, int rows, int cols, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = (row+i+rows) % rows;
            int c = (col+j+cols) % cols;
            if (grid[r][c] == 1 && !(i == 0 && j == 0)) {
                count++;
            }
        }
    }
    return count;
}

// function to apply the rules of the game to a given cell
int applyRules(int** grid, int rows, int cols, int row, int col) {
    int count = countNeighbors(grid, rows, cols, row, col);
    if (grid[row][col] == 1 && (count < 2 || count > 3)) {
        return 0;
    }
    else if (grid[row][col] == 0 && count == 3) {
        return 1;
    }
    else {
        return grid[row][col];
    }
}

// function to iterate through the grid and apply the rules of the game
void step(int** grid, int rows, int cols) {
    int** newGrid = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++) {
        newGrid[i] = (int*)malloc(cols*sizeof(int));
        for (int j = 0; j < cols; j++) {
            newGrid[i][j] = applyRules(grid, rows, cols, i, j);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        free(newGrid[i]);
    }
    free(newGrid);
}

int main() {
    // initialize the grid with random values
    int rows = 10;
    int cols = 10;
    int** grid = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols*sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // run the simulation for 10 iterations
    for (int i = 0; i < 10; i++) {
        printGrid(grid, rows, cols);
        step(grid, rows, cols);
    }
    
    // free memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}