//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 1024

int main() {
    int shmid;
    void *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, (void*)0, 0);
    if (shmptr == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        char *msg = "Hello from the child process!";
        strcpy(shmptr, msg);
        printf("Child process wrote to shared memory\n");
        exit(0);
    } else {
        // Parent process reads from shared memory
        wait(NULL);
        char msg[SIZE];
        strcpy(msg, shmptr);
        printf("Parent process read from shared memory: %s\n", msg);
        exit(0);
    }

    return 0;
}