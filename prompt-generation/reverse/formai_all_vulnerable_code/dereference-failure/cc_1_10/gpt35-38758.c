//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants
#define ROWS 10
#define COLS 10
#define OPEN 1
#define BLOCKED 0

// Declare the functions
int** createGrid();
void init(int** grid);
void printGrid(int** grid);
int percolation(int** grid);
int isOpen(int row, int col, int** grid);
int isFull(int row, int col, int** grid);
void dfs(int row, int col, int** grid);
void freeGrid(int** grid);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the grid
    int** grid = createGrid();
    
    // Initialize the grid
    init(grid);
    
    // Print the initial grid
    printf("Initial Grid\n");
    printGrid(grid);
    
    // Run the percolation simulation
    int percolates = percolation(grid);
    
    // Print the final grid
    printf("Final Grid\n");
    printGrid(grid);
    
    // Print the result of the percolation simulation
    if (percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    // Free the memory used by the grid
    freeGrid(grid);
    
    return 0;
}

// Function to create the grid
int** createGrid() {
    // Allocate memory for the grid
    int** grid = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int*)malloc(COLS * sizeof(int));
    }
    
    return grid;
}

// Function to initialize the grid
void init(int** grid) {
    // Set all cells to be blocked
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = BLOCKED;
        }
    }
    
    // Open some cells at random
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % ROWS;
            int c = rand() % COLS;
            if (isOpen(r, c, grid)) {
                continue;
            } else {
                grid[r][c] = OPEN;
            }
        }
    }
    
    // Open the top and bottom rows
    for (int j = 0; j < COLS; j++) {
        grid[0][j] = OPEN;
        grid[ROWS-1][j] = OPEN;
    }
}

// Function to print the grid
void printGrid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OPEN) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to run the percolation simulation
int percolation(int** grid) {
    // Initialize the visited array
    int** visited = createGrid();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Check each cell in the top row
    for (int j = 0; j < COLS; j++) {
        if (isOpen(0, j, grid)) {
            dfs(0, j, visited);
        }
    }
    
    // Check if any cell in the bottom row was visited
    for (int j = 0; j < COLS; j++) {
        if (visited[ROWS-1][j]) {
            freeGrid(visited);
            return 1;
        }
    }
    
    freeGrid(visited);
    return 0;
}

// Function to check if a cell is open
int isOpen(int row, int col, int** grid) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return grid[row][col] == OPEN;
}

// Function to check if a cell is full
int isFull(int row, int col, int** grid) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return grid[row][col] == BLOCKED;
}

// Function to perform DFS on the grid
void dfs(int row, int col, int** visited) {
    // Mark the cell as visited
    visited[row][col] = 1;
    
    // Check the adjacent cells
    if (isOpen(row+1, col, visited) && !visited[row+1][col]) {
        dfs(row+1, col, visited);
    }
    if (isOpen(row-1, col, visited) && !visited[row-1][col]) {
        dfs(row-1, col, visited);
    }
    if (isOpen(row, col+1, visited) && !visited[row][col+1]) {
        dfs(row, col+1, visited);
    }
    if (isOpen(row, col-1, visited) && !visited[row][col-1]) {
        dfs(row, col-1, visited);
    }
}

// Function to free the memory used by the grid
void freeGrid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}