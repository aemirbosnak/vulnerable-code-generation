//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <string.h>

#define SHM_SIZE 1024
#define BUFFER_SIZE 10
#define NUM_ITEMS 20

typedef struct {
    int buffer[BUFFER_SIZE];
    int in; 
    int out; 
} shared_data;

void producer(shared_data *data, sem_t *sem_full, sem_t *sem_empty) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 100;  // Generate a random number
        sem_wait(sem_empty);       // Wait if buffer is full

        // Add item to the buffer
        data->buffer[data->in] = item;
        printf("Producer produced: %d\n", item);
        data->in = (data->in + 1) % BUFFER_SIZE;

        sem_post(sem_full);        // Signal that buffer is not empty
        sleep(rand() % 2);         // Simulate variable production time
    }
}

void consumer(shared_data *data, sem_t *sem_full, sem_t *sem_empty) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(sem_full);        // Wait if buffer is empty
        
        // Remove item from the buffer
        int item = data->buffer[data->out];
        printf("Consumer consumed: %d\n", item);
        data->out = (data->out + 1) % BUFFER_SIZE;

        sem_post(sem_empty);       // Signal that buffer is not full
        sleep(rand() % 3);         // Simulate variable consumption time
    }
}

int main() {
    int shm_id;
    shared_data *data;
    sem_t *sem_full, *sem_empty;

    // Create semaphore for full and empty slots
    sem_full = sem_open("/sem_full", O_CREAT, 0644, 0);
    sem_empty = sem_open("/sem_empty", O_CREAT, 0644, BUFFER_SIZE);

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, sizeof(shared_data), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    data = (shared_data *)shmat(shm_id, NULL, 0);
    if (data == (shared_data *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Initialize producer and consumer indices
    data->in = 0;
    data->out = 0;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process - Consumer
        consumer(data, sem_full, sem_empty);
        exit(0);
    } else {
        // Parent process - Producer
        producer(data, sem_full, sem_empty);
        wait(NULL);  // Wait for child to finish
    }

    // Clean up
    shmdt(data);                      // Detach shared memory
    shmctl(shm_id, IPC_RMID, NULL);  // Remove shared memory
    sem_close(sem_full);
    sem_close(sem_empty);
    sem_unlink("/sem_full");
    sem_unlink("/sem_empty");
    
    return 0;
}