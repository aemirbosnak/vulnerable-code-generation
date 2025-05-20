//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 20

pthread_mutex_t buffer_mutex;
pthread_cond_t buffer_full;
pthread_cond_t buffer_empty;

char buffer[BUFFER_SIZE];
int count = 0, in = 0, out = 0;

void* producer(void* param) {
    int id = *((int *)param);
    free(param);
    char item;

    while (1) {
        item = 'A' + (rand() % 26);  // Produce a random character from A to Z
        pthread_mutex_lock(&buffer_mutex);

        while (count == BUFFER_SIZE) {
            // Buffer is full, wait for consumer
            pthread_cond_wait(&buffer_full, &buffer_mutex);
        }

        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        printf("Producer %d produced: %c | Buffer count: %d\n", id, item, count);

        // Signal that the buffer is not empty
        pthread_cond_signal(&buffer_empty);
        pthread_mutex_unlock(&buffer_mutex);

        sleep(rand() % 3); // Simulate time taken to produce an item
    }
    
    return NULL;
}

void* consumer(void* param) {
    int id = *((int *)param);
    free(param);
    char item;

    while (1) {
        pthread_mutex_lock(&buffer_mutex);

        while (count == 0) {
            // Buffer is empty, wait for producer
            pthread_cond_wait(&buffer_empty, &buffer_mutex);
        }

        // Remove item from buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        printf("Consumer %d consumed: %c | Buffer count: %d\n", id, item, count);

        // Signal that the buffer is not full
        pthread_cond_signal(&buffer_full);
        pthread_mutex_unlock(&buffer_mutex);

        sleep(rand() % 3); // Simulate time taken to consume an item
    }
    
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    pthread_t producers[MAX_THREADS], consumers[MAX_THREADS];
    pthread_mutex_init(&buffer_mutex, NULL);
    pthread_cond_init(&buffer_full, NULL);
    pthread_cond_init(&buffer_empty, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1; // Producer IDs from 1 to MAX_THREADS
        pthread_create(&producers[i], NULL, producer, id);

        id = malloc(sizeof(int));
        *id = i + 1; // Consumer IDs from 1 to MAX_THREADS
        pthread_create(&consumers[i], NULL, consumer, id);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    // Cleanup
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&buffer_full);
    pthread_cond_destroy(&buffer_empty);

    return 0;
}