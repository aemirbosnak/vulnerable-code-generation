//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
/* Interprocess communication using shared memory in C */

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

// Define key for shared memory
#define SHM_KEY 0x1234

int main()
{
    // create shared memory segment
    int shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("Shared memory creation failed");
        return 1;
    }

    // attach shared memory segment to the process's address space
    int *shared_data = (int *) shmat(shmid, NULL, 0);

    if (shared_data == (int *) -1)
    {
        perror("Shared memory attach failed");
        return 1;
    }

    // initialize shared data value
    *shared_data = 0;

    // create child process
    int pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        // child process
        printf("Child process:\n");
        *shared_data = 7;
        printf("Shared data value in child process = %d\n", *shared_data);
        return 0;
    }
    else
    {
        // parent process
        printf("Parent process:\n");
        printf("Shared data value in parent process = %d\n", *shared_data);

        // wait for child process to finish
        wait(NULL);

        printf("Shared data value after child process = %d\n", *shared_data);
    }

    // detach shared memory segment from the process's address space
    if (shmdt(shared_data) == -1)
    {
        perror("Shared memory detach failed");
        return 1;
    }

    // mark shared memory segment for deletion
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("Shared memory deletion failed");
        return 1;
    }

    return 0;
}