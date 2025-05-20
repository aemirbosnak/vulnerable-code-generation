//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>
#include <time.h>

typedef struct {
    int32_t m, n;
    int32_t **a;
} Matrix;

Matrix *create_matrix(int32_t m, int32_t n) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->m = m;
    matrix->n = n;
    matrix->a = malloc(m * sizeof(int32_t *));
    for (int32_t i = 0; i < m; i++) {
        matrix->a[i] = malloc(n * sizeof(int32_t));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int32_t i = 0; i < matrix->m; i++) {
        free(matrix->a[i]);
    }
    free(matrix->a);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int32_t i = 0; i < matrix->m; i++) {
        for (int32_t j = 0; j < matrix->n; j++) {
            printf("%" PRId32 " ", matrix->a[i][j]);
        }
        printf("\n");
    }
}

void *add_matrices(void *arg) {
    Matrix *result = arg;
    for (int32_t i = 0; i < result->m; i++) {
        for (int32_t j = 0; j < result->n; j++) {
            result->a[i][j] = result->a[i][j] + result->a[i][j];
        }
    }
    return NULL;
}

void *subtract_matrices(void *arg) {
    Matrix *result = arg;
    for (int32_t i = 0; i < result->m; i++) {
        for (int32_t j = 0; j < result->n; j++) {
            result->a[i][j] = result->a[i][j] - result->a[i][j];
        }
    }
    return NULL;
}

void *multiply_matrices(void *arg) {
    Matrix *result = arg;
    for (int32_t i = 0; i < result->m; i++) {
        for (int32_t j = 0; j < result->n; j++) {
            result->a[i][j] = result->a[i][j] * result->a[i][j];
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    int32_t m = 3, n = 3;
    Matrix *matrix1 = create_matrix(m, n);
    Matrix *matrix2 = create_matrix(m, n);
    Matrix *result = create_matrix(m, n);
    for (int32_t i = 0; i < m; i++) {
        for (int32_t j = 0; j < n; j++) {
            matrix1->a[i][j] = rand() % 10;
            matrix2->a[i][j] = rand() % 10;
        }
    }

    pthread_t threads[3];
    pthread_create(&threads[0], NULL, add_matrices, result);
    pthread_create(&threads[1], NULL, subtract_matrices, result);
    pthread_create(&threads[2], NULL, multiply_matrices, result);

    for (int32_t i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    print_matrix(result);

    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(result);

    return 0;
}