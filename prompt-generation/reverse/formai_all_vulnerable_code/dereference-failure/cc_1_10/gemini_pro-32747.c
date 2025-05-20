//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SEM_KEY 1234
#define SHM_KEY 5678

int main() {
    int sem_id, shm_id;
    int *shm_ptr;
    struct sembuf sem_op;

    // Create semaphore
    if ((sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Create shared memory
    if ((shm_id = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    if ((shm_ptr = shmat(shm_id, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Set initial value in shared memory
    *shm_ptr = 0;

    printf("Parent process: waiting for child process to increment counter\n");

    // Wait for child process to increment counter
    sem_op.sem_op = -1;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    printf("Parent process: child process has incremented counter to %d\n", *shm_ptr);

    // Detach shared memory
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Delete semaphore
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}