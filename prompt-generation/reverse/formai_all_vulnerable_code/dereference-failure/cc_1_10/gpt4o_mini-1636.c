//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>

#define SHM_SIZE 1024   // Size of shared memory
#define MAX_NUMBERS 10  // Max numbers to produce/consume

// Shared memory and semaphore identifiers
int shmid;
int semid;

// Create semaphore operations
void P(int semid, int semnum) {
    struct sembuf sb;
    sb.sem_num = semnum;
    sb.sem_op = -1; // Wait
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

void V(int semid, int semnum) {
    struct sembuf sb;
    sb.sem_num = semnum;
    sb.sem_op = 1; // Signal
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

// Function to handle cleanup on termination
void cleanup(int sig) {
    shmdt((void *)shmid);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    exit(0);
}

// Main function for the producer
void producer() {
    int *shared_memory = (int *)shmat(shmid, NULL, 0);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        P(semid, 0); // Wait for empty
        shared_memory[i % MAX_NUMBERS] = i + 1; // Produce a number
        printf("Produced: %d\n", i + 1);
        V(semid, 1); // Signal full
        sleep(rand() % 2); // Sleep for random time
    }
    
    shmdt((void *)shared_memory);
    exit(0);
}

// Main function for the consumer
void consumer() {
    int *shared_memory = (int *)shmat(shmid, NULL, 0);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        P(semid, 1); // Wait for full
        int number = shared_memory[i % MAX_NUMBERS]; // Consume a number
        printf("\tConsumed: %d\n", number);
        V(semid, 0); // Signal empty
        sleep(rand() % 2); // Sleep for random time
    }

    shmdt((void *)shared_memory);
    exit(0);
}

// Driver function
int main() {
    signal(SIGINT, cleanup);

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Create semaphores
    semid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }
    
    // Initialize semaphores
    semctl(semid, 0, SETVAL, MAX_NUMBERS); // Empty slots
    semctl(semid, 1, SETVAL, 0);           // Full slots

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        producer(); // Child process becomes the producer
    } else {
        consumer(); // Parent process becomes the consumer
    }

    // Wait for the child process to finish
    wait(NULL);
    
    cleanup(0); // Perform cleanup
    return 0;
}