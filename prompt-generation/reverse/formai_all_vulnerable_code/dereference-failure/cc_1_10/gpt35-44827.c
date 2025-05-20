//FormAI DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int **addMatrix(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *)); // Allocate memory for result matrix
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Add two matrices
        }
    }
    return result;
}

// Function to multiply two matrices
int **multiplyMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Matrices cannot be multiplied!\n"); // Check if matrices can be multiplied
        exit(1);
    }
    int **result = (int **)malloc(rows1 * sizeof(int *)); // Allocate memory for result matrix
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply two matrices
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Get dimensions of first matrix
    printf("Enter dimensions of first matrix:\n");
    printf("Number of rows: ");
    scanf("%d", &rows1);
    printf("Number of columns: ");
    scanf("%d", &cols1);

    // Allocate memory for first matrix
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // Get elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get dimensions of second matrix
    printf("Enter dimensions of second matrix:\n");
    printf("Number of rows: ");
    scanf("%d", &rows2);
    printf("Number of columns: ");
    scanf("%d", &cols2);

    // Allocate memory for second matrix
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Get elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nFirst matrix:\n");
    printMatrix(matrix1, rows1, cols1); // Print first matrix
    printf("\nSecond matrix:\n");
    printMatrix(matrix2, rows2, cols2); // Print second matrix

    int choice;

    do {
        // Get operation choice from user
        printf("\nChoose an operation:\n");
        printf("[1] Add matrices\n");
        printf("[2] Multiply matrices\n");
        printf("[3] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows1 == rows2 && cols1 == cols2) { // Check if matrices can be added
                    int **sum = addMatrix(matrix1, matrix2, rows1, cols1); // Add matrices
                    printf("\nSum of matrices:\n");
                    printMatrix(sum, rows1, cols1); // Print result
                    for (int i = 0; i < rows1; i++) {
                        free(sum[i]); // Free memory allocated for sum matrix
                    }
                    free(sum);
                } else {
                    printf("Error: Matrices cannot be added!\n");
                }
                break;
            case 2:
                if (cols1 == rows2) { // Check if matrices can be multiplied
                    int **product = multiplyMatrix(matrix1, matrix2, rows1, cols1, rows2, cols2); // Multiply matrices
                    printf("\nProduct of matrices:\n");
                    printMatrix(product, rows1, cols2); // Print result
                    for (int i = 0; i < rows1; i++) {
                        free(product[i]); // Free memory allocated for product matrix
                    }
                    free(product);
                } else {
                    printf("Error: Matrices cannot be multiplied!\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]); // Free memory allocated for first matrix
    }
    free(matrix1);
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]); // Free memory allocated for second matrix
    }
    free(matrix2);

    return 0;
}