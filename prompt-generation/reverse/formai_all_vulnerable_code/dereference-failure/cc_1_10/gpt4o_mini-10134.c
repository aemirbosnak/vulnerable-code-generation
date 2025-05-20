//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define SIZE 10 // Number of integers to produce and consume
#define SHM_NAME "/my_shared_memory"
#define SEM_PRODUCER "/sem_producer"
#define SEM_CONSUMER "/sem_consumer"

typedef struct {
    int numbers[SIZE];
    int count;
} shared_data;

void producer(shared_data* data, sem_t* sem_producer, sem_t* sem_consumer) {
    for (int i = 0; i < SIZE; i++) {
        // Wait for consumer to finish
        sem_wait(sem_producer);
        
        // Produce a random number and store it in shared memory
        data->numbers[data->count] = rand() % 100;
        printf("Producer produced: %d\n", data->numbers[data->count]);
        data->count++;
        
        // Signal the consumer that data is ready
        sem_post(sem_consumer);
        
        sleep(1); // Sleep for a second to simulate time taken to produce
    }
}

void consumer(shared_data* data, sem_t* sem_producer, sem_t* sem_consumer) {
    for (int i = 0; i < SIZE; i++) {
        // Wait for produced item
        sem_wait(sem_consumer);
        
        // Consume the number from shared memory
        int consumed_number = data->numbers[data->count - 1];
        printf("Consumer consumed: %d\n", consumed_number);
        data->count--;
        
        // Signal the producer that space is available to produce more data
        sem_post(sem_producer);
        
        sleep(1); // Sleep for a second to simulate time taken to consume
    }
}

int main() {
    // Set up shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shared_data));
    shared_data* data = mmap(0, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    memset(data, 0, sizeof(shared_data)); // Initialize shared memory
    
    // Set up semaphores
    sem_t* sem_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, 1); // Start with producer semaphore available
    sem_t* sem_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 0); // Consumer semaphore starts not available
    
    // Create child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process - Consumer
        consumer(data, sem_producer, sem_consumer);
    } else {
        // Parent process - Producer
        producer(data, sem_producer, sem_consumer);
        
        // Wait for child process to finish
        wait(NULL);
        
        // Clean up
        sem_close(sem_producer);
        sem_close(sem_consumer);
        shm_unlink(SHM_NAME);
        sem_unlink(SEM_PRODUCER);
        sem_unlink(SEM_CONSUMER);
        printf("Producer and Consumer finished their work.\n");
    }
    
    // Cleanup
    munmap(data, sizeof(shared_data));
    return 0;
}