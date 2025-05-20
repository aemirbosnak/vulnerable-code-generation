//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the matrix
#define N 10

// Define the maximum value for the matrix elements
#define MAX_VALUE 100

// Generate a random matrix
int **generate_matrix(void) {
    int **matrix = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }
    return matrix;
}

// Print the matrix
void print_matrix(int **matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the matrix
void free_matrix(int **matrix) {
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main(void) {
    // Set the random seed
    srand(time(NULL));

    // Generate the matrix
    int **matrix = generate_matrix();

    // Print the matrix
    printf("Generated matrix:\n");
    print_matrix(matrix);

    // Calculate the sum of the elements in the matrix
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }

    // Print the sum of the elements in the matrix
    printf("Sum of the elements in the matrix: %d\n", sum);

    // Free the matrix
    free_matrix(matrix);

    return 0;
}