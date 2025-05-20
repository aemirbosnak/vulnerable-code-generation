//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void *shm_ptr;

int main() {
    key_t key = SHM_KEY;
    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0600);
    if (shm_id < 0) {
        perror("shmget");
        return 1;
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Protected communication using mmap
    char *message = "Hello from child process!";
    memcpy(shm_ptr, message, strlen(message));

    // Wait for the parent process to read the message
    while (1) {
        wait(NULL);
    }

    return 0;
}

int child_process() {
    key_t key = SHM_KEY;
    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0600);
    if (shm_id < 0) {
        perror("shmget");
        return 1;
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Read the message from the shared memory
    char *message = (char *)shm_ptr;
    printf("Received message from parent process: %s\n", message);

    // Clean up
    munmap(shm_ptr, SHM_SIZE);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}