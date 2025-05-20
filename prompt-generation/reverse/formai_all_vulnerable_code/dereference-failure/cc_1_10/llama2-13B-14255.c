//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_mem"
#define MESSAGE_MAX_LEN 1024

void *shm_alloc(size_t size) {
    int shmid = shmget(IPC_PRIVATE, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void shm_free(void *ptr) {
    munmap(ptr, strlen(SHM_NAME));
}

int main() {
    // Create a shared memory segment
    void *shm = shm_alloc(1024);
    if (shm == NULL) {
        perror("shm_alloc");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory
    char message[MESSAGE_MAX_LEN];
    strcpy(message, "Hello, world!");
    if (msync(shm, strlen(message), MS_ASYNC) == -1) {
        perror("msync");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
        // Do something with the message
        sleep(5);
        // Write a response to the shared memory
        char response[MESSAGE_MAX_LEN];
        strcpy(response, "Hello, parent!");
        if (msync(shm_ptr, strlen(response), MS_ASYNC) == -1) {
            perror("msync");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        char *shm_ptr = shm;
        printf("Sent message: %s\n", shm_ptr);
        sleep(10);
        // Read the response from the shared memory
        char response[MESSAGE_MAX_LEN];
        strcpy(response, shm_ptr);
        printf("Received response: %s\n", response);
    }

    // Clean up the shared memory
    shm_free(shm);
    return 0;
}