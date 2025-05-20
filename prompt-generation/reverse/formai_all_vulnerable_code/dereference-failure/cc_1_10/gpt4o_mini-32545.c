//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <time.h>

#define SHM_NAME "/my_shared_memory"
#define SEM_EMPTY_NAME "/sem_empty"
#define SEM_FULL_NAME "/sem_full"
#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
} SharedData;

void producer(SharedData *data, sem_t *sem_empty, sem_t *sem_full) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < 20; i++) {
        int number = rand() % 100; // Generate random number
        sem_wait(sem_empty); // Wait if the buffer is full

        // Produce a number
        data->buffer[data->in] = number;
        printf("Produced: %d\n", number);
        data->in = (data->in + 1) % BUFFER_SIZE;

        sem_post(sem_full); // Signal that the buffer has data
        sleep(1); // Simulate time taken to produce
    }
}

void consumer(SharedData *data, sem_t *sem_empty, sem_t *sem_full) {
    for (int i = 0; i < 20; i++) {
        sem_wait(sem_full); // Wait if the buffer is empty

        // Consume a number
        int number = data->buffer[data->out];
        printf("Consumed: %d\n", number);
        data->out = (data->out + 1) % BUFFER_SIZE;

        sem_post(sem_empty); // Signal that there is space in the buffer
        sleep(2); // Simulate time taken to consume
    }
}

int main() {
    // Create shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedData));
    SharedData *data = mmap(0, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    data->in = 0;
    data->out = 0;

    // Create semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, BUFFER_SIZE);
    sem_t *sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);

    // Fork to create a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) { // Child process
        consumer(data, sem_empty, sem_full);
    } else { // Parent process
        producer(data, sem_empty, sem_full);
        wait(NULL); // Wait for child to finish
    }

    // Cleanup
    sem_close(sem_empty);
    sem_close(sem_full);
    shm_unlink(SHM_NAME);
    sem_unlink(SEM_EMPTY_NAME);
    sem_unlink(SEM_FULL_NAME);
    munmap(data, sizeof(SharedData));
    close(shm_fd);

    return 0;
}