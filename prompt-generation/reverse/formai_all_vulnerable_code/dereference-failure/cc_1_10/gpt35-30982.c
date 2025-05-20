//FormAI DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    // creating a shared memory segment
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    // error handling for shared memory segment creation
    if (shmid < 0)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attaching to shared memory segment
    char *shared_mem = (char *)shmat(shmid, NULL, 0);

    // error handling for shared memory segment attachment
    if (shared_mem == (char *)-1)
    {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // forking a child process
    pid_t pid = fork();

    // error handling for fork
    if (pid < 0)
    {
        printf("Error forking child process\n");
        exit(1);
    }

    // child process
    if (pid == 0)
    {
        // writing to shared memory
        sprintf(shared_mem, "Hello from child!");

        // exiting child process
        exit(0);
    }

    // parent process
    else
    {
        // waiting for child process to terminate
        wait(NULL);

        // reading from shared memory
        char buffer[1024];
        strcpy(buffer, shared_mem);

        // printing content of shared memory
        printf("Content of shared memory: %s\n", buffer);
    }

    // detaching from shared memory segment
    shmdt(shared_mem);

    // deleting shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}