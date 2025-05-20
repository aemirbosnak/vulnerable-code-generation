//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_ITERATIONS 100000000

int iterations;
int num_threads;

struct v {
    int id;
    int iterations;
};

void *runner(void *param) {
    struct v *data = (struct v *) param;
    for (int i = 0; i < data->iterations; i++) {
        // do some computation here
        printf("Thread %d completed %d iterations\n", data->id, i + 1);
    }
    return NULL;
}

int main() {
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d\n", MAX_THREADS);
        exit(1);
    }

    iterations = MAX_ITERATIONS / num_threads;

    pthread_t thread_id[MAX_THREADS];
    struct v thread_data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].id = i + 1;
        thread_data[i].iterations = iterations;
        pthread_create(&thread_id[i], NULL, runner, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}