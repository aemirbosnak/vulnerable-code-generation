//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define KEY 0x1234
#define MAX_SIZE 100

int main() {
    int shm_id, sem_id;
    char *shm;
    int i, j;

    // Create shared memory segment
    shm_id = shmget(KEY, MAX_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shm = shmat(shm_id, NULL, 0);
    if ((long)shm == -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < MAX_SIZE; i++) {
        shm[i] = 0;
    }

    // Create semaphore
    sem_id = semget(KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    semctl(sem_id, 0, SETVAL, 0);

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        shmdt(shm);
        semctl(sem_id, 0, IPC_RMID);
        exit(0);
    } else {
        // Child process
        for (j = 0; j < MAX_SIZE; j++) {
            shm[j] = j;
        }

        for (j = 0; j < MAX_SIZE; j++) {
            sem_wait(sem_id);
            printf("Child process: %d\n", shm[j]);
        }

        shmdt(shm);
        exit(0);
    }
}