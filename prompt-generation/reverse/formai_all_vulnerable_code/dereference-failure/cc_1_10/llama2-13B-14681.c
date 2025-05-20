//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define SHM_KEY 0x12345678

void* shm_alloc(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }
    void* shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_free(void* shm) {
    if (munmap(shm, BUFFER_SIZE) == -1) {
        perror("munmap() failed");
    }
    shmctl(SHM_KEY, IPC_RMID, 0);
}

int main() {
    // Create a shared memory segment
    void* shm = shm_alloc(BUFFER_SIZE);
    if (!shm) {
        perror("shm_alloc() failed");
        exit(EXIT_FAILURE);
    }

    // Write some data to the shared memory
    char* data = "Hello, world!";
    memcpy(shm, data, strlen(data));

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        // Mmap the shared memory into our address space
        void* mapped_shm = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0);
        if (mapped_shm == MAP_FAILED) {
            perror("mmap() failed");
            exit(EXIT_FAILURE);
        }

        // Print the data from the shared memory
        printf("Received message: %s\n", mapped_shm);

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        // Wait for the child process to finish
        wait(NULL);

        // Print the data from the shared memory
        printf("Sent message: %s\n", shm);

        // Clean up
        shm_free(shm);
    }

    return 0;
}