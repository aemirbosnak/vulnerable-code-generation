//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define BUFFER_SIZE 10
#define NUM_ITEMS 20

typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t empty;
    sem_t full;
} SharedBuffer;

void* producer(void* arg) {
    SharedBuffer* shared = (SharedBuffer*) arg;
    for(int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 100;  // Produce a random number
        sem_wait(&shared->empty);  // Wait for an empty slot
        shared->buffer[shared->in] = item; // Put item in buffer
        printf("Produced: %d\n", item);
        shared->in = (shared->in + 1) % BUFFER_SIZE; // Update index
        sem_post(&shared->full); // Signal that there's a new item
        usleep(rand() % 100000); // Simulate variable production time
    }
    return NULL;
}

void* consumer(void* arg) {
    SharedBuffer* shared = (SharedBuffer*) arg;
    for(int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&shared->full); // Wait for a full slot
        int item = shared->buffer[shared->out]; // Get item from buffer
        printf("Consumed: %d\n", item);
        shared->out = (shared->out + 1) % BUFFER_SIZE; // Update index
        sem_post(&shared->empty); // Signal that there's a new empty slot
        usleep(rand() % 150000); // Simulate variable consumption time
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int shm_id;
    SharedBuffer* shared;

    // Create shared memory
    shm_id = shmget(IPC_PRIVATE, sizeof(SharedBuffer), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shared = (SharedBuffer*) shmat(shm_id, NULL, 0);
    if (shared == (SharedBuffer*) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared buffer
    shared->in = 0;
    shared->out = 0;
    sem_init(&shared->empty, 1, BUFFER_SIZE); // Initialize empty semaphore
    sem_init(&shared->full, 1, 0); // Initialize full semaphore

    pthread_t prod_thread, cons_thread;
    
    // Create producer and consumer threads
    if(pthread_create(&prod_thread, NULL, producer, shared) != 0) {
        perror("Failed to create producer thread");
        exit(1);
    }
    if(pthread_create(&cons_thread, NULL, consumer, shared) != 0) {
        perror("Failed to create consumer thread");
        exit(1);
    }

    // Wait for threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Clean up
    shmdt(shared); // Detach shared memory
    shmctl(shm_id, IPC_RMID, NULL); // Remove shared memory
    sem_destroy(&shared->empty); // Destroy empty semaphore
    sem_destroy(&shared->full); // Destroy full semaphore

    return 0;
}