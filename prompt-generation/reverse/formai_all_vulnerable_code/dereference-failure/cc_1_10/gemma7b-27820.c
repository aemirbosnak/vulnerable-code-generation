//Gemma-7B DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of integers
    int **grid = NULL;
    grid = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        grid[i] = (int*)malloc(5 * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = 0;
        }
    }

    // Place the treasure
    grid[2][2] = 100;

    // The player's turn
    int x, y;
    printf("Enter the coordinates of your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Check if the move is valid
    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        printf("Invalid move.\n");
    } else if (grid[x][y] != 0) {
        printf("There is already a treasure there.\n");
    } else {
        // The player has found the treasure
        grid[x][y] = 1;
        printf("You have found the treasure!\n");
    }

    // Free the memory
    for (int i = 0; i < 5; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}