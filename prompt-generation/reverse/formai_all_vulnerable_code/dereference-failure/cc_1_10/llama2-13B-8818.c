//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void *shm_addr;

int main() {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    printf("Parent process: shm_addr = %p\n", shm_addr);

    // Create a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process: shm_addr = %p\n", shm_addr);

        // Modify shared memory
        char *message = "Hello from child process!";
        memcpy(shm_addr, message, strlen(message));

        // Exit child process
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Check the shared memory
        char *message = "Hello from parent process!";
        memcpy(shm_addr, message, strlen(message));

        // Print the modified shared memory
        printf("Parent process: shm_addr = %p\n", shm_addr);
    }

    // Unmap shared memory
    munmap(shm_addr, size);

    return 0;
}