//FormAI DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print the current state of the grid
void print_grid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

//Function to count the number of live neighbors of a cell
int count_live_neighbors(int** grid, int row, int col, int rows, int cols) {
    int count = 0;

    //Checking the 8 neighbors of a cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int r = row + i;
            int c = col + j;

            //Checking if the neighbor is within bounds and is a live cell
            if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1) {
                count++;
            }
        }
    }

    return count;
}

//Function to update the grid according to the rules of the Game of Life
void update_grid(int** grid, int rows, int cols) {
    int** new_grid = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (int*) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int live_neighbors = count_live_neighbors(grid, i, j, rows, cols);

            if (grid[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (live_neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        free(new_grid[i]);
    }
    free(new_grid);
}

int main() {
    //Initializing the grid
    int rows = 10;
    int cols = 10;
    int** grid = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*) malloc(cols * sizeof(int));
    }

    //Setting random values for the grid
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    //Printing the initial state of the grid
    printf("Initial grid:\n");
    print_grid(grid, rows, cols);

    //Simulating the Game of Life
    int num_iterations = 10;
    for (int i = 1; i <= num_iterations; i++) {
        printf("Iteration %d:\n", i);
        update_grid(grid, rows, cols);
        print_grid(grid, rows, cols);
    }

    //Freeing the memory allocated for the grid
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}