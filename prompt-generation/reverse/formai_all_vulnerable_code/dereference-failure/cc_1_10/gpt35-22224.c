//FormAI DATASET v1.0 Category: Interprocess communication ; Style: immersive
// Welcome to the Interprocess Communication program!
// This program demonstrates how two processes can communicate with each other.

// Let's start with including the necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Next, we define some constants
#define SHM_SIZE 1024 // Size of the shared memory segment
#define KEY 1234 // Key for the shared memory segment

int main() {
    // Once the headers and constants are defined, we can move on to creating two processes
    pid_t pid; // Variable for storing process ID

    pid = fork(); // Create a child process

    if (pid == -1) { // Check if fork failed
        perror("fork"); // Print error message
        exit(1); // Exit with error status
    }

    if (pid == 0) { // Child process
        // In the child process, we will attach the shared memory segment

        int shmid; // Variable for storing shared memory ID
        char *shm_ptr; // Pointer to the shared memory segment

        // Get the shared memory segment
        shmid = shmget(KEY, SHM_SIZE, 0666);
        if (shmid < 0) { // Check if shared memory segment creation failed
            perror("shmget"); // Print error message
            exit(1); // Exit with error status
        }

        // Attach the shared memory segment
        shm_ptr = (char *) shmat(shmid, NULL, 0);
        if (shm_ptr == (char *) -1) { // Check if shared memory segment attachment failed
            perror("shmat"); // Print error message
            exit(1); // Exit with error status
        }

        // In an infinite loop, read data from shared memory segment and print it
        while (1) {
            printf("Child process received: %s\n", shm_ptr);
            sleep(1); // Sleep for 1 second
        }

        // Detach the shared memory segment
        shmdt(shm_ptr);
    } else { // Parent process
        // In the parent process, we will write data to the shared memory segment

        int shmid; // Variable for storing shared memory ID
        char *shm_ptr; // Pointer to the shared memory segment

        // Get the shared memory segment
        shmid = shmget(KEY, SHM_SIZE, IPC_CREAT | 0666);
        if (shmid < 0) { // Check if shared memory segment creation failed
            perror("shmget"); // Print error message
            exit(1); // Exit with error status
        }

        // Attach the shared memory segment
        shm_ptr = (char *) shmat(shmid, NULL, 0);
        if (shm_ptr == (char *) -1) { // Check if shared memory segment attachment failed
            perror("shmat"); // Print error message
            exit(1); // Exit with error status
        }

        // In an infinite loop, write data to the shared memory segment and print it
        while (1) {
            printf("Enter message to send to child process: ");
            fgets(shm_ptr, SHM_SIZE, stdin);
            printf("Parent process sent: %s\n", shm_ptr);
            sleep(1); // Sleep for 1 second
        }

        // Detach the shared memory segment
        shmdt(shm_ptr);

        // Wait for child process to exit
        wait(NULL);
    }

    return 0; // Exit with success status
}