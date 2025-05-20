//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to print spiral pattern in 2D array
void print_spiral(int **matrix, int rows, int cols) {
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int direction = 1;

    printf("Spiral Pattern:\n");

    while (top <= bottom && left <= right) {
        // Print column from left to right
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Check if we have reached the end of the row
        if (top <= bottom) {
            // Print row from top to bottom
            for (int i = top; i <= bottom; i++) {
                printf("%d ", matrix[i][right]);
            }
            right--;
        }

        // Check if we have reached the end of the matrix
        if (left < right) {
            // Print column from right to left
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Check if we have reached the end of the matrix
        if (top < bottom) {
            // Print row from bottom to top
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    printf("\n");
}

// Function to initialize 2D array with random values
void initialize_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Main function
int main() {
    int rows = 5;
    int cols = 5;
    int **matrix;

    // Allocate memory for 2D array
    matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
    }

    // Initialize 2D array with random values
    initialize_matrix(matrix, rows, cols);

    // Print spiral pattern
    print_spiral(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}