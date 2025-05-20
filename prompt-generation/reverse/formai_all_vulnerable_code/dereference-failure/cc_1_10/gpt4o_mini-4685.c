//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

typedef struct {
    Complex **data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (Complex**)malloc(rows * sizeof(Complex*));
    
    for (int i = 0; i < rows; i++)
        mat->data[i] = (Complex*)malloc(cols * sizeof(Complex));
    
    return mat;
}

void freeMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++)
        free(mat->data[i]);
    free(mat->data);
    free(mat);
}

void printMatrix(const Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("(%lf + %lfi) ", mat->data[i][j].real, mat->data[i][j].imag);
        }
        printf("\n");
    }
}

Matrix* addMatrices(const Matrix* A, const Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Matrix dimensions must match for addition.\n");
        return NULL;
    }
    
    Matrix* result = createMatrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[i][j].real = A->data[i][j].real + B->data[i][j].real;
            result->data[i][j].imag = A->data[i][j].imag + B->data[i][j].imag;
        }
    }
    return result;
}

Matrix* subtractMatrices(const Matrix* A, const Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Matrix dimensions must match for subtraction.\n");
        return NULL;
    }

    Matrix* result = createMatrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[i][j].real = A->data[i][j].real - B->data[i][j].real;
            result->data[i][j].imag = A->data[i][j].imag - B->data[i][j].imag;
        }
    }
    return result;
}

Matrix* multiplyMatrices(const Matrix* A, const Matrix* B) {
    if (A->cols != B->rows) {
        fprintf(stderr, "Matrix A's columns must match Matrix B's rows for multiplication.\n");
        return NULL;
    }

    Matrix* result = createMatrix(A->rows, B->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            result->data[i][j].real = 0.0;
            result->data[i][j].imag = 0.0;

            for (int k = 0; k < A->cols; k++) {
                double a_real = A->data[i][k].real;
                double a_imag = A->data[i][k].imag;
                double b_real = B->data[k][j].real;
                double b_imag = B->data[k][j].imag;

                result->data[i][j].real += a_real * b_real - a_imag * b_imag;
                result->data[i][j].imag += a_real * b_imag + a_imag * b_real;
            }
        }
    }
    return result;
}

Matrix* transposeMatrix(const Matrix* mat) {
    Matrix* result = createMatrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i].real = mat->data[i][j].real;
            result->data[j][i].imag = mat->data[i][j].imag;
        }
    }
    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    Matrix* A = createMatrix(rowsA, colsA);
    
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++) {
            printf("Element [%d][%d] (real imag): ", i, j);
            scanf("%lf %lf", &A->data[i][j].real, &A->data[i][j].imag);
        }

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    Matrix* B = createMatrix(rowsB, colsB);
    
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d] (real imag): ", i, j);
            scanf("%lf %lf", &B->data[i][j].real, &B->data[i][j].imag);
        }

    // Operations
    printf("\nMatrix A:\n");
    printMatrix(A);
    
    printf("Matrix B:\n");
    printMatrix(B);
    
    Matrix* C = addMatrices(A, B);
    if (C) {
        printf("A + B:\n");
        printMatrix(C);
        freeMatrix(C);
    }

    C = subtractMatrices(A, B);
    if (C) {
        printf("A - B:\n");
        printMatrix(C);
        freeMatrix(C);
    }

    C = multiplyMatrices(A, B);
    if (C) {
        printf("A * B:\n");
        printMatrix(C);
        freeMatrix(C);
    }

    C = transposeMatrix(A);
    if (C) {
        printf("Transpose of A:\n");
        printMatrix(C);
        freeMatrix(C);
    }
    
    freeMatrix(A);
    freeMatrix(B);

    return 0;
}