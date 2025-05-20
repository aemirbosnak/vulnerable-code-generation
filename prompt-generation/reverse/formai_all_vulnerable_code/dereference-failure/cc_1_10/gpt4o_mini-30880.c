//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 512

typedef struct {
    int row;
    int (*A)[MATRIX_SIZE];
    int (*B)[MATRIX_SIZE];
    int (*C)[MATRIX_SIZE];
} MatrixMulArgs;

void *matrix_multiply(void *args) {
    MatrixMulArgs *mulArgs = (MatrixMulArgs *)args;
    int row = mulArgs->row;
    
    for (int col = 0; col < MATRIX_SIZE; col++) {
        int value = 0;
        for (int k = 0; k < MATRIX_SIZE; k++) {
            value += mulArgs->A[row][k] * mulArgs->B[k][col];
        }
        mulArgs->C[row][col] = value;
    }
    
    return NULL;
}

void initialize_matrix(int (*matrix)[MATRIX_SIZE], int value) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = value;
        }
    }
}

void print_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Allocate matrices A, B, and C
    int (*A)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*B)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*C)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Failed to allocate memory for matrices.\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices A and B with sample values
    initialize_matrix(A, 1);
    initialize_matrix(B, 2);
    // C will be initialized to 0 by default

    pthread_t threads[MATRIX_SIZE];
    MatrixMulArgs threadArgs[MATRIX_SIZE];

    clock_t start_time = clock();

    // Creating threads for parallel multiplication
    for (int i = 0; i < MATRIX_SIZE; i++) {
        threadArgs[i].row = i;
        threadArgs[i].A = A;
        threadArgs[i].B = B;
        threadArgs[i].C = C;

        if (pthread_create(&threads[i], NULL, matrix_multiply, &threadArgs[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Joining threads
    for (int i = 0; i < MATRIX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end_time = clock();
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Matrix multiplication completed in %.3f seconds.\n", time_elapsed);
    
    // Uncomment to print the resulting matrix
    // print_matrix(C);

    // Clean up allocated memory
    free(A);
    free(B);
    free(C);
    
    return EXIT_SUCCESS;
}