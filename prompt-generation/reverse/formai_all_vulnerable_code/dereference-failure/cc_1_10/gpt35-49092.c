//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define KEY 1234

int main() {
    // Create shared memory segment
    int shmid = shmget(KEY, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    char *buffer = (char *) shmat(shmid, NULL, 0);
    if (buffer == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process - write to shared memory
        strcpy(buffer, "Hello, this is the child process");
        printf("Child process wrote data: %s\n", buffer);
    } else {
        // Parent process - read from shared memory
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }

        // Verify the data written by child process
        if (strcmp(buffer, "Hello, this is the child process") == 0) {
            printf("Data read from shared memory: %s\n", buffer);
        } else {
            printf("Warning: Data mismatch - Possible Man-in-the-Middle Attack\n");
        }

        // Detach and remove shared memory segment
        if (shmdt(buffer) == -1) {
            perror("shmdt");
            exit(1);
        }
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }
    
    return 0;
}