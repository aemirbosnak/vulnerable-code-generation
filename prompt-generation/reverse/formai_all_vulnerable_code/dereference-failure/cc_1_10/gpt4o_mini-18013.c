//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printMatrix(int** matrix, int rows, int cols);
int** createMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
int** addMatrices(int** A, int** B, int rows, int cols);
int** subtractMatrices(int** A, int** B, int rows, int cols);
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB);
int** transposeMatrix(int** matrix, int rows, int cols);

int main() {
    int rows, cols;

    // Shape-shifting: Reading matrix dimensions
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int** A = createMatrix(rows, cols);
    int** B = createMatrix(rows, cols);

    // Filling matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Filling matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Shape-shifting: Performing operations
    printf("\nMatrix A:\n");
    printMatrix(A, rows, cols);
    
    printf("\nMatrix B:\n");
    printMatrix(B, rows, cols);

    // Addition
    int** sum = addMatrices(A, B, rows, cols);
    printf("\nSum of A and B:\n");
    printMatrix(sum, rows, cols);
    
    // Subtraction
    int** difference = subtractMatrices(A, B, rows, cols);
    printf("\nDifference of A and B:\n");
    printMatrix(difference, rows, cols);
    
    // Multiplication
    int** product = multiplyMatrices(A, B, rows, cols, cols);
    printf("\nProduct of A and B:\n");
    printMatrix(product, rows, cols);
    
    // Transposition
    int** transposed = transposeMatrix(A, rows, cols);
    printf("\nTransposed Matrix A:\n");
    printMatrix(transposed, cols, rows);

    // Free allocated memory
    freeMatrix(A, rows);
    freeMatrix(B, rows);
    freeMatrix(sum, rows);
    freeMatrix(difference, rows);
    freeMatrix(product, rows);
    freeMatrix(transposed, cols);

    return 0;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}