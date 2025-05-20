//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

void initMatrix(matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = mmap(NULL, rows * cols * sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mat->data == MAP_FAILED) {
        perror("Error initializing matrix.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows * cols; ++i)
        mat->data[i] = 0;
}

void printMatrix(const matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j)
            printf("%d ", mat->data[i * mat->cols + j]);
        printf("\n");
    }
}

void addMatrices(const matrix *matA, const matrix *matB, matrix *result) {
    if (matA->rows != matB->rows || matA->cols != matB->cols) {
        perror("Error: Matrices have different dimensions.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matA->rows * matA->cols; ++i)
        result->data[i] = matA->data[i] + matB->data[i];
}

void multiplyMatrices(const matrix *matA, const matrix *matB, matrix *result) {
    if (matA->cols != matB->rows) {
        perror("Error: Matrices cannot be multiplied.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matA->rows; ++i) {
        for (int j = 0; j < matB->cols; ++j) {
            int sum = 0;
            for (int k = 0; k < matA->cols; ++k)
                sum += matA->data[i * matA->cols + k] * matB->data[k * matB->cols + j];
            result->data[i * matB->cols + j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));

    matrix matA, matB, resultA, resultB;

    initMatrix(&matA, ROWS, COLS);
    initMatrix(&matB, ROWS, COLS);

    for (int i = 0; i < ROWS * COLS; ++i) {
        matA.data[i] = rand() % 100;
        matB.data[i] = rand() % 100;
    }

    printMatrix(&matA);
    printf("\n");
    printMatrix(&matB);
    printf("\n");

    addMatrices(&matA, &matB, &resultA);
    printf("The sum of the matrices:\n");
    printMatrix(&resultA);
    printf("\n");

    multiplyMatrices(&matA, &matB, &resultB);
    printf("The product of the matrices:\n");
    printMatrix(&resultB);

    munmap(matA.data, ROWS * COLS * sizeof(int));
    munmap(matB.data, ROWS * COLS * sizeof(int));
    munmap(resultA.data, ROWS * COLS * sizeof(int));
    munmap(resultB.data, ROWS * COLS * sizeof(int));

    return EXIT_SUCCESS;
}