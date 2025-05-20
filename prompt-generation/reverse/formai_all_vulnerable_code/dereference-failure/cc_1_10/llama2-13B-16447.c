//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

void *shm_region;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_region = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_region == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a message to be sent
    char message[] = "Hello, world!";
    strcpy(shm_region, message);

    // Create a new process to receive the message
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        shm_region = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
        if (shm_region == MAP_FAILED) {
            perror("mmap");
            return 1;
        }

        // Receive the message
        char *message_ptr = shm_region;
        printf("Received message: %s\n", message_ptr);

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        wait(NULL);
    }

    // Unmap the shared memory region
    munmap(shm_region, SHM_SIZE);

    return 0;
}