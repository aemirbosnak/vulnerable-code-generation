//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int rows;
    int columns;
    int **data;
};

typedef struct matrix Matrix;

// Creates a new matrix with specified rows and columns
Matrix createMatrix(int rows, int columns) {
    Matrix newMatrix;
    newMatrix.rows = rows;
    newMatrix.columns = columns;
    newMatrix.data = (int**) malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++) {
        newMatrix.data[i] = (int*) malloc(columns * sizeof(int));
    }

    return newMatrix;
}

// Fills the matrix with random numbers
void fillMatrix(Matrix m) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.columns; j++) {
            m.data[i][j] = rand() % 100;
        }
    }
}

// Prints the matrix to the console
void printMatrix(Matrix m) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.columns; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Adds two matrices together
Matrix addMatrices(Matrix m1, Matrix m2) {
    Matrix result = createMatrix(m1.rows, m1.columns);
    for(int i = 0; i < m1.rows; i++) {
        for(int j = 0; j < m1.columns; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }

    return result;
}

// Multiplies two matrices together
Matrix multiplyMatrices(Matrix m1, Matrix m2) {
    if(m1.columns != m2.rows) {
        printf("Error: Incompatible matrices.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(m1.rows, m2.columns);
    for(int i = 0; i < m1.rows; i++) {
        for(int j = 0; j < m2.columns; j++) {
            result.data[i][j] = 0;
            for(int k = 0; k < m1.columns; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix a = createMatrix(3, 2);
    fillMatrix(a);
    printf("Matrix A:\n");
    printMatrix(a);

    Matrix b = createMatrix(2, 4);
    fillMatrix(b);
    printf("\nMatrix B:\n");
    printMatrix(b);

    Matrix c = addMatrices(a, b);
    printf("\nMatrix C (A + B):\n");
    printMatrix(c);

    Matrix d = multiplyMatrices(a, b);
    printf("\nMatrix D (A*B):\n");
    printMatrix(d);

    return 0;
}