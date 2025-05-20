//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

typedef struct {
    int rows, cols;
    double* data;
} Matrix;

// Function to create a new matrix
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (double*)calloc(rows * cols, sizeof(double));
    return mat;
}

// Function to free memory allocated by a matrix
void freeMatrix(Matrix mat) {
    free(mat.data);
}

// Function to print a matrix
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%f ", mat.data[i * mat.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i * mat1.cols + j] = mat1.data[i * mat1.cols + j] + mat2.data[i * mat1.cols + j];
        }
    }
    return result;
}

// Function to subtract two matrices
Matrix subtractMatrices(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i * mat1.cols + j] = mat1.data[i * mat1.cols + j] - mat2.data[i * mat1.cols + j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            double sum = 0;
            for (int k = 0; k < mat1.cols; k++) {
                sum += mat1.data[i * mat1.cols + k] * mat2.data[k * mat2.cols + j];
            }
            result.data[i * result.cols + j] = sum;
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix A = createMatrix(3, 2);
    Matrix B = createMatrix(2, 3);

    // Populate the matrices with data
    A.data[0] = 1; A.data[1] = 2;
    A.data[2] = 3; A.data[3] = 4;
    A.data[4] = 5; A.data[5] = 6;

    B.data[0] = 7; B.data[1] = 8; B.data[2] = 9;
    B.data[3] = 10; B.data[4] = 11; B.data[5] = 12;

    // Calculate the sum, difference and product of the matrices
    Matrix sum = addMatrices(A, B);
    Matrix difference = subtractMatrices(A, B);
    Matrix product = multiplyMatrices(A, B);

    // Print the matrices and their results
    printf("A:\n");
    printMatrix(A);

    printf("\nB:\n");
    printMatrix(B);

    printf("\nA + B:\n");
    printMatrix(sum);

    printf("\nA - B:\n");
    printMatrix(difference);

    printf("\nA * B:\n");
    printMatrix(product);

    // Free the memory allocated to the matrices
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(sum);
    freeMatrix(difference);
    freeMatrix(product);

    return 0;
}