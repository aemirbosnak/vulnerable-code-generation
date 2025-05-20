//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, cols;
    int** data;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int**) calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int*) calloc(cols, sizeof(int));
    }
    return mat;
}

void printMatrix(const Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%3d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

Matrix multiplyMatrices(const Matrix mat1, const Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        fprintf(stderr, "Error: Matrices can't be multiplied.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result;
    result.rows = mat1.rows;
    result.cols = mat2.cols;
    result.data = (int**) calloc(result.rows, sizeof(int*));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (int*) calloc(result.cols, sizeof(int));
    }

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix magician1 = createMatrix(3, 3);
    Matrix magician2 = createMatrix(3, 3);

    for (int i = 0; i < magician1.rows; i++) {
        for (int j = 0; j < magician1.cols; j++) {
            magician1.data[i][j] = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < magician2.rows; i++) {
        for (int j = 0; j < magician2.cols; j++) {
            magician2.data[i][j] = rand() % 10 + 1;
        }
    }

    printf("Matrix Magician 1:\n");
    printMatrix(magician1);

    printf("Matrix Magician 2:\n");
    printMatrix(magician2);

    Matrix result = multiplyMatrices(magician1, magician2);

    printf("The product of Matrix Magician 1 and Matrix Magician 2 is:\n");
    printMatrix(result);

    for (int i = 0; i < magician1.rows; i++) {
        free(magician1.data[i]);
    }
    free(magician1.data);

    for (int i = 0; i < magician2.rows; i++) {
        free(magician2.data[i]);
    }
    free(magician2.data);

    for (int i = 0; i < result.rows; i++) {
        free(result.data[i]);
    }
    free(result.data);

    return 0;
}