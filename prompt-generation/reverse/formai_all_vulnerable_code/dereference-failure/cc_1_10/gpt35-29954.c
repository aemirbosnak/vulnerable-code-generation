//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

int main()
{
    int pid; // process id
    int shmid; // shared memory id
    char *shmaddr; // pointer to shared memory segment
    char msg[MAX_MSG_LENGTH]; // message buffer

    // generate unique key for shared memory segment
    key_t key = ftok("shmfile", 65);
    if (key == -1)
    {
        perror("Error generating key!");
        exit(EXIT_FAILURE);
    }

    // create shared memory segment
    shmid = shmget(key, MAX_MSG_LENGTH, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("Error creating shared memory segment!");
        exit(EXIT_FAILURE);
    }

    // attach shared memory segment to process address space
    shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1)
    {
        perror("Error attaching shared memory segment!");
        exit(EXIT_FAILURE);
    }

    // get process id
    pid = fork();
    if (pid == -1)
    {
        perror("Error forking new process!");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) // child process writes to shared memory
    {
        printf("Child process is writing to shared memory...\n");

        strcpy(msg, "Hello from child process!");
        strcpy(shmaddr, msg);

        printf("Child process wrote to shared memory: %s\n", shmaddr);

        exit(EXIT_SUCCESS);
    }
    else // parent process reads from shared memory
    {
        printf("Parent process is waiting for child process to write to shared memory...\n");

        wait(NULL); // wait for child process to exit

        printf("Parent process read from shared memory: %s\n", shmaddr);

        // detach and remove shared memory segment
        if (shmdt(shmaddr) == -1)
        {
            perror("Error detaching shared memory segment!");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("Error removing shared memory segment!");
            exit(EXIT_FAILURE);
        }

        printf("Shared memory segment detached and removed successfully!\n");

        exit(EXIT_SUCCESS);
    }

    return 0;
}