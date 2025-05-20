//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_SIZE (1024 * 1024)

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0644);
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

    // Create a mapping of the shared memory to the current process's address space
    mmap(shm, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);

    // Write a message to the shared memory
    char *message = "Hello, world!";
    memcpy(shm, message, strlen(message));

    // Fork a child process to read the message
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid == 0) {
        // Child process reads the message from the shared memory
        char *shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
        exit(0);
    } else {
        // Parent process waits for the child process to finish
        wait(NULL);
    }

    // Unmap the shared memory
    munmap(shm, SHM_SIZE);

    // Detach from the shared memory segment
    shmdt(shm);

    return 0;
}