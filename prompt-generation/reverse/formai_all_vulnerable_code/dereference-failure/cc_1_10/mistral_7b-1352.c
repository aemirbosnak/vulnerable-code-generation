//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

typedef struct {
    float data[ROWS][COLS];
} Matrix;

Matrix createMatrix() {
    Matrix matrix;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix.data[i][j] = rand() / (float)RAND_MAX;
        }
    }
    return matrix;
}

void printMatrix(const Matrix* matrix) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(const Matrix* first, const Matrix* second) {
    Matrix result;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result.data[i][j] = first->data[i][j] + second->data[i][j];
        }
    }

    return result;
}

int main() {
    srand(time(NULL));

    Matrix matrix1 = createMatrix();
    Matrix matrix2 = createMatrix();

    printf("Matrix 1:\n");
    printMatrix(&matrix1);

    printf("Matrix 2:\n");
    printMatrix(&matrix2);

    Matrix sum = addMatrices(&matrix1, &matrix2);

    printf("Sum of Matrix 1 and Matrix 2:\n");
    printMatrix(&sum);

    free(matrix1.data);
    free(matrix2.data);
    free(sum.data);

    return 0;
}