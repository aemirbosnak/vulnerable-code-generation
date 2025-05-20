//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_SIZE 1000000

struct point {
    int x;
    int y;
};

struct thread_data {
    int start;
    int end;
};

struct point *points;
int num_points;
pthread_mutex_t mutex;

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int start = data->start;
    int end = data->end;
    int count = 0;

    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        points[i].x = rand() % MAX_SIZE;
        points[i].y = rand() % MAX_SIZE;
        pthread_mutex_unlock(&mutex);
        count++;
    }

    return (void *) count;
}

int main() {
    srand(time(NULL));
    num_points = MAX_SIZE;
    points = (struct point *) malloc(num_points * sizeof(struct point));

    pthread_mutex_init(&mutex, NULL);

    int thread_count = 0;
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->start = i * num_points / NUM_THREADS;
        data->end = (i + 1) * num_points / NUM_THREADS;
        pthread_create(&threads[i], NULL, thread_func, data);
        thread_count++;
    }

    int total_count = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        void *result;
        pthread_join(threads[i], &result);
        total_count += *(int *) result;
        free(result);
    }

    printf("Total points generated: %d\n", total_count);

    return 0;
}