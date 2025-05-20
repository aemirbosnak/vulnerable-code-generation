//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function Prototypes
Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix mat);
void fillMatrix(Matrix mat);
void displayMatrix(Matrix mat);
Matrix addMatrices(Matrix a, Matrix b);
Matrix multiplyMatrices(Matrix a, Matrix b);
Matrix transposeMatrix(Matrix mat);
int main() {
    srand(time(NULL));

    Matrix A = createMatrix(MAX, MAX);
    Matrix B = createMatrix(MAX, MAX);

    fillMatrix(A);
    fillMatrix(B);
    
    printf("Matrix A:\n");
    displayMatrix(A);
    
    printf("\nMatrix B:\n");
    displayMatrix(B);
    
    Matrix sum = addMatrices(A, B);
    printf("\nSum of A and B:\n");
    displayMatrix(sum);
    
    Matrix product = multiplyMatrices(A, B);
    printf("\nProduct of A and B:\n");
    displayMatrix(product);
    
    Matrix transposeA = transposeMatrix(A);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(transposeA);

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(sum);
    freeMatrix(product);
    freeMatrix(transposeA);
    
    return 0;
}

Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        mat.data[i] = (int*)malloc(cols * sizeof(int));
    return mat;
}

void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++)
        free(mat.data[i]);
    free(mat.data);
}

void fillMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++)
        for (int j = 0; j < mat.cols; j++)
            mat.data[i][j] = rand() % 10; // Filling with random numbers [0-9]
}

void displayMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++)
            printf("%d ", mat.data[i][j]);
        printf("\n");
    }
}

Matrix addMatrices(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices dimensions do not match for addition!\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}

Matrix multiplyMatrices(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        printf("Error: Matrices dimensions do not match for multiplication!\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    return result;
}

Matrix transposeMatrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++)
        for (int j = 0; j < mat.cols; j++)
            result.data[j][i] = mat.data[i][j];
    return result;
}