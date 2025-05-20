//FormAI DATASET v1.0 Category: Game of Life ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to randomly generate the initial state of the grid
void initGrid(int** grid, int rows, int cols) {
    srand(time(0));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i][j] = (rand()%2 == 0 ? 0 : 1);
        }
    }
}

// Function to print the state of the grid
void printGrid(int** grid, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c ", (grid[i][j] == 1 ? 'O' : ' '));
        }
        printf("\n");
    }
}

// Function to count the number of alive neighbors of a cell
int countNeighbors(int** grid, int x, int y, int rows, int cols) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            int newX = (x+i+rows)%rows;
            int newY = (y+j+cols)%cols;
            if(grid[newX][newY] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to simulate one step of the Game of Life
void simulateStep(int** grid, int rows, int cols) {
    int** newGrid = (int**)malloc(rows*sizeof(int*));
    for(int i=0; i<rows; i++) {
        newGrid[i] = (int*)malloc(cols*sizeof(int));
        for(int j=0; j<cols; j++) {
            // Count the number of alive neighbors of the cell
            int count = countNeighbors(grid, i, j, rows, cols);
            // Apply the rules of the Game of Life
            if(grid[i][j] == 0 && count == 3) {
                newGrid[i][j] = 1;
            }
            else if(grid[i][j] == 1 && (count < 2 || count > 3)) {
                newGrid[i][j] = 0;
            }
            else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    // Update the grid
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
    // Free the memory used by the new grid
    for(int i=0; i<rows; i++) {
        free(newGrid[i]);
    }
    free(newGrid);
}

int main() {
    int rows, cols, steps;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int** grid = (int**)malloc(rows*sizeof(int*));
    for(int i=0; i<rows; i++) {
        grid[i] = (int*)malloc(cols*sizeof(int));
    }
    // Initialize the grid
    initGrid(grid, rows, cols);
    // Print the initial state of the grid
    printf("Initial state:\n");
    printGrid(grid, rows, cols);
    // Ask the user for the number of steps to simulate
    printf("Enter the number of steps to simulate: ");
    scanf("%d", &steps);
    // Simulate the Game of Life for the specified number of steps
    for(int i=1; i<=steps; i++) {
        printf("Step %d:\n", i);
        simulateStep(grid, rows, cols);
        printGrid(grid, rows, cols);
    }
    // Free the memory used by the grid
    for(int i=0; i<rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}