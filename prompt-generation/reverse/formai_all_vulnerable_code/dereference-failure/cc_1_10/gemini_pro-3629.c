//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define KEY 1234
#define SIZE 1024

int main() {
    int shmid;
    char *shm;

    // Create shared memory
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Child process writes to shared memory
    if (pid == 0) {
        strcpy(shm, "Hello from child process");
        exit(0);
    }

    // Parent process waits for child process to finish
    wait(NULL);

    // Parent process reads from shared memory
    printf("Message from child process: %s\n", shm);

    // Detach shared memory
    shmdt(shm);

    // Destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}