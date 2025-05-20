//FormAI DATASET v1.0 Category: Interprocess communication ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *shared_memory;
    char message[100];

    // Create shared memory
    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        printf("Failed to create shared memory!\n");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (char *)-1)
    {
        printf("Failed to attach shared memory!\n");
        exit(EXIT_FAILURE);
    }

    // Create child process
    pid_t pid = fork();

    if (pid == -1)
    {
        printf("Failed to create child process!\n");
        exit(EXIT_FAILURE);
    }

    else if (pid == 0) // Child process
    {
        printf("Enter a message to send to the parent process: ");
        fgets(message, sizeof(message), stdin);

        // Copy message to shared memory
        strcpy(shared_memory, message);

        exit(EXIT_SUCCESS);
    }

    else // Parent process
    {
        // Wait for child process to finish
        wait(NULL);
        printf("Parent process received message: %s", shared_memory);

        // Detach and remove shared memory
        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, 0);
    }

    return 0;
}