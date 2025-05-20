//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<signal.h>

// Structure for shared memory
struct shared_memory
{
    int status_1; // Status of process 1, 1 indicates it is running
    int status_2; // Status of process 2, 1 indicates it is running
    char message[100]; // Shared message
};

// Function to handle signals
void sigHandler(int sig)
{
    printf("IPCM: Signal Caught %d\n", sig);
    exit(0);
}

int main()
{
    int shmid;
    int pid1, pid2;
    struct shared_memory *sharedMem;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(struct shared_memory), 0666|IPC_CREAT);
    if(shmid<0)
    {
        printf("IPCM: Error in creating shared memory\n");
        exit(1);
    }

    // Attach shared memory
    sharedMem = (struct shared_memory*) shmat(shmid, NULL, 0);

    // Initialize status of processes to 0
    sharedMem->status_1 = 0;
    sharedMem->status_2 = 0;

    // Fork process 1
    pid1 = fork();
    if(pid1<0)
    {
        printf("IPCM: Error in forking process 1\n");
        exit(1);
    }
    if(pid1==0)
    {
        // Child process 1
        sharedMem->status_1 = 1;

        // Wait until process 2 starts
        while(sharedMem->status_2==0);

        // Send message to process 2
        strcpy(sharedMem->message, "Hello from process 1");
        printf("IPCM: Process 1 sends message: %s\n", sharedMem->message);

        // Set status to not running
        sharedMem->status_1 = 0;

        exit(0);
    }

    // Fork process 2
    pid2 = fork();
    if(pid2<0)
    {
        printf("IPCM: Error in forking process 2\n");
        exit(1);
    }
    if(pid2==0)
    {
        // Child process 2
        sharedMem->status_2 = 1;

        // Receive message from process 1
        while(sharedMem->status_1==0);
        printf("IPCM: Process 2 receives message: %s\n", sharedMem->message);

        // Set status to not running
        sharedMem->status_2 = 0;

        exit(0);
    }

    // Wait for processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Detach shared memory
    shmdt(sharedMem);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}