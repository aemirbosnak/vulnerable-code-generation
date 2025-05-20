//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xDEADBEEF

void* shm_alloc(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return NULL;
    }
    void* shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    return shm;
}

void shm_free(void* shm) {
    if (shm == MAP_FAILED) {
        return;
    }
    munmap(shm, sizeof(int));
    shmctl(SHM_KEY, IPC_RMID, 0);
}

int main() {
    int shmid = shmget(SHM_KEY, 100, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    void* shm = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a message of gratitude to the shared memory
    char* message = "Thank you for reading this program! 😊";
    strcpy(shm, message);

    // Fork a child process to read the message
    pid_t pid = fork();
    if (pid == 0) {
        // Child process reads the message from shared memory
        char* message_copy = shm;
        printf("Received message: %s\n", message_copy);
    } else {
        // Parent process waits for the child process to finish
        wait(NULL);
    }

    // Clean up and exit
    shm_free(shm);
    return 0;
}