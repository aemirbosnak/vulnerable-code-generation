//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 0x1234
#define SIZE 1024

void *attach_shm(int shmid) {
    void *ptr;
    ptr = shmat(shmid, NULL, 0);
    if ((long)ptr == -1) {
        perror("shmat");
        exit(1);
    }
    return ptr;
}

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = attach_shm(shmid);

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        // Write to shared memory
        strcpy(shm, "Hello from child process!");
    } else {
        // Parent process
        sleep(2);
        // Read from shared memory
        printf("Shared memory contains: %s\n", shm);
    }

    return 0;
}