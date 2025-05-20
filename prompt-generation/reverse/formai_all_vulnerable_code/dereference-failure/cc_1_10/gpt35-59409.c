//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10 // maximum number of items in buffer
#define NUM_THREADS 2 // number of producer threads

int buffer[BUFFER_SIZE]; // shared buffer
int in = 0; // index for inserting into buffer
int out = 0; // index for removing from buffer
int count = 0; // number of items in buffer

pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;

void *producer(void *arg) {
    int num = *(int*)arg;
    free(arg);
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Producer %d is waiting...\n", num);
            pthread_cond_wait(&not_full, &mutex);
        }
        int item = rand() % 1000; // generate random item
        buffer[in] = item; // insert into buffer
        printf("Producer %d produced item %d\n", num, item);
        in = (in + 1) % BUFFER_SIZE; // update insert index
        count++; // increment count
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000); // sleep for random time
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            printf("Consumer is waiting...\n");
            pthread_cond_wait(&not_empty, &mutex);
        }
        int item = buffer[out]; // remove item from buffer
        printf("Consumer consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE; // update remove index
        count--; // decrement count
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000); // sleep for random time
    }
    return NULL;
}

int main() {
    pthread_t thread[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);
    for (int i = 0; i < NUM_THREADS; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&thread[i], NULL, producer, arg);
    }
    pthread_create(&thread[NUM_THREADS], NULL, consumer, NULL);
    for (int i = 0; i < NUM_THREADS+1; i++) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}