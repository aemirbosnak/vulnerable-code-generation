//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void *shm_ptr;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a shared memory message
    char message[] = "Hello from the other process!";
    strcpy(shm_ptr, message);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Received message: %s\n", shm_ptr);

        // Write a new message to the shared memory
        char new_message[] = "Hello again!";
        strcpy(shm_ptr, new_message);

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        printf("Sent message: %s\n", shm_ptr);
    }

    // Unmap the shared memory
    munmap(shm_ptr, SHM_SIZE);

    return 0;
}