//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <errno.h>

#define SHM_SIZE 1024  // Size of shared memory
#define SEM_KEY 12345  // Semaphore key
#define SHM_KEY 56789  // Shared memory key
#define MAX_NUMBERS 10 // Number of items to produce/consume

// Union for semaphore operation
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Function to perform a semaphore wait (P operation)
void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0}; // P operation
    semop(semid, &sb, 1);
}

// Function to perform a semaphore signal (V operation)
void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0}; // V operation
    semop(semid, &sb, 1);
}

// Producer function
void producer(int semid, int shmid) {
    int *shm_ptr = (int *)shmat(shmid, NULL, 0); // Attach to shared memory

    for (int i = 0; i < MAX_NUMBERS; i++) {
        sem_wait(semid); // Wait until there's space in the buffer

        shm_ptr[i] = rand() % 100; // Produce a random number
        printf("Produced: %d\n", shm_ptr[i]);
        
        sem_signal(semid); // Signal that there is a new item
        sleep(1); // Simulate time taken to produce
    }

    shmdt(shm_ptr); // Detach from shared memory
}

// Consumer function
void consumer(int semid, int shmid) {
    int *shm_ptr = (int *)shmat(shmid, NULL, 0); // Attach to shared memory

    for (int i = 0; i < MAX_NUMBERS; i++) {
        sem_wait(semid); // Wait until an item is produced

        int item = shm_ptr[i]; // Consume the number
        printf("Consumed: %d\n", item);
        
        sem_signal(semid); // Signal that space is available
        sleep(1); // Simulate time taken to consume
    }

    shmdt(shm_ptr); // Detach from shared memory
}

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666); // Create shared memory
    if (shmid < 0) {
        perror("Failed to create shared memory");
        return 1;
    }

    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666); // Create semaphore
    if (semid < 0) {
        perror("Failed to create semaphore");
        return 1;
    }

    union semun sem_union;
    sem_union.val = 1; // Initialize semaphore value to 1
    if (semctl(semid, 0, SETVAL, sem_union) < 0) {
        perror("Failed to initialize semaphore");
        return 1;
    }

    if (fork() == 0) {
        // Child process runs the producer
        producer(semid, shmid);
        exit(0);
    } else {
        // Parent process runs the consumer
        consumer(semid, shmid);
        wait(NULL); // Wait for the child process to finish
    }

    // Clean up resources
    shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    semctl(semid, 0, IPC_RMID); // Remove semaphore
    return 0;
}