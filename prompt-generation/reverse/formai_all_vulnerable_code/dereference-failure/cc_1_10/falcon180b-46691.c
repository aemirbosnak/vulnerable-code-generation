//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_KEY 0x1234
#define SEM_SIZE 10
#define SHM_KEY 0x5678
#define SHM_SIZE 100

int main() {
    int shmid, semid;
    char *shmptr;
    int i, value = 0;

    // Create shared memory
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create shared memory\n");
        exit(1);
    }

    // Attach shared memory
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Failed to attach shared memory\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SHM_SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Failed to create semaphore\n");
        exit(1);
    }

    // Initialize semaphore
    semctl(semid, 0, SETVAL, 1);

    // Fork child process
    int pid = fork();
    if (pid == -1) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < SHM_SIZE; i++) {
            *(shmptr + i) = i;
        }
        value = *(shmptr + 9);
        printf("Child process: Value in shared memory is %d\n", value);
        exit(0);
    } else {
        // Parent process
        sleep(2);
        semctl(semid, 0, GETVAL, &value);
        printf("Parent process: Value in shared memory is %d\n", value);
        exit(0);
    }

    return 0;
}