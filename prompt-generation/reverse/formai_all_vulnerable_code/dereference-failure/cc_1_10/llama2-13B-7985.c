//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void* shm_alloc(size_t size)
{
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0600);
    if (shmid == -1) {
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

void shm_free(void* shm)
{
    munmap(shm, SHM_SIZE);
    shmctl(SHM_KEY, IPC_RMID, 0);
}

int main()
{
    // Create a shared memory segment
    void* shm = shm_alloc(SHM_SIZE);
    if (shm == NULL) {
        perror("shm_alloc");
        exit(EXIT_FAILURE);
    }

    // Write some data to the shared memory
    char* data = "Hello, world!";
    strcpy(shm, data);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process reading shared memory...\n");

        // Mmap the shared memory
        void* mapped_shm = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shm, 0);
        if (mapped_shm == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        // Print the data
        printf("Shared memory contents: %s\n", mapped_shm);

        // Unmap the shared memory
        munmap(mapped_shm, SHM_SIZE);
    } else {
        // Parent process
        printf("Parent process writing shared memory...\n");

        // Write some more data to the shared memory
        strcpy(shm, "Hello again!");
    }

    // Wait for the child process to finish
    wait(NULL);

    // Free the shared memory
    shm_free(shm);

    return 0;
}