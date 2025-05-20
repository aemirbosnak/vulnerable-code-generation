//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>

#define SHM_NAME "shm_example"
#define SEM_PRODUCE "sem_produce"
#define SEM_CONSUME "sem_consume"
#define BUFFER_SIZE 10
#define ITEM_SIZE 32

typedef struct {
    char buffer[BUFFER_SIZE][ITEM_SIZE];
    int in;
    int out;
} SharedBuffer;

void producer(SharedBuffer *shared) {
    for (int i = 0; i < 20; ++i) {
        sem_wait(sem_open(SEM_CONSUME, 0)); // wait if consumer is not ready
        snprintf(shared->buffer[shared->in], ITEM_SIZE, "Item %d", i);
        printf("Produced: %s\n", shared->buffer[shared->in]);
        
        shared->in = (shared->in + 1) % BUFFER_SIZE;
        sem_post(sem_open(SEM_PRODUCE, 0)); // signal that produce is done
        
        sleep(1);  // simulate time taken to produce an item
    }
}

void consumer(SharedBuffer *shared) {
    for (int i = 0; i < 20; ++i) {
        sem_wait(sem_open(SEM_PRODUCE, 0)); // wait if producer is not ready
        printf("Consumed: %s\n", shared->buffer[shared->out]);
        
        shared->out = (shared->out + 1) % BUFFER_SIZE;
        sem_post(sem_open(SEM_CONSUME, 0)); // signal that consume is done
        
        sleep(2);  // simulate time taken to consume an item
    }
}

int main() {
    int shm_fd;
    SharedBuffer *shared;
    
    // Create shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedBuffer));
    shared = mmap(0, sizeof(SharedBuffer), PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    
    // Initialize shared buffer
    shared->in = 0;
    shared->out = 0;
    
    // Create semaphores
    sem_t *sem_produce = sem_open(SEM_PRODUCE, O_CREAT, 0644, 0);
    sem_t *sem_consume = sem_open(SEM_CONSUME, O_CREAT, 0644, BUFFER_SIZE);
    
    if (fork() == 0) {
        // Child process: Consumer
        consumer(shared);
        exit(0);
    } else {
        // Parent process: Producer
        producer(shared);
        wait(NULL); // Wait for child process to finish
    }
    
    // Clean up
    sem_close(sem_produce);
    sem_close(sem_consume);
    sem_unlink(SEM_PRODUCE);
    sem_unlink(SEM_CONSUME);
    munmap(shared, sizeof(SharedBuffer));
    shm_unlink(SHM_NAME);
    
    return 0;
}