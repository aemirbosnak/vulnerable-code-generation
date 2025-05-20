//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 4
#define NUM_THREADS 4

int A[MATRIX_SIZE][MATRIX_SIZE], B[MATRIX_SIZE][MATRIX_SIZE], C[MATRIX_SIZE][MATRIX_SIZE];
pthread_mutex_t mutex;

typedef struct {
    int row;
    int col;
} ThreadData;

void* matrix_add(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int row = data->row;
    int col = data->col;

    pthread_mutex_lock(&mutex);
    C[row][col] = A[row][col] + B[row][col];
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* matrix_multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int row = data->row;
    int col = data->col;
    int sum = 0;

    for (int k = 0; k < MATRIX_SIZE; k++) {
        sum += A[row][k] * B[k][col];
    }

    pthread_mutex_lock(&mutex);
    C[row][col] = sum;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    ThreadData threadData[NUM_THREADS];

    // Initializing matrices A and B with random values
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    // Matrix addition
    printf("Performing Matrix Addition:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            threadData[i * MATRIX_SIZE + j].row = i;
            threadData[i * MATRIX_SIZE + j].col = j;
            pthread_create(&threads[i * MATRIX_SIZE + j], NULL, matrix_add, (void*)&threadData[i * MATRIX_SIZE + j]);
        }
    }
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Result of Matrix Addition:\n");
    print_matrix(C);

    // Resetting C for multiplication
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            C[i][j] = 0;

    // Matrix multiplication
    printf("Performing Matrix Multiplication:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            threadData[i * MATRIX_SIZE + j].row = i;
            threadData[i * MATRIX_SIZE + j].col = j;
            pthread_create(&threads[i * MATRIX_SIZE + j], NULL, matrix_multiply, (void*)&threadData[i * MATRIX_SIZE + j]);
        }
    }
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Result of Matrix Multiplication:\n");
    print_matrix(C);

    pthread_mutex_destroy(&mutex);
    return 0;
}