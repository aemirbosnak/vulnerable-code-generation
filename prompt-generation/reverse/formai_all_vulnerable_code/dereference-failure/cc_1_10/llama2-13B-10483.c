//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xDEADBEEF

void *shm_malloc(size_t size) {
    void *ptr = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (ptr == NULL) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void shm_free(void *ptr) {
    shmctl(SHM_KEY, IPC_RMID, NULL);
}

int main() {
    // Create a shared memory segment
    void *shm = shm_malloc(MESSAGE_SIZE);
    if (shm == NULL) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory
    char message[] = "Hello, world!";
    strcpy(shm, message);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process reads from the shared memory
        char *shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process waits for the child process to finish
        wait(NULL);

        // Print the message received from the child process
        printf("Message received from child: %s\n", shm);
    }

    // Clean up
    shm_free(shm);
    return 0;
}