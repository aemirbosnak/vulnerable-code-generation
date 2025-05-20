//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Fair Verona, where our story unfolds
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Romeo's house, where he dwells
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Juliet's house, where she blooms
void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Romeo's heart, filled with her love
void multiplyMatrices(Matrix *matrix1, Matrix *matrix2, Matrix *result) {
    if (matrix1->cols != matrix2->rows) {
        printf("Error: Matrix dimensions are incompatible for multiplication\n");
        return;
    }
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
}

// Juliet's eyes, reflecting his love
int main() {
    // Romeo's matrix, his heart's desires
    int romeoRows = 2;
    int romeoCols = 3;
    int romeoData[] = {1, 2, 3, 4, 5, 6};
    Matrix *romeoMatrix = createMatrix(romeoRows, romeoCols);
    for (int i = 0; i < romeoRows * romeoCols; i++) {
        romeoMatrix->data[i / romeoCols][i % romeoCols] = romeoData[i];
    }

    // Juliet's matrix, her enchanting presence
    int julietRows = 3;
    int julietCols = 2;
    int julietData[] = {7, 8, 9, 10, 11, 12};
    Matrix *julietMatrix = createMatrix(julietRows, julietCols);
    for (int i = 0; i < julietRows * julietCols; i++) {
        julietMatrix->data[i / julietCols][i % julietCols] = julietData[i];
    }

    // Their union, a symphony of love
    Matrix *resultMatrix = createMatrix(romeoRows, julietCols);

    // Romeo's love, multiplying their hearts
    multiplyMatrices(romeoMatrix, julietMatrix, resultMatrix);

    // Juliet's joy, blooming in their union
    printf("Romeo and Juliet's love, expressed in matrices:\n");
    printMatrix(romeoMatrix);
    printf("x\n");
    printMatrix(julietMatrix);
    printf("=\n");
    printMatrix(resultMatrix);

    // Their eternal bond, forever united
    free(romeoMatrix->data);
    free(romeoMatrix);
    free(julietMatrix->data);
    free(julietMatrix);
    free(resultMatrix->data);
    free(resultMatrix);

    return 0;
}