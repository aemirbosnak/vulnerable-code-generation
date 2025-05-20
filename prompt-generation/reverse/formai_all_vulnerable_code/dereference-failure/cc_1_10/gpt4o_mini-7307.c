//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHM_SIZE 256
#define SEM_PRODUCER "/sem_producer"
#define SEM_CONSUMER "/sem_consumer"

void producer(const char *shm_name) {
    int shm_fd;
    char *shm_ptr;
    sem_t *sem_producer = sem_open(SEM_PRODUCER, O_CREAT, 0644, 1);
    sem_t *sem_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0644, 0);

    // Open shared memory
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shm_ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    for (int i = 0; i < 10; i++) {
        sem_wait(sem_producer); // Wait for producer semaphore

        snprintf(shm_ptr, SHM_SIZE, "Message %d from Producer", i);
        printf("Producer wrote: %s\n", shm_ptr);

        sem_post(sem_consumer); // Signal consumer semaphore
        sleep(1); // Simulate work
    }

    // Cleanup
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_producer);
    sem_close(sem_consumer);
}

void consumer(const char *shm_name) {
    int shm_fd;
    char *shm_ptr;
    sem_t *sem_producer = sem_open(SEM_PRODUCER, 0);
    sem_t *sem_consumer = sem_open(SEM_CONSUMER, 0);

    // Open shared memory
    shm_fd = shm_open(shm_name, O_RDWR, 0666);
    shm_ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    for (int i = 0; i < 10; i++) {
        sem_wait(sem_consumer); // Wait for consumer semaphore

        printf("Consumer read: %s\n", shm_ptr);

        sem_post(sem_producer); // Signal producer semaphore
        sleep(1); // Simulate work
    }

    // Cleanup
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_producer);
    sem_close(sem_consumer);
}

int main() {
    const char *shm_name = "/my_shared_memory";

    // Forking to create producer and consumer
    pid_t pid = fork();

    if (pid == 0) {
        // Child process (Consumer)
        consumer(shm_name);
        exit(0);
    } else {
        // Parent process (Producer)
        producer(shm_name);
        wait(NULL); // Wait for child to finish
    }

    // Clean up shared memory and semaphores on exit
    shm_unlink(shm_name);
    sem_unlink(SEM_PRODUCER);
    sem_unlink(SEM_CONSUMER);

    return 0;
}