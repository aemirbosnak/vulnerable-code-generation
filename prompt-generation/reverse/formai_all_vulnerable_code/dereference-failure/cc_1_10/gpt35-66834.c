//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024

// Shared memory buffer 
struct shm_buffer {
    int data[SHM_SIZE];
    int count;
    int sem_id;
};

// Semaphores
#define SEM_EMPTY 0
#define SEM_FULL 1

// Signal handlers
void sigint_handler(int sig) {
    printf("Process interrupted!\n");
    exit(0);
}

void sigsegv_handler(int sig) {
    printf("Oops, segmentation fault!\n");
    exit(1);
}

int main(void) {
    // Set up signal handlers
    signal(SIGINT, sigint_handler);
    signal(SIGSEGV, sigsegv_handler);

    // Create shared memory segment
    int shm_id = shmget(IPC_PRIVATE, sizeof(struct shm_buffer), IPC_CREAT | 0666);
    struct shm_buffer* shm = (struct shm_buffer*) shmat(shm_id, 0, 0);

    // Initialize shared memory buffer
    shm->count = 0;
    int i;
    for (i = 0; i < SHM_SIZE; i++) {
        shm->data[i] = 0;
    }

    // Create semaphores
    int sem_id = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
    semctl(sem_id, SEM_EMPTY, SETVAL, SHM_SIZE);
    semctl(sem_id, SEM_FULL, SETVAL, 0);
    shm->sem_id = sem_id;

    // Fork child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        while (1) {
            // Wait until there is data in the buffer
            struct sembuf sem_op = {SEM_FULL, -1, 0};
            semop(sem_id, &sem_op, 1);

            // Read data from buffer
            int data = shm->data[shm->count - 1];
            printf("Child process read data: %d\n", data);

            // Decrement count and signal empty space available
            shm->count--;
            sem_op.sem_num = SEM_EMPTY;
            sem_op.sem_op = 1;
            semop(sem_id, &sem_op, 1);

            // Sleep for some time
            usleep(100000);
        }

    } else {
        // Parent process
        int data = 0;
        while (1) {
            // Wait until there is space in the buffer
            struct sembuf sem_op = {SEM_EMPTY, -1, 0};
            semop(sem_id, &sem_op, 1);

            // Generate random data and add to buffer
            data++;
            shm->data[shm->count] = data;
            printf("Parent process added data: %d\n", data);

            // Increment count and signal data written
            shm->count++;
            sem_op.sem_num = SEM_FULL;
            sem_op.sem_op = 1;
            semop(sem_id, &sem_op, 1);

            // Sleep for some time
            usleep(100000);
        }
    }

    // Clean up shared memory and semaphores
    shmdt(shm);
    shmctl(shm_id, IPC_RMID, 0);
    semctl(sem_id, 0, IPC_RMID);

    return 0;
}