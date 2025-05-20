//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond[NUM_THREADS];

int light = 0;
int count = 0;

void *thread_func(void *arg) {
    int id = *(int *) arg;
    int i;

    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        if (light == id) {
            printf("Thread %d is running.\n", id);
        } else {
            printf("Thread %d is waiting.\n", id);
        }
        pthread_mutex_unlock(&mutex);

        pthread_cond_wait(&cond[id], &mutex);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    while (1) {
        pthread_mutex_lock(&mutex);
        light++;
        if (light >= NUM_THREADS) {
            light = 0;
        }
        count++;
        printf("The current light is %d and the current count is %d.\n", light, count);
        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond[light]);
        sleep(1);
    }

    return 0;
}