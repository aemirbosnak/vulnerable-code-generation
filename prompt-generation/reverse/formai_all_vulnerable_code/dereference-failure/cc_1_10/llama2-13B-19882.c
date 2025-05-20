//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello, world!";
    strcpy(shm, message);

    // Create a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child process
        char *shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
    } else {
        // Parent process
        wait(NULL);
        printf("Message sent successfully\n");
    }

    // Unmap the shared memory
    munmap(shm, SHM_SIZE);

    return 0;
}