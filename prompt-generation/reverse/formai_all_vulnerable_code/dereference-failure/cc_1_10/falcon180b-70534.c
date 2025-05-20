//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 1000

// Structure for shared memory
struct shm_struct {
    int count;
    char data[SIZE];
};

int main() {
    int shmid, shmfd, pid;
    struct shm_struct *shmptr;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if ((long) shmptr == -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shmptr->count = 0;
    for (int i = 0; i < SIZE; i++) {
        shmptr->data[i] = '\0';
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        shmptr->count += 1;
        strcpy(shmptr->data, "Child process");

        // Detach from shared memory segment
        shmdt(shmptr);

        // Exit child process
        exit(0);
    } else {
        // Parent process reads from shared memory
        wait(NULL);

        shmptr->count += 1;
        strcpy(shmptr->data, "Parent process");

        // Detach from shared memory segment
        shmdt(shmptr);
    }

    // Remove shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}