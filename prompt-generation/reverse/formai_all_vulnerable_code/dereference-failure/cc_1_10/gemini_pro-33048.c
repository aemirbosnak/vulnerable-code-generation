//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROWS 100
#define NUM_COLS 100

int matrix[NUM_ROWS][NUM_COLS];

void* thread_func(void* arg)
{
    int thread_id = *(int*)arg;

    for (int i = thread_id * NUM_ROWS / NUM_THREADS; i < (thread_id + 1) * NUM_ROWS / NUM_THREADS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else if (i + j == NUM_ROWS - 1) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;

        pthread_create(&threads[i], NULL, thread_func, arg);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}