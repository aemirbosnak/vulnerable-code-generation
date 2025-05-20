//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <time.h>

#define BUFFER_SIZE 5
#define ITERATIONS 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
} shared_data;

shared_data *shm_data;
sem_t *empty;     // Semaphore to count empty slots
sem_t *full;      // Semaphore to count full slots
sem_t *mutex;     // Semaphore for mutual exclusion

void *producer(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        int item = rand() % 100; // Produce a random number
        sem_wait(empty);          // Wait for an empty slot
        sem_wait(mutex);          // Lock access

        // Produce the item
        shm_data->buffer[shm_data->in] = item;
        printf("Produced: %d at index %d\n", item, shm_data->in);
        shm_data->in = (shm_data->in + 1) % BUFFER_SIZE;

        sem_post(mutex);          // Unlock access
        sem_post(full);           // Increment full count

        sleep(rand() % 2);        // Sleep for a random time
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(full);           // Wait for a full slot
        sem_wait(mutex);          // Lock access

        // Consume the item
        int item = shm_data->buffer[shm_data->out];
        printf("Consumed: %d from index %d\n", item, shm_data->out);
        shm_data->out = (shm_data->out + 1) % BUFFER_SIZE;

        sem_post(mutex);          // Unlock access
        sem_post(empty);          // Increment empty count

        sleep(rand() % 2);        // Sleep for a random time
    }
    return NULL;
}

int main() {
    int shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shared_data));
    shm_data = mmap(0, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    shm_data->in = 0;
    shm_data->out = 0;

    // Initialize semaphores
    empty = sem_open("/empty", O_CREAT, 0644, BUFFER_SIZE);
    full = sem_open("/full", O_CREAT, 0644, 0);
    mutex = sem_open("/mutex", O_CREAT, 0644, 1);

    pthread_t prod_thread, cons_thread;
    
    // Seed random number generator
    srand(time(NULL));

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Clean up
    sem_close(empty);
    sem_close(full);
    sem_close(mutex);
    sem_unlink("/empty");
    sem_unlink("/full");
    sem_unlink("/mutex");
    munmap(shm_data, sizeof(shared_data));
    shm_unlink("/my_shm");

    return 0;
}