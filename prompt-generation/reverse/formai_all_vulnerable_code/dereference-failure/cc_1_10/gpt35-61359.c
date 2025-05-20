//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the 2D grid with random values
void initialize(int** grid, int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int rand_val = rand() % 2;
            grid[i][j] = rand_val;
        }
    }
}

// function to print the current state of the grid
void print_grid(int** grid, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// recursive function to check if a cell can percolate to the bottom
// returns 1 if it can percolate, 0 if it cannot
int percolate(int** grid, int n, int i, int j, int visited[][n]) {
    // base case
    if(i<0 || j<0 || i>=n || j>=n || visited[i][j] || !grid[i][j]) {
        return 0;
    }
    // mark the current cell as visited
    visited[i][j] = 1;
    // if the current cell is in the bottom row and has a value of 1, it can percolate
    if(i == n-1 && grid[i][j]) {
        return 1;
    }
    // recursive calls to check all neighbours
    int result1 = percolate(grid, n, i+1, j, visited); // down
    int result2 = percolate(grid, n, i, j+1, visited); // right
    int result3 = percolate(grid, n, i-1, j, visited); // up
    int result4 = percolate(grid, n, i, j-1, visited); // left
    // if any neighbour can percolate, the current cell can also percolate
    if(result1 || result2 || result3 || result4) {
        return 1;
    }
    // the current cell cannot percolate
    return 0;
}

int main() {
    int n = 5; // size of the grid
    int** grid = (int**) malloc(n * sizeof(int*));
    for(int i=0; i<n; i++) {
        grid[i] = (int*) malloc(n * sizeof(int));
    }
    initialize(grid, n); // initialize the grid with random values
    print_grid(grid, n); // print the initial grid
    printf("\n");
    int visited[n][n];
    // initialize visited matrix with 0's
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }
    // check if any cell in the top row can percolate to the bottom
    int percolates = 0;
    for(int j=0; j<n; j++) {
        if(percolate(grid, n, 0, j, visited)) {
            percolates = 1;
            break;
        }
    }
    if(percolates) {
        printf("The liquid can percolate through the grid.");
    }
    else {
        printf("The liquid cannot percolate through the grid.");
    }
    return 0;
}