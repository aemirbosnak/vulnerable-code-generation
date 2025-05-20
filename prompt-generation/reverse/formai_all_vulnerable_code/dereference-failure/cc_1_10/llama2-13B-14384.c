//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define SHM_KEY 0xdeadbeef

void* shm_alloc(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_PRIVATE | IPC_CREAT);
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

void shm_free(void* shm) {
    munmap(shm, SHM_SIZE);
    shmctl(SHM_KEY, IPC_RMID, 0);
}

int main() {
    // Create shared memory
    void* shm = shm_alloc(SHM_SIZE);
    if (shm == NULL) {
        perror("shm_alloc");
        exit(EXIT_FAILURE);
    }

    // Write a message to shared memory
    char* message = "Hello, world!";
    strcpy(shm, message);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char* shm_addr = shm;
        printf("Received message: %s\n", shm_addr);

        // Exit child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);

        // Read message from shared memory
        char* shm_addr = shm;
        printf("Sent message: %s\n", shm_addr);
    }

    // Clean up
    shm_free(shm);
    return 0;
}