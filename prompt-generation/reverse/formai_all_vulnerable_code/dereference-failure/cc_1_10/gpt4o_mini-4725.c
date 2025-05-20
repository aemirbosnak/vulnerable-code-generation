//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

#define SHM_SIZE 10  // Size of the shared memory buffer
#define MAX_NUM 100  // Maximum number to produce

// Structure to hold shared data
typedef struct {
    int buffer[SHM_SIZE];
    int in;   // Producer index
    int out;  // Consumer index
    sem_t mutex;          // Semaphore for mutual exclusion
    sem_t full;           // Semaphore to count full slots
    sem_t empty;          // Semaphore to count empty slots
} SharedData;

int main() {
    int shm_fd;
    SharedData *data;

    // Create shared memory object
    shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedData));

    // Map shared memory object
    data = mmap(0, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    memset(data, 0, sizeof(SharedData));  // Clear the shared memory

    // Initialize semaphores
    sem_init(&data->mutex, 1, 1);
    sem_init(&data->full, 1, 0);
    sem_init(&data->empty, 1, SHM_SIZE);

    // Fork the process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process (Consumer)
        srand(time(NULL));
        for (int i = 0; i < 20; i++) { // Consume 20 items
            sem_wait(&data->full);       // Wait until there is at least 1 item
            sem_wait(&data->mutex);      // Enter critical section

            // Consume an item from the buffer
            int item = data->buffer[data->out];
            printf("Consumer consumed: %d\n", item);
            data->out = (data->out + 1) % SHM_SIZE;

            sem_post(&data->mutex);      // Exit critical section
            sem_post(&data->empty);      // Signal that there is now an empty slot

            sleep(rand() % 2);          // Simulate variable consume time
        }
    } else { // Parent process (Producer)
        srand(time(NULL) + 1);
        for (int i = 0; i < 20; i++) { // Produce 20 items
            int item = rand() % MAX_NUM;  // Produce a random number

            sem_wait(&data->empty);      // Wait until there is at least 1 empty slot
            sem_wait(&data->mutex);      // Enter critical section

            // Produce an item into the buffer
            data->buffer[data->in] = item;
            printf("Producer produced: %d\n", item);
            data->in = (data->in + 1) % SHM_SIZE;

            sem_post(&data->mutex);      // Exit critical section
            sem_post(&data->full);       // Signal that there is now a full slot

            sleep(rand() % 2);          // Simulate variable produce time
        }

        // Wait for the consumer to finish (optional)
        wait(NULL);

        // Cleanup
        sem_destroy(&data->mutex);
        sem_destroy(&data->full);
        sem_destroy(&data->empty);
        munmap(data, sizeof(SharedData));
        shm_unlink("/my_shm");
    }

    return 0;
}