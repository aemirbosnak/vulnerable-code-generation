//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 1
#define NUM_ITEMS 20

typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} shared_data_t;

shared_data_t *shared_data;

// Producer function
void* producer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sleep(rand() % 3); // Simulate production time
        int item = rand() % 100; // Create an item

        sem_wait(&shared_data->empty); // Wait for empty slot
        pthread_mutex_lock(&shared_data->mutex); // Lock for mutual exclusion

        // Add item to buffer
        shared_data->buffer[shared_data->count++] = item;
        printf("Producer %d produced: %d\n", id, item);

        pthread_mutex_unlock(&shared_data->mutex); // Unlock
        sem_post(&shared_data->full); // Signal that buffer is not empty
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&shared_data->full); // Wait for full slot
        pthread_mutex_lock(&shared_data->mutex); // Lock for mutual exclusion

        // Remove item from buffer
        int item = shared_data->buffer[--shared_data->count];
        printf("Consumer consumed: %d\n", item);

        pthread_mutex_unlock(&shared_data->mutex); // Unlock
        sem_post(&shared_data->empty); // Signal that buffer has empty slot
        sleep(rand() % 2); // Simulate consumption time
    }
    return NULL;
}

int main() {
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumer_thread;
    int producer_ids[NUM_PRODUCERS];

    // Allocate shared memory
    shared_data = mmap(NULL, sizeof(shared_data_t), PROT_READ | PROT_WRITE, 
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize shared data
    shared_data->count = 0;
    sem_init(&shared_data->empty, 1, BUFFER_SIZE); // Buffer is empty at start
    sem_init(&shared_data->full, 1, 0); // Buffer is full at start
    pthread_mutex_init(&shared_data->mutex, NULL);

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    // Create consumer thread
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Join consumer thread
    pthread_join(consumer_thread, NULL);

    // Cleanup
    munmap(shared_data, sizeof(shared_data_t));
    pthread_mutex_destroy(&shared_data->mutex);
    sem_destroy(&shared_data->empty);
    sem_destroy(&shared_data->full);

    return 0;
}