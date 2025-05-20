//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Create a mapped memory region
    void *addr = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (addr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Write a message to the shared memory
    char message[] = "Hello, world!";
    strcpy(addr, message);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Received message: %s\n", message);
        sleep(5);
        // Write a response to the shared memory
        char response[] = "Hello, parent!";
        strcpy(addr, response);
    } else {
        // Parent process
        sleep(5);
        // Read the response from the shared memory
        char response[BUFFER_SIZE];
        memcpy(response, addr, BUFFER_SIZE);
        printf("Received response: %s\n", response);
    }

    // Unmap the shared memory
    munmap(addr, BUFFER_SIZE);

    return 0;
}