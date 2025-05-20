//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main()
{
    int shmid;
    void *shmaddr;
    int *shmptr;
    pid_t childpid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process's data space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1)
    {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory pointer
    shmptr = shmaddr;

    // Fork a child process
    childpid = fork();

    if (childpid == -1)
    {
        printf("Error forking child process\n");
        exit(1);
    }
    else if (childpid == 0) // Child process
    {
        // Increment shared memory pointer
        *shmptr += 1;

        // Detach shared memory segment from process's data space
        if (shmdt(shmaddr) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    }
    else // Parent process
    {
        // Wait for child process to complete
        wait(NULL);

        // Print final value of shared memory pointer
        printf("Final value of shared memory pointer: %d\n", *shmptr);

        // Detach shared memory segment from process's data space
        if (shmdt(shmaddr) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}