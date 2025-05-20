//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    pid_t pid;
    int shmem_id;
    char *shmem_addr;
    char buffer[BUFFER_SIZE];

    // Generate a shared memory segment
    shmem_id = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmem_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shmem_addr = shmat(shmem_id, NULL, 0);
    if (shmem_addr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // If this is the child process
    if (pid == 0) {
        printf("Child process started\n");

        // Write a string to the shared memory
        strcpy(shmem_addr, "Hello from child process!");

        // Wait for the parent process to read the string from the shared memory
        while (strlen(shmem_addr) != 0) {
            sleep(1);
        }

        printf("Child process ended\n");
        exit(0);
    }

    // If this is the parent process
    else {
        printf("Parent process started\n");

        // Wait for the child process to write the string to the shared memory
        while (strlen(shmem_addr) == 0) {
            sleep(1);
        }

        // Read the string from the shared memory
        strcpy(buffer, shmem_addr);
        printf("Received message from child process: %s\n", buffer);

        // Clear the shared memory
        strcpy(shmem_addr, "");

        // Wait for the child process to exit
        wait(NULL);

        // Detach and destroy the shared memory segment
        if (shmdt(shmem_addr) < 0) {
            perror("shmdt");
            exit(1);
        }

        if (shmctl(shmem_id, IPC_RMID, NULL) < 0) {
            perror("shmctl");
            exit(1);
        }

        printf("Parent process ended\n");
        exit(0);
    }
}