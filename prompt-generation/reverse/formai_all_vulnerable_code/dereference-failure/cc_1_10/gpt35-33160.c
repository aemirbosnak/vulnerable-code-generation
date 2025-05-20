//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// function prototype
void parentProcess(int shmid);
void childProcess(int shmid);

int main() {
    pid_t pid;
    int shmid;
    int *sharedMem;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // attach shared memory segment to process
    sharedMem = shmat(shmid, NULL, 0);
    if (sharedMem == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // set initial value to shared memory
    *sharedMem = 0;

    // create child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        childProcess(shmid);
    } else {
        // parent process
        parentProcess(shmid);
    }

    // detach shared memory segment from process
    if (shmdt(sharedMem) < 0) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void parentProcess(int shmid) {
    int *sharedMem = shmat(shmid, NULL, 0);
    if (sharedMem == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    while (*sharedMem < 10) {
        // waiting for child to modify shared memory
    }

    printf("Parent process: shared memory value is now %d\n", *sharedMem);

    // detach shared memory segment from process
    if (shmdt(sharedMem) < 0) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // wait for child process to terminate
    wait(NULL);
}

void childProcess(int shmid) {
    int *sharedMem = shmat(shmid, NULL, 0);
    if (sharedMem == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    while (*sharedMem < 10) {
        (*sharedMem)++;
        printf("Child process: shared memory value is now %d\n", *sharedMem);
        usleep(500000);
    }

    // detach shared memory segment from process
    if (shmdt(sharedMem) < 0) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}