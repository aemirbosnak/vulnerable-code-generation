//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Matrix structure made of dreams
typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

// Function prototypes
Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix m);
Matrix fillMatrixWithShadow(Matrix m);
Matrix multiplyMatrices(Matrix a, Matrix b);
void printMatrix(Matrix m);
Matrix addMatrix(Matrix a, Matrix b);
Matrix transposeMatrix(Matrix m);

// The cosmos really knows its numbers
int main() {
    srand(time(0)); // The hands of time dance with randomness
    
    // Dimension of the surreal
    int rowsA = 3, colsA = 3, rowsB = 3, colsB = 3;
    
    // The essence of matrices born from the void
    Matrix A = createMatrix(rowsA, colsA);
    Matrix B = createMatrix(rowsB, colsB);
    
    // Filling the matrices with echoes from the beyond
    A = fillMatrixWithShadow(A);
    B = fillMatrixWithShadow(B);
    
    // Printing the matrices as they emerge from the ether
    printf("Matrix A:\n");
    printMatrix(A);
    
    printf("Matrix B:\n");
    printMatrix(B);
    
    // Multiply the matrices, creating a new universe
    Matrix C = multiplyMatrices(A, B);
    printf("Matrix C (AxB):\n");
    printMatrix(C);

    // Adding the matrices, blending them into a new reality
    Matrix D = addMatrix(A, B);
    printf("Matrix D (A+B):\n");
    printMatrix(D);
    
    // Transposing the first matrix
    Matrix E = transposeMatrix(A);
    printf("Matrix E (Transpose of A):\n");
    printMatrix(E);
    
    // Freeing the spectral resources
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(D);
    freeMatrix(E);
    
    return 0;
}

// Creates a matrix filled with the essence of nothingness
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    
    // Allocating memory in the void
    m.data = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (float *)malloc(cols * sizeof(float));
    }
    
    return m;
}

// Frees the echoes trapped in the matrix
void freeMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

// Fill a given matrix with values from dreams (random numbers)
Matrix fillMatrixWithShadow(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            m.data[i][j] = (float)(rand() % 10); // between 0 and 9
        }
    }
    return m;
}

// Multiplies two matrices forged in the void
Matrix multiplyMatrices(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        fprintf(stderr, "Incompatible matrices for multiplication\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// Add two matrices like merging two realities
Matrix addMatrix(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "Incompatible matrices for addition\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Transpose the matrix, a dance through dimensions
Matrix transposeMatrix(Matrix m) {
    Matrix result = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    return result;
}

// Print the matrix like unveiling a hidden truth
void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}