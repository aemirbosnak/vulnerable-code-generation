//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

#define SHMSIZE 1024
#define SERVER_SHM_KEY 5678
#define CLIENT_SHM_KEY 5679

void signalHandler(int signum);
void printMessage(char *message);

int serverShmId, clientShmId;
char *serverShmAddr, *clientShmAddr;

int main()
{
    // Allocate shared memory for server and client
    serverShmId = shmget(SERVER_SHM_KEY, SHMSIZE, IPC_CREAT | 0666);
    clientShmId = shmget(CLIENT_SHM_KEY, SHMSIZE, IPC_CREAT | 0666);

    if (serverShmId == -1 || clientShmId == -1)
    {
        printf("Error: Could not create shared memory.\n");
        exit(1);
    }

    // Attach shared memory to server and client processes
    serverShmAddr = shmat(serverShmId, NULL, 0);
    clientShmAddr = shmat(clientShmId, NULL, 0);

    if (serverShmAddr == (char *) -1 || clientShmAddr == (char *) -1)
    {
        printf("Error: Could not attach shared memory.\n");
        exit(1);
    }

    // Initialize signals and print message
    signal(SIGINT, signalHandler);
    printf("C Interprocess Communication Example Program\n");
    printf("--------------------------------------------\n");
    printf("Enter a message to send to the server.\n");

    // Loop for input and communication
    while (1)
    {
        // Get message input
        printf("> ");
        fgets(clientShmAddr, SHMSIZE, stdin);

        // Send message to server
        strcpy(serverShmAddr, clientShmAddr);

        // Wait for server response
        while (strlen(serverShmAddr) == 0)
        {
            usleep(1000);
        }

        // Print server response
        printf("Server: ");
        printMessage(serverShmAddr);

        // Clear shared memory contents
        memset(clientShmAddr, 0, SHMSIZE);
        memset(serverShmAddr, 0, SHMSIZE);
    }

    return 0;
}

// Signal handler function to detach shared memory and exit
void signalHandler(int signum)
{
    if (signum == SIGINT)
    {
        shmdt(serverShmAddr);
        shmdt(clientShmAddr);

        shmctl(serverShmId, IPC_RMID, NULL);
        shmctl(clientShmId, IPC_RMID, NULL);

        printf("\nExiting...\n");
        exit(0);
    }
}

// Helper function to print message without newline
void printMessage(char *message)
{
    message[strlen(message) - 1] = '\0';
    printf("%s\n", message);
}