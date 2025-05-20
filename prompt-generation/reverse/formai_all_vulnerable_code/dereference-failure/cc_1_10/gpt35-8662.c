//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 // Size of shared memory

int main()
{
    int shmid;
    char *shm_ptr;
    key_t key;
    pid_t pid;

    // Generate a key for shared memory
    key = ftok("shmfile", 65);

    // Create shared memory segment using the key
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    // Attach shared memory segment to the process
    shm_ptr = (char *)shmat(shmid, NULL, 0);

    // Fork a child process
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process: write message to shared memory
        char message[] = "Hello Parent Process!";

        // Copy the message to shared memory
        strcpy(shm_ptr, message);

        // Notify the parent process that the message was written
        printf("Child Process: Wrote '%s' to shared memory\n", message);

        // Detach shared memory from the child process and exit
        shmdt(shm_ptr);
        exit(0);
    }
    else
    {
        // Parent process: wait for child to finish writing the message
        wait(NULL);

        // Read the message from shared memory
        char message[SHM_SIZE];
        strcpy(message, shm_ptr);

        // Print the message
        printf("Parent Process: Received message '%s' from child process\n", message);

        // Detach shared memory from the parent process and remove the segment
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}