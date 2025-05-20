//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0
#define SEM_ID 0x1234
#define SHM_KEY 0x5678
#define SHM_SIZE 1024

int main() {
    int shmid, semid;
    char *shmptr;
    struct sembuf sem_op;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid < 0) {
        printf("Error: Failed to create shared memory segment.\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error: Failed to attach shared memory segment.\n");
        exit(1);
    }

    // Initialize semaphore
    semid = semget(SEM_ID, 1, 0666);
    if (semid < 0) {
        printf("Error: Failed to create semaphore.\n");
        exit(1);
    }

    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(semid, &sem_op, 1) < 0) {
        printf("Error: Failed to initialize semaphore.\n");
        exit(1);
    }

    // Write to shared memory
    strcpy(shmptr, "Hello, world!");

    // Signal semaphore
    sem_op.sem_op = 0;
    if (semop(semid, &sem_op, 1) < 0) {
        printf("Error: Failed to signal semaphore.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error: Failed to attach shared memory segment.\n");
        exit(1);
    }

    // Read from shared memory
    printf("Shared memory content: %s\n", shmptr);

    // Detach from shared memory segment
    if (shmdt(shmptr) < 0) {
        printf("Error: Failed to detach shared memory segment.\n");
        exit(1);
    }

    // Delete semaphore
    if (semctl(semid, 0, IPC_RMID) < 0) {
        printf("Error: Failed to delete semaphore.\n");
        exit(1);
    }

    return 0;
}