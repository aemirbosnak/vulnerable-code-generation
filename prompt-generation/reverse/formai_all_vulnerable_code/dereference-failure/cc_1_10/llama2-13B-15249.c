//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    char *shm = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a message to the shared memory
    char message[] = "Hello from child process!";
    strcpy(shm, message);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child process
        char *message = shm;
        printf("Received message: %s\n", message);
        // Do something with the message
        sleep(5);
        printf("Child process done\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process done\n");
    }

    // Unmap the shared memory
    munmap(shm, BUFFER_SIZE);

    return 0;
}