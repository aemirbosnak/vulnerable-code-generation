//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int fd;
    char *shm;
    pid_t child_pid;

    // Create shared memory segment
    fd = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (fd == -1) {
        printf("Error: shmget() failed.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = (char *) shmat(fd, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error: shmat() failed.\n");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shm, 0, SHM_SIZE);

    // Fork child process
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error: fork() failed.\n");
        exit(1);
    } else if (child_pid == 0) {
        // Child process

        // Write to shared memory segment
        sprintf(shm, "Hello, World!");

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process to exit
        wait(NULL);

        // Read from shared memory segment
        printf("Shared memory segment contains: %s\n", shm);

        // Detach shared memory segment from process
        if (shmdt(shm) == -1) {
            printf("Error: shmdt() failed.\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(fd, IPC_RMID, NULL) == -1) {
            printf("Error: shmctl() failed.\n");
            exit(1);
        }
    }

    return 0;
}