//GEMINI-pro DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the number of rows and columns in the matrix
#define ROWS 3
#define COLS 3

// Function to generate a random matrix
int** generate_matrix(int rows, int cols) {
    // Allocate memory for the matrix
    int** matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // Initialize the matrix with random values
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    return matrix;
}

// Function to print the matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the saddle point in the matrix
int find_saddle_point(int** matrix, int rows, int cols) {
    // Initialize the saddle point to -1
    int saddle_point = -1;

    // Iterate over each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Check if the current element is the minimum in its row
            int is_row_min = 1;
            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] < matrix[i][j]) {
                    is_row_min = 0;
                    break;
                }
            }

            // Check if the current element is the maximum in its column
            int is_col_max = 1;
            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] > matrix[i][j]) {
                    is_col_max = 0;
                    break;
                }
            }

            // If the current element is both the minimum in its row and the maximum in its column, it is a saddle point
            if (is_row_min && is_col_max) {
                saddle_point = matrix[i][j];
                break;
            }
        }
    }

    return saddle_point;
}

int main() {
    // Generate a random matrix
    int** matrix = generate_matrix(ROWS, COLS);

    // Print the matrix
    printf("Generated matrix:\n");
    print_matrix(matrix, ROWS, COLS);

    // Find the saddle point in the matrix
    int saddle_point = find_saddle_point(matrix, ROWS, COLS);

    // Print the saddle point
    if (saddle_point == -1) {
        printf("No saddle point found in the matrix.\n");
    } else {
        printf("Saddle point: %d\n", saddle_point);
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}