//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
    int thread_id;
    int start;
    int end;
};

void *sum_range(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int i;
    int sum = 0;

    for (i = data->start; i <= data->end; i++) {
        sum += i;
    }

    pthread_exit((void *) sum);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, j, start, end;
    int total_sum = 0;

    start = 1;
    end = 100000;

    for (i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->start = start;
        data->end = end;

        pthread_create(&threads[i], NULL, sum_range, (void *) data);

        start += (end - start) / NUM_THREADS;
        end -= (end - start) / NUM_THREADS;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        void *result;
        pthread_join(threads[i], &result);
        total_sum += *(int *) result;
    }

    printf("Total sum: %d\n", total_sum);

    return 0;
}