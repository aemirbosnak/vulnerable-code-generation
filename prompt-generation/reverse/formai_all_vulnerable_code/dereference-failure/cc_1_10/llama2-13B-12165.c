//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

void* shm_addr;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Create a shared message
    char* message = "Hello, world!";
    strcpy(shm_addr, message);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }

    // In child process, read the shared message
    if (pid > 0) {
        char read_message[SHM_SIZE];
        memcpy(read_message, shm_addr, SHM_SIZE);
        printf("Received message: %s\n", read_message);
    } else {
        // In parent process, write to the shared message
        char* new_message = "Hello again!";
        strcpy(shm_addr, new_message);
    }

    // Unmap the shared memory
    munmap(shm_addr, SHM_SIZE);

    // Wait for the child process to finish
    wait(NULL);

    return 0;
}