//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define STACK_SIZE (1024 * 1024)

typedef struct {
    int id;
    pthread_t thread;
    int *data;
    int size;
} thread_data;

void *runner(void *param) {
    thread_data *data = (thread_data *) param;
    int i, sum = 0;

    for (i = 0; i < data->size; i++) {
        sum += data->data[i];
    }

    pthread_exit((void *) sum);
}

int main() {
    int i, sum = 0;
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizes[NUM_THREADS] = {1, 2, 3, 4};

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i + 1;
        data[i].data = &numbers[0];
        data[i].size = sizes[i];
        pthread_create(&threads[i], NULL, runner, (void *) &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        void *result;
        pthread_join(threads[i], &result);
        sum += *(int *) result;
    }

    printf("Sum: %d\n", sum);

    return 0;
}