//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Create shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory segment to process
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // Write data to shared memory segment
    char *message = "Hello from process 1!";
    memcpy(shm_ptr, message, strlen(message) + 1);

    // Notify other process that data is ready
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(pipefd[1]);  // Close write end of pipe

        // Wait for notification from parent process
        char buf[1];
        read(pipefd[0], buf, 1);

        // Read data from shared memory segment
        char *message = shm_ptr;
        printf("Message from process 1: %s\n", message);

        // Detach shared memory segment from process
        shmdt(shm_ptr);

        // Close pipe
        close(pipefd[0]);
    } else {
        // Parent process
        close(pipefd[0]);  // Close read end of pipe

        // Notify child process that data is ready
        write(pipefd[1], "a", 1);

        // Wait for child process to finish
        wait(NULL);

        // Detach shared memory segment from process
        shmdt(shm_ptr);

        // Close pipe
        close(pipefd[1]);

        // Delete shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}