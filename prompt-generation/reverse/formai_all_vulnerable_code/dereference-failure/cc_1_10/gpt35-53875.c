//FormAI DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to print matrix
void printMatrix(int** mat, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrix(int** mat1, int** mat2, int rows, int cols) {
    int** resultMat = (int**)malloc(rows * sizeof(int*));
    int i, j;
    for (i = 0; i < rows; i++) {
        resultMat[i] = (int*)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            resultMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return resultMat;
}

// Function to multiply two matrices
int** multiplyMatrix(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Invalid matrices dimensions for multiplication\n");
        return NULL;
    }
    int** resultMat = (int**)malloc(rows1 * sizeof(int*));
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        resultMat[i] = (int*)malloc(cols2 * sizeof(int));
        for (j = 0; j < cols2; j++) {
            resultMat[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                resultMat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return resultMat;
}

// Main function
int main() {
    int rows1, cols1, rows2, cols2, i, j;
    printf("Enter rows and cols of matrix1: ");
    scanf("%d %d", &rows1, &cols1);
    int** mat1 = (int**)malloc(rows1 * sizeof(int*));
    for (i = 0; i < rows1; i++) {
        mat1[i] = (int*)malloc(cols1 * sizeof(int));
        for (j = 0; j < cols1; j++) {
            printf("Enter value at row %d column %d: ", i+1, j+1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter rows and cols of matrix2: ");
    scanf("%d %d", &rows2, &cols2);
    int** mat2 = (int**)malloc(rows2 * sizeof(int*));
    for (i = 0; i < rows2; i++) {
        mat2[i] = (int*)malloc(cols2 * sizeof(int));
        for (j = 0; j < cols2; j++) {
            printf("Enter value at row %d column %d: ", i+1, j+1);
            scanf("%d", &mat2[i][j]);
        }
    }
    // Printing original matrices
    printf("\nOriginal matrix1:\n");
    printMatrix(mat1, rows1, cols1);
    printf("Original matrix2:\n");
    printMatrix(mat2, rows2, cols2);

    // Adding matrices
    int** sumMat = addMatrix(mat1, mat2, rows1, cols1);
    printf("\nSum of matrices:\n");
    printMatrix(sumMat, rows1, cols1);

    // Multiplying matrices
    int** mulMat = multiplyMatrix(mat1, rows1, cols1, mat2, rows2, cols2);
    if(mulMat) {
        printf("\nMultiplication of matrices:\n");
        printMatrix(mulMat, rows1, cols2);
    }

    // Freeing memory
    for (i = 0; i < rows1; i++) {
        free(mat1[i]);
        free(sumMat[i]);
    }
    for (i = 0; i < rows2; i++) {
        free(mat2[i]);
    }
    for (i = 0; i < rows1; i++) {
        free(mulMat[i]);
    }
    free(mat1);
    free(mat2);
    free(sumMat);
    free(mulMat);

    return 0;
}