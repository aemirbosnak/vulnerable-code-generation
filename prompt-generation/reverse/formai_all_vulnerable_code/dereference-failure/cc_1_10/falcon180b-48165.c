//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 2

int thread_id;
int num_threads;

pthread_mutex_t mutex;

struct event {
    int thread_id;
    int time;
};

void *thread_func(void *arg) {
    struct event *event = arg;
    int thread_id = event->thread_id;

    printf("Thread %d starting at time %d\n", thread_id, event->time);

    // Simulate some work
    for (int i = 0; i < 5; i++) {
        printf("Thread %d doing work at time %d\n", thread_id, event->time + i);
        sleep(1);
    }

    printf("Thread %d ending at time %d\n", thread_id, event->time + 5);

    pthread_exit(0);
}

void schedule_event(int thread_id, int time) {
    struct event *event = malloc(sizeof(struct event));
    event->thread_id = thread_id;
    event->time = time;

    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, event);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int times[NUM_THREADS] = {0, 2};

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        schedule_event(i, times[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}