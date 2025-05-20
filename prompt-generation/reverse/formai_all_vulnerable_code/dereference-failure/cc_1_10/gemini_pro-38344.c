//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <pthread.h>

#define NUM_THREADS 4
#define TIME_INTERVAL 1

// global variables
double cpu_usage[NUM_THREADS];
bool thread_running[NUM_THREADS];
pthread_t threads[NUM_THREADS];

// thread function to calculate CPU usage
void *thread_func(void *arg) {
    int tid = *(int *)arg;
    while (thread_running[tid]) {
        // get CPU time
        clock_t start_time = clock();
        
        // do some work
        for (int i = 0; i < 10000000; i++) {
            double x = i * 3.14159265358979323846;
        }

        // get CPU time again
        clock_t end_time = clock();
        
        // calculate CPU usage
        cpu_usage[tid] = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    return NULL;
}

int main() {
    // initialize global variables
    for (int i = 0; i < NUM_THREADS; i++) {
        cpu_usage[i] = 0.0;
        thread_running[i] = true;
    }

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int *tid = malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], NULL, thread_func, tid);
    }

    // periodically print CPU usage
    while (true) {
        // print CPU usage
        printf("CPU usage:\n");
        for (int i = 0; i < NUM_THREADS; i++) {
            printf("Thread %d: %.2f%%\n", i, cpu_usage[i] * 100.0);
        }

        // sleep for a while
        sleep(TIME_INTERVAL);
    }

    // cleanup
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_running[i] = false;
        pthread_join(threads[i], NULL);
    }

    return 0;
}