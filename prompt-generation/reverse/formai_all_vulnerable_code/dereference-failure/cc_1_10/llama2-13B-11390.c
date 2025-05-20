//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define SHM_KEY 0xdeadbeef

void* shm_create(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
}

void shm_destroy(void* shm) {
    munmap(shm, SHM_SIZE);
    shmctl(SHM_KEY, IPC_RMID, 0);
}

int main() {
    // Create shared memory
    void* shm = shm_create(SHM_SIZE);
    if (!shm) {
        perror("shm_create");
        exit(EXIT_FAILURE);
    }

    // Write a message to shared memory
    char* message = "Hello, world!";
    memcpy(shm, message, strlen(message));

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process reads from shared memory
        char* shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
    } else {
        // Parent process waits for child process to finish
        wait(NULL);
    }

    // Destroy shared memory
    shm_destroy(shm);

    return 0;
}