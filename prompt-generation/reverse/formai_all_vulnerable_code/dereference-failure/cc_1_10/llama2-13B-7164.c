//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_memory"
#define SHM_SIZE 1024

typedef struct {
    int data[10];
} shared_data_t;

void *shm_addr;

int main() {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a shared data structure
    shared_data_t *shared_data = (shared_data_t *)shm_addr;
    shared_data->data[0] = 1;
    shared_data->data[1] = 2;
    shared_data->data[2] = 3;

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());

        // Access the shared memory
        shared_data_t *child_data = (shared_data_t *)shm_addr;
        child_data->data[3] = 4;

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());

        // Wait for the child process to exit
        wait(NULL);

        // Access the shared memory again
        shared_data_t *parent_data = (shared_data_t *)shm_addr;
        printf("Parent process: data[3] = %d\n", parent_data->data[3]);
    }

    // Unmap the shared memory
    munmap(shm_addr, SHM_SIZE);

    return 0;
}