//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int size, i, j, count = 0;
    int **grid;
    int *row;

    // Initialize random seed
    srand(time(NULL));

    // Ask user for grid size
    printf("Enter grid size (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Create grid
    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize grid with random values
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Print initial grid
    printf("\nInitial grid:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Percolate grid
    for (i = 0; i < size; i++) {
        row = grid[i];
        for (j = 0; j < size; j++) {
            if (row[j] == 1) {
                count++;
            }
        }
    }

    printf("\nNumber of sites percolated: %d\n", count);

    return 0;
}