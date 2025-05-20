//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat() failed");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello, world!";
    strcpy(shm, message);

    // Create a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }

    // In the parent process, wait for the child process to finish
    if (pid > 0) {
        wait(NULL);
    }

    // In the child process, read the message from the shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat() failed");
        return 1;
    }
    printf("Received message: %s\n", shm);

    // Do some work...
    sleep(1);

    // Write a response to the shared memory
    char *response = "Hello, world back!";
    strcpy(shm, response);

    // Exit the child process
    exit(0);
}