//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xDEADBEEF
#define SHM_SIZE 1024

void* create_shm_segment(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_PRIVATE | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void* shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return shm;
}

int main() {
    // Create a shared memory segment
    void* shm = create_shm_segment(SHM_SIZE);
    if (shm == MAP_FAILED) {
        perror("create_shm_segment");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory
    char* message = "Hello, brave world!";
    memcpy(shm, message, strlen(message));

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        char* shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
    } else {
        // Parent process
        wait(NULL);
    }

    // Unmap the shared memory
    munmap(shm, SHM_SIZE);

    return 0;
}