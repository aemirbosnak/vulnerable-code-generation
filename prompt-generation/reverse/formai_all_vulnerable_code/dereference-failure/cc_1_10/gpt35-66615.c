//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x123456  // Shared memory key
#define SEM_KEY 0x654321  // Semaphore key
#define BUFFER_SIZE 10    // Size of shared buffer

// Struct representing a buffer of integers
typedef struct {
    int data[BUFFER_SIZE];
    int in;   // Index to put data into buffer
    int out;  // Index to take data from buffer
} SharedBuffer;

// Function to create shared memory segment and semaphore
void createResources(int *shmId, SharedBuffer **buffer, int *semId) {
    // Create shared memory segment for buffer
    *shmId = shmget(SHM_KEY, sizeof(SharedBuffer), IPC_CREAT | 0666);
    if (*shmId == -1) {
        perror("shmget");
        exit(1);
    }
    
    // Attach to shared memory segment
    *buffer = shmat(*shmId, NULL, 0);
    if (*buffer == (void *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Initialize buffer indices
    (*buffer)->in = 0;
    (*buffer)->out = 0;
    
    // Create semaphore for buffer
    *semId = semget(SEM_KEY, 2, IPC_CREAT | 0666);
    if (*semId == -1) {
        perror("semget");
        exit(1);
    }
    
    // Initialize semaphore values
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    arg.val = 1;   // For mutex
    semctl(*semId, 0, SETVAL, arg);
    arg.val = BUFFER_SIZE;  // For empty slots
    semctl(*semId, 1, SETVAL, arg);
}

// Function to delete shared memory segment and semaphore
void deleteResources(int shmId, SharedBuffer *buffer, int semId) {
    // Detach from shared memory segment
    if (shmdt(buffer) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Delete shared memory segment
    if (shmctl(shmId, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    // Delete semaphore
    if (semctl(semId, 0, IPC_RMID, 0) == -1) {
        perror("semctl");
        exit(1);
    }
}

// Function for producer process
void producer(SharedBuffer *buffer, int semId) {
    int i, item;
    for (i = 0; i < 100; i++) {
        // Wait for empty slot(s) in buffer
        struct sembuf semOps[2] = {
            {1, -1, 0},  // Wait for empty slots
            {0, -1, 0}   // Wait for mutex
        };
        semop(semId, semOps, 2);
        
        // Put item into buffer
        item = i + 1;  // Generate item
        buffer->data[buffer->in] = item;
        buffer->in = (buffer->in + 1) % BUFFER_SIZE;
        printf("Producer produced %d\n", item);
        
        // Release mutex and signal full slot(s) in buffer
        semOps[0].sem_op = 1;  // Signal full slots
        semOps[1].sem_op = 1;  // Release mutex
        semop(semId, semOps, 2);
        
        // Simulate some work time
        usleep(50000);
    }
}

// Function for consumer process
void consumer(SharedBuffer *buffer, int semId) {
    int i, item;
    for (i = 0; i < 100; i++) {
        // Wait for full slot(s) in buffer
        struct sembuf semOps[2] = {
            {0, -1, 0},  // Wait for mutex
            {1, -1, 0}   // Wait for full slots
        };
        semop(semId, semOps, 2);
        
        // Take item from buffer
        item = buffer->data[buffer->out];
        buffer->out = (buffer->out + 1) % BUFFER_SIZE;
        printf("Consumer consumed %d\n", item);
        
        // Release mutex and signal empty slot(s) in buffer
        semOps[0].sem_op = 1;  // Signal empty slots
        semOps[1].sem_op = 1;  // Release mutex
        semop(semId, semOps, 2);
        
        // Simulate some work time
        usleep(100000);
    }
}

int main() {
    int shmId, semId;
    SharedBuffer *buffer;
    
    // Create shared memory segment and semaphore
    createResources(&shmId, &buffer, &semId);
    
    // Fork off a child process to be the producer
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        producer(buffer, semId);
        return 0;
    } else if (pid == -1) {
        // Error forking
        perror("fork");
        deleteResources(shmId, buffer, semId);
        exit(1);
    }
    
    // Parent process is the consumer
    consumer(buffer, semId);
    
    // Wait for child process to finish
    int status;
    waitpid(pid, &status, 0);
    
    // Delete shared memory segment and semaphore
    deleteResources(shmId, buffer, semId);
    
    return 0;
}