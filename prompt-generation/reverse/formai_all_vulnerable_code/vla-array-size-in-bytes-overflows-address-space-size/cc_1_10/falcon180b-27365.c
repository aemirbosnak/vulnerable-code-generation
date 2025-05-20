//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_THREADS 10

typedef struct {
    int row;
    int col;
    int value;
} matrix_element;

matrix_element matrix[MAX_ROWS][MAX_COLS];
int num_rows, num_cols;

pthread_mutex_t mutex;

void *thread_func(void *arg) {
    int i, j;
    int sum = 0;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            pthread_mutex_lock(&mutex);
            sum += matrix[i][j].value;
            pthread_mutex_unlock(&mutex);
        }
    }

    printf("Sum of matrix elements: %d\n", sum);
    return NULL;
}

int main() {
    int i, j, k;
    int num_threads;

    printf("Enter the number of rows and columns for the matrix:\n");
    scanf("%d %d", &num_rows, &num_cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            scanf("%d", &matrix[i][j].value);
        }
    }

    printf("Enter the number of threads:\n");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];

    for (k = 0; k < num_threads; k++) {
        pthread_create(&threads[k], NULL, thread_func, NULL);
    }

    for (k = 0; k < num_threads; k++) {
        pthread_join(threads[k], NULL);
    }

    return 0;
}