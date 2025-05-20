//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int read_pos = 0;
int write_pos = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    int id = *(int *) arg;
    int i;

    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while ((write_pos - read_pos) % BUFFER_SIZE == 0) {
            pthread_mutex_unlock(&mutex);
            usleep(100);
            pthread_mutex_lock(&mutex);
        }
        buffer[write_pos] = id * i;
        write_pos++;
        printf("Producer %d produced %d\n", id, buffer[write_pos - 1]);
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }

    pthread_exit(0);
}

void *consumer(void *arg) {
    int id = *(int *) arg;
    int i;

    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while (read_pos == write_pos) {
            pthread_mutex_unlock(&mutex);
            usleep(100);
            pthread_mutex_lock(&mutex);
        }
        int value = buffer[read_pos];
        read_pos++;
        printf("Consumer %d consumed %d\n", id, value);
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = rand() % 100;
        pthread_create(&threads[i], NULL, producer, &ids[i]);
        pthread_create(&threads[i + NUM_THREADS / 2], NULL, consumer, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS * 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}