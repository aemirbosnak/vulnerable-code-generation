//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define KEY 1234

int main() {
    int semid;
    int shmid;
    int *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) - 1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    // Create semaphore set
    semid = semget(KEY, 2, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore set\n");
        exit(1);
    }

    // Initialize semaphores
    semctl(semid, 0, SETVAL, 1);
    semctl(semid, 1, SETVAL, 0);

    // Fork child process
    int pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        int count = 0;
        for (i = 0; i < SIZE; i++) {
            semctl(semid, 0, GETVAL);
            shmptr[i] = count;
            semctl(semid, 1, GETVAL);
            count++;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        int count = 0;
        for (i = 0; i < SIZE; i++) {
            semctl(semid, 0, GETVAL);
            shmptr[i] = count;
            semctl(semid, 1, GETVAL);
            count++;
        }
        printf("Parent process completed\n");
        exit(0);
    }
}