//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 //Size of the grid
#define THRESHOLD 0.6 //Percolation Threshold
#define PARANOID_CHECK 1 //Enable/Disable paranoid check

void printGrid(int** matrix);
int percolates(int** matrix);
void paranoidCheck(int** matrix);

int main() {
    srand(time(NULL)); //Seed the random number generator with time

    int** grid = (int**) malloc(SIZE * sizeof(int*)); //Allocate memory for the grid
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int*) malloc(SIZE * sizeof(int));
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double randomVal = (double) rand() / RAND_MAX; //Generate a random value between 0 and 1

            if (randomVal > THRESHOLD) { //If the random value is greater than the threshold, set the value to 1
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }

    printGrid(grid); //Print the initial grid

    int result = percolates(grid); //Check if the grid percolates
    if (result == 1) {
        printf("Percolates!\n");
    }
    else {
        printf("Does not percolate :(\n");
    }

    paranoidCheck(grid); //Perform a paranoid check

    //Free the memory
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

//Print the grid to the console
void printGrid(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//Check if the grid percolates
int percolates(int** matrix) {
    int topRow[SIZE] = {0}; //Array to keep track of open sites in the top row

    //Check if any sites in the top row are open
    for (int i = 0; i < SIZE; i++) {
        if (matrix[0][i] == 0) {
            topRow[i] = 1;
        }
    }

    //Check if there is a path from any open site in the top row to any open site in the bottom row
    for (int i = 0; i < SIZE; i++) {
        if (topRow[i] == 1) {
            int visited[SIZE] = {0}; //Array to keep track of visited sites

            if (percolatesHelper(matrix, visited, 0, i)) { //If a path is found, return 1
                return 1;
            }
        }
    }

    return 0; //If no path is found, return 0
}

//Recursive helper function for percolates()
int percolatesHelper(int** matrix, int* visited, int row, int col) {
    if (row == SIZE - 1) { //If we have reached the bottom row, return 1
        return 1;
    }

    visited[col] = 1; //Mark current site as visited

    //Check adjacent sites
    if (col > 0 && matrix[row+1][col-1] == 0 && visited[col-1] == 0 && percolatesHelper(matrix, visited, row+1, col-1)) {
        return 1;
    }

    if (matrix[row+1][col] == 0 && visited[col] == 0 && percolatesHelper(matrix, visited, row+1, col)) {
        return 1;
    }

    if (col < SIZE - 1 && matrix[row+1][col+1] == 0 && visited[col+1] == 0 && percolatesHelper(matrix, visited, row+1, col+1)) {
        return 1;
    }

    return 0; //If no path is found, return 0
}

//Perform paranoid check on the grid
void paranoidCheck(int** matrix) {
    if (PARANOID_CHECK == 0) { //If paranoid check is disabled, return
        return;
    }

    int topRow[SIZE] = {0}; //Array to keep track of open sites in the top row
    int bottomRow[SIZE] = {0}; //Array to keep track of open sites in the bottom row

    //Check if any sites in the top and bottom row are open
    for (int i = 0; i < SIZE; i++) {
        if (matrix[0][i] == 0) {
            topRow[i] = 1;
        }

        if (matrix[SIZE-1][i] == 0) {
            bottomRow[i] = 1;
        }
    }

    //Check if there is a path from any open site in the top row to any open site in the bottom row
    for (int i = 0; i < SIZE; i++) {
        if (topRow[i] == 1) {
            int visited[SIZE] = {0}; //Array to keep track of visited sites

            if (paranoidCheckHelper(matrix, visited, 0, i, bottomRow)) { //If a path is found, return
                return;
            }
        }
    }

    printf("Paranoid check failed!\n"); //If no path is found, print a failure message
}

//Recursive helper function for paranoidCheck()
int paranoidCheckHelper(int** matrix, int* visited, int row, int col, int* bottomRow) {
    if (bottomRow[col] == 1) { //If we have reached an open site in the bottom row, return
        return 1;
    }

    visited[col] = 1; //Mark current site as visited

    //Check adjacent sites
    if (col > 0 && matrix[row+1][col-1] == 0 && visited[col-1] == 0 && paranoidCheckHelper(matrix, visited, row+1, col-1, bottomRow)) {
        return 1;
    }

    if (matrix[row+1][col] == 0 && visited[col] == 0 && paranoidCheckHelper(matrix, visited, row+1, col, bottomRow)) {
        return 1;
    }

    if (col < SIZE - 1 && matrix[row+1][col+1] == 0 && visited[col+1] == 0 && paranoidCheckHelper(matrix, visited, row+1, col+1, bottomRow)) {
        return 1;
    }

    return 0; //If no path is found, return 0
}