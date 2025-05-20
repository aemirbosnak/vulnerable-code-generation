//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

// Function to create a percolation matrix
int **createPercolationMatrix(int size, int numIterations) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2; // Randomly initialize matrix elements
        }
    }
    for (int iter = 0; iter < numIterations; iter++) {
        // Apply percolation algorithm
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                int neighbors = 0;
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        if (i + k >= 0 && j + l >= 0 && i + k < size && j + l < size) {
                            neighbors++;
                        }
                    }
                }
                if (rand() % 2 == 0 && (neighbors == 2 || neighbors == 3)) {
                    matrix[i][j] = 1; // Percolate if conditions are met
                }
            }
        }
    }
    return matrix;
}

// Function to print the percolation matrix
void printPercolationMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 50; // Size of the percolation matrix
    int numIterations = 100; // Number of iterations for the percolation algorithm
    srand(time(NULL)); // Seed the random number generator

    // Create the percolation matrix
    int **matrix = createPercolationMatrix(size, numIterations);

    // Print the percolation matrix
    printf("Percolation Matrix:\n");
    printPercolationMatrix(matrix, size);

    return 0;
}