//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to the current process
    void *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Write a message to the shared memory segment
    strcpy(shmaddr, "Hello, world!");

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    // In the child process, read the message from the shared memory segment
    if (child_pid == 0) {
        printf("Child process: %s\n", shmaddr);
        return EXIT_SUCCESS;
    }

    // In the parent process, wait for the child process to finish
    int status;
    waitpid(child_pid, &status, 0);

    // Detach the shared memory segment from the current process
    shmdt(shmaddr);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}