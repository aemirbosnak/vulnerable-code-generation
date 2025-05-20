//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <sys/mman.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define SHM_NAME "my_shared_mem"
#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(SHM_NAME, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello, world!";
    memcpy(shm, message, strlen(message));

    // Fork a new process to read the message
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }

    // In the child process, read the message from shared memory
    if (pid > 0) {
        // Wait for the child process to finish reading the message
        wait(NULL);
    } else {
        // In the child process, read the message from shared memory
        char *read_message = (char *)shm;
        printf("Received message: %s\n", read_message);
    }

    // Unmap the shared memory segment
    munmap(shm, SHM_SIZE);

    return 0;
}