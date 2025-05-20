//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define KEY_SIZE 1024
#define LOOP_LIMIT 1000000

int *data;
pthread_mutex_t mutex;

void *worker(void *arg) {
    int thread_num = *(int *) arg;
    int start = thread_num * KEY_SIZE;
    int end = start + KEY_SIZE;

    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        data[i] = rand() % 10;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t threads[NUM_THREADS];
    data = malloc(KEY_SIZE * NUM_THREADS);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < KEY_SIZE * NUM_THREADS; i++) {
        printf("%d ", data[i]);
    }

    pthread_mutex_destroy(&mutex);
    free(data);

    return 0;
}