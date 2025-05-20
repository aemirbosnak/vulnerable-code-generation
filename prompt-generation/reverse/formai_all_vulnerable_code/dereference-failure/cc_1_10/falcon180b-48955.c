//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024
#define SEM_KEY 5678
#define SEM_VALUE 1

int main() {
    int shmid, semid;
    char *shm;
    int *sem;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shm, 0, SHM_SIZE);

    // Create semaphore
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore value
    sem = (int *) semctl(semid, 0, SETVAL, SEM_VALUE);
    if (sem == (void *) -1) {
        perror("semctl");
        exit(1);
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        int count = 0;
        while (count < 10) {
            // Lock semaphore
            sem_wait(sem);

            // Increment shared memory value
            int *value = (int *) shm;
            (*value)++;

            // Unlock semaphore
            sem_post(sem);

            // Print shared memory value
            printf("Child: Shared memory value = %d\n", *value);

            count++;
            usleep(100000);
        }
        exit(0);
    } else {
        // Parent process
        int count = 0;
        while (count < 10) {
            // Lock semaphore
            sem_wait(sem);

            // Print shared memory value
            int *value = (int *) shm;
            printf("Parent: Shared memory value = %d\n", *value);

            // Unlock semaphore
            sem_post(sem);

            count++;
            usleep(100000);
        }
        exit(0);
    }

    return 0;
}