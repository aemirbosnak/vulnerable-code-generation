//FormAI DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include<stdio.h>

// Function to print the matrix
void printMatrix(int** matrix, int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int** matrix1, int** matrix2, int rows, int cols) {
    int sumMatrix[rows][cols];

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Matrix addition result:\n");
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrix(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int productMatrix[rows1][cols2];

    for(int i=0;i<rows1;i++) {
        for(int j=0;j<cols2;j++) {
            productMatrix[i][j] = 0;
            for(int k=0;k<cols1;k++) {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Matrix multiplication result:\n");
    for(int i=0;i<rows1;i++) {
        for(int j=0;j<cols2;j++) {
            printf("%d ", productMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input for matrix 1
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    int** matrix1 = (int **)calloc(rows1, sizeof(int *));
    for(int i=0;i<rows1;i++) {
        matrix1[i] = (int *)calloc(cols1, sizeof(int));
    }

    printf("Enter the elements of matrix 1:\n");
    for(int i=0;i<rows1;i++) {
        for(int j=0;j<cols1;j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input for matrix 2
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    int** matrix2 = (int **)calloc(rows2, sizeof(int *));
    for(int i=0;i<rows2;i++) {
        matrix2[i] = (int *)calloc(cols2, sizeof(int));
    }

    printf("Enter the elements of matrix 2:\n");
    for(int i=0;i<rows2;i++) {
        for(int j=0;j<cols2;j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Performing matrix operations
    if(rows1 != rows2 || cols1 != cols2) {
        printf("Matrix addition not possible\n");
    } else {
        addMatrix(matrix1, matrix2, rows1, cols1);
    }

    if(cols1 != rows2) {
        printf("Matrix multiplication not possible\n");
    } else {
        multiplyMatrix(matrix1, matrix2, rows1, cols1, cols2);
    }

    // Freeing the dynamically allocated memory
    for(int i=0;i<rows1;i++) {
        free(matrix1[i]);
    }
    for(int i=0;i<rows2;i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    
    return 0;
}