//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <string.h>

#define MEM_SIZE 1024
#define NUM_ITEMS 10

// Semaphore operations
void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

int main() {
    int shmid, semid;
    key_t key = ftok("shmfile",65);
    
    // Create shared memory segment
    shmid = shmget(key, MEM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Create semaphore for synchronization
    semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1); // Initialize semaphore value to 1

    char *shared_memory = (char *)shmat(shmid, NULL, 0);
    if (shared_memory == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Consumer process
        for (int i = 0; i < NUM_ITEMS; i++) {
            sem_wait(semid);  // Wait for semaphore
            printf("Consumer: Read value %s\n", shared_memory);
            memset(shared_memory, 0, MEM_SIZE);  // Clear memory after reading
            sem_signal(semid);  // Signal semaphore
            sleep(1);  // Simulate work
        }
    } else {
        // Producer process
        for (int i = 0; i < NUM_ITEMS; i++) {
            char value[20];
            snprintf(value, sizeof(value), "Item %d", i + 1); // Create new item

            sem_wait(semid);  // Wait for semaphore
            strncpy(shared_memory, value, MEM_SIZE); // Write new item to shared memory
            printf("Producer: Wrote value %s\n", value);
            sem_signal(semid);  // Signal semaphore
            sleep(1);  // Simulate work
        }
        wait(NULL);  // Wait for consumer to finish
        shmdt(shared_memory);  // Detach shared memory
        shmctl(shmid, IPC_RMID, NULL);  // Destroy shared memory
        semctl(semid, 0, IPC_RMID); // Destroy semaphore
    }

    return 0;
}