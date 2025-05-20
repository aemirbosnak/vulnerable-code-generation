//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10
#define MAX_PRIORITY 100
#define MIN_PRIORITY 1

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} thread_t;

void *runner(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    thread_t *thread_data = malloc(NUM_THREADS * sizeof(thread_t));
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i + 1;
        thread_data[i].priority = rand() % (MAX_PRIORITY - MIN_PRIORITY + 1) + MIN_PRIORITY;
        thread_data[i].burst_time = rand() % 10 + 1;
        thread_data[i].waiting_time = 0;
        thread_data[i].turnaround_time = 0;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, runner, &thread_data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(thread_data);
    return 0;
}

void *runner(void *param) {
    thread_t *thread_data = param;
    int i, j;

    for (i = 0; i < thread_data->burst_time; i++) {
        printf("Thread %d is running...\n", thread_data->id);
        sleep(1);
    }

    thread_data->turnaround_time = thread_data->burst_time;

    return NULL;
}