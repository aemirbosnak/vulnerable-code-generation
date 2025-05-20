//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  

int main() {
    // Create a shared memory segment.
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process.
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory segment.
    const char *message = "Hello, world!";
    memcpy(shm_ptr, message, strlen(message) + 1);

    // Detach the shared memory segment from the current process.
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Create a child process.
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // In the child process, read the message from the shared memory segment.
    if (child_pid == 0) {
        // Attach the shared memory segment to the child process.
        void *shm_ptr = shmat(shm_id, NULL, 0);
        if (shm_ptr == (void *)-1) {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        // Read the message from the shared memory segment.
        char message[SHM_SIZE];
        memcpy(message, shm_ptr, strlen(message) + 1);

        // Print the message.
        printf("Message: %s\n", message);

        // Detach the shared memory segment from the child process.
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
    }

    // In the parent process, wait for the child process to finish.
    else {
        int status;
        waitpid(child_pid, &status, 0);

        // Remove the shared memory segment.
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}