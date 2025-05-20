//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_NAME "my_shared_mem"
#define SHM_SIZE 1024

void *shm_addr;

int main() {
    key_t key = IPC_PRIVATE;
    int shm_id = shmget(SHM_NAME, SHM_SIZE, IPC_PRIVATE | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget");
        return 1;
    }

    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a shared message buffer
    char *msg = "Hello, world!";
    strcpy(shm_addr, msg);

    // Fork a child process to read the shared memory
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(shm_id);
        munmap(shm_addr, SHM_SIZE);
        printf("Received message: %s\n", shm_addr);
        exit(0);
    } else {
        // Parent process
        wait(NULL);
    }

    // Write a message to the shared memory
    char *new_msg = "Goodbye, world!";
    strcpy(shm_addr, new_msg);

    // Wait for the child process to read the message
    wait(NULL);

    return 0;
}