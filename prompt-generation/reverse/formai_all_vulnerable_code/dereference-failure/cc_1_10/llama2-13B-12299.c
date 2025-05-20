//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_ERROR 50

// Function to read a matrix from the user
void readMatrix(int **matrix, int *size) {
    int i, j;
    for (i = 0; i < *size; i++) {
        for (j = 0; j < *size; j++) {
            printf("Enter element %d, %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0) {
                printf("Error: Matrix must not contain zero elements\n");
                return;
            }
        }
    }
}

// Function to calculate the determinant of a matrix
double determinant(int **matrix, int size) {
    int i, j;
    double det = 1;
    for (i = 0; i < size; i++) {
        det *= matrix[i][i];
        for (j = i + 1; j < size; j++) {
            det -= matrix[i][j] * matrix[j][i];
        }
    }
    return det;
}

int main() {
    int size, i, j;
    int **matrix;

    // Check if the user wants to continue
    while (1) {
        printf("Do you want to continue? (y/n): ");
        char choice = getchar();
        if (choice == 'n') {
            break;
        }

        // Read the matrix from the user
        readMatrix(matrix, &size);

        // Calculate the determinant of the matrix
        double det = determinant(matrix, size);

        // Check if the determinant is zero
        if (fabs(det) < 1e-6) {
            printf("Error: Determinant is zero\n");
            continue;
        }

        // Print the result
        printf("The determinant of the matrix is %f\n", det);
    }

    return 0;
}