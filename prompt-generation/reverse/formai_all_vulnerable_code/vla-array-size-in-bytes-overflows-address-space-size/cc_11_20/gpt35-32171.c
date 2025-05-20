//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to the matrix operations program!\n\n");

    int rows, cols;
    printf("Enter number of rows in matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns in matrix: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nYour matrix is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int choice;
    printf("\nChoose the operation you want to perform:\n1. Matrix Transpose\n2. Matrix Multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Matrix Transpose
        {
            int transpose[cols][rows];
            for(int i = 0; i < cols; i++) {
                for(int j = 0; j < rows; j++) {
                    transpose[i][j] = matrix[j][i];
                }
            }

            printf("\nTranspose of your matrix is:\n");
            for(int i = 0; i < cols; i++) {
                for(int j = 0; j < rows; j++) {
                    printf("%d ", transpose[i][j]);
                }
                printf("\n");
            }
            break;
        }

        case 2: // Matrix Multiplication
        {
            int mcols;
            printf("\nEnter number of columns in second matrix: ");
            scanf("%d", &mcols);

            int matrix2[cols][mcols];
            printf("\nEnter second matrix elements:\n");
            for(int i = 0; i < cols; i++) {
                for(int j = 0; j < mcols; j++) {
                    printf("Enter element [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matrix2[i][j]);
                }
            }

            int result[rows][mcols];
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < mcols; j++) {
                    result[i][j] = 0;
                    for(int k = 0; k < cols; k++) {
                        result[i][j] += matrix[i][k] * matrix2[k][j];
                    }
                }
            }

            printf("\nResult of matrix multiplication:\n");
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < mcols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        }

        default: // Invalid choice
            printf("\nInvalid choice! Please choose either 1 or 2.\n");
    }

    return 0;
}