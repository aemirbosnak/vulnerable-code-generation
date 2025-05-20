//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define MAX_TRIES 5
#define SEM_ID 0
#define SHM_ID 1

void die(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int semid, shmid, i;
    char *shm;
    struct sembuf sem_op;

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0777);
    if (shmid == -1) {
        die("shmget");
    }

    // Attach the shared memory segment to our data segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        die("shmat");
    }

    // Initialize the shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = '0' + i;
    }

    // Create a semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0777);
    if (semid == -1) {
        die("semget");
    }

    // Initialize the semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;

    while (semop(semid, &sem_op, 1) == -1) {
        if (errno!= EINTR) {
            die("semop");
        }
    }

    // Spawn a child process
    int pid = fork();
    if (pid == -1) {
        die("fork");
    } else if (pid == 0) {
        // Child process

        // Wait for the semaphore to be released
        while (semop(semid, &sem_op, 1) == -1) {
            if (errno!= EINTR) {
                die("semop");
            }
        }

        // Modify the shared memory segment
        for (i = 0; i < SIZE; i++) {
            shm[i] = 'A' + i;
        }

        // Release the semaphore
        sem_op.sem_op = -1;
        while (semop(semid, &sem_op, 1) == -1) {
            if (errno!= EINTR) {
                die("semop");
            }
        }

        // Exit the child process
        exit(0);
    } else {
        // Parent process

        // Wait for the child process to modify the shared memory segment
        int status;
        while (waitpid(pid, &status, 0) == -1) {
            if (errno!= EINTR) {
                die("waitpid");
            }
        }

        // Print the modified shared memory segment
        for (i = 0; i < SIZE; i++) {
            printf("%c ", shm[i]);
        }
        printf("\n");

        // Remove the shared memory segment and semaphore
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, SEM_ID, IPC_RMID, NULL);
    }

    return 0;
}