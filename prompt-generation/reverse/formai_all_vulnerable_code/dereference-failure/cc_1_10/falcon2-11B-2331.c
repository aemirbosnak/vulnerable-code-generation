//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3

int matrix[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int transpose[N][N] = {{0}};
int inverse[N][N] = {{0}};

void *transpose_matrix(void *arg) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    return NULL;
}

void *inverse_matrix(void *arg) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            inverse[j][i] = matrix[i][j] * inverse[j][i] - inverse[j][i] * matrix[i][j];
        }
    }
    return NULL;
}

int main() {
    pthread_t transpose_thread, inverse_thread;
    int result;

    // Create threads to compute transpose and inverse
    pthread_create(&transpose_thread, NULL, transpose_matrix, NULL);
    pthread_create(&inverse_thread, NULL, inverse_matrix, NULL);

    // Wait for threads to complete
    pthread_join(transpose_thread, &result);
    pthread_join(inverse_thread, &result);

    // Print results
    printf("Transpose matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", transpose[j][i]);
        }
        printf("\n");
    }
    printf("\nInverse matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", inverse[j][i]);
        }
        printf("\n");
    }

    return 0;
}