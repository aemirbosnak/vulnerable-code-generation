//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4096
#define SHM_KEY 0xdeadbeef

void *shm_alloc(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_PRIVATE | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *ptr = shmat(shmid, NULL, 0);
    if (ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void shm_free(void *ptr) {
    if (ptr == MAP_FAILED) {
        return;
    }
    shmctl(SHM_KEY, IPC_RMID, NULL);
}

int main() {
    // Parent process
    printf("Parent process starting...\n");

    // Create a shared memory segment
    void *shm_ptr = shm_alloc(SHM_SIZE);
    if (shm_ptr == MAP_FAILED) {
        perror("shm_alloc");
        exit(EXIT_FAILURE);
    }

    // Write some data to the shared memory
    char *data = "Hello, world!";
    memcpy(shm_ptr, data, strlen(data));

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        printf("Child process starting...\n");

        // Map the shared memory segment
        void *shm_ptr_child = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, SHM_KEY, 0);
        if (shm_ptr_child == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        // Print the data from the shared memory
        printf("Received message: %s\n", shm_ptr_child);

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
    }

    // Clean up the shared memory
    shm_free(shm_ptr);

    return 0;
}