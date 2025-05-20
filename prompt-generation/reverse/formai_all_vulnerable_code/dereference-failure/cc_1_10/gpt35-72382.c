//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

// Function for parent process
int parent_process(int shmid)
{
    // Attach shared memory
    char *shm_ptr = (char *)shmat(shmid,(void *)0,0);

    // Declare variables
    char message[SHM_SIZE];

    // Ask user for input and send it to child
    printf("Enter a message to send to child process: ");
    fflush(stdout);
    fgets(message,SHM_SIZE,stdin);
    strncpy(shm_ptr,message,SHM_SIZE);

    // Wait for child to signal read
    while(strcmp(shm_ptr,"READY")!=0)
    {
        sleep(1);
    }

    // Print message received from child
    printf("Parent received message: %s\n",shm_ptr);

    // Detach shared memory and exit
    shmdt(shm_ptr);
    exit(0);
}

// Function for child process
int child_process(int shmid)
{
    // Attach shared memory
    char *shm_ptr = (char *)shmat(shmid,(void *)0,0);

    // Declare variables
    char message[SHM_SIZE];

    // Signal parent that we are ready to receive message
    strncpy(shm_ptr,"READY",SHM_SIZE);

    // Wait for message from parent
    while(strlen(shm_ptr) == 0)
    {
        sleep(1);
    }

    // Print message received from parent
    printf("Child received message: %s\n",shm_ptr);

    // Ask user for input and send it to parent
    printf("Enter a message to send to parent process: ");
    fflush(stdout);
    fgets(message,SHM_SIZE,stdin);
    strncpy(shm_ptr,message,SHM_SIZE);

    // Detach shared memory and exit
    shmdt(shm_ptr);
    exit(0);
}

// Main function
int main(int argc, char* argv[])
{
    // Declare variables
    int shmid;
    key_t key;

    // Generate key for shared memory
    if((key = ftok(".", 'a')) == -1)
    {
        perror("ftok");
        exit(1);
    }

    // Create shared memory segment
    if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Fork child process
    pid_t pid = fork();

    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) // Child process
    {
        child_process(shmid);
    }
    else // Parent process
    {
        parent_process(shmid);
    }

    return 0;
}