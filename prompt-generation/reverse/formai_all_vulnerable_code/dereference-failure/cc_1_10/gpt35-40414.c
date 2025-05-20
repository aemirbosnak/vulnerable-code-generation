//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main()
{
    int i, shmid, pid;
    char *shm, *s;

    // create shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    // attach segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 
    {
        perror("shmat");
        exit(1);
    }

    // fork a child process
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    // child process writes to shared memory
    else if (pid == 0)
    {
        s = shm;
        for (i = 0; i < 26; i++)
            *s++ = 'a' + i;
        *s = '\0';
        exit(0);
    }

    // parent process waits for child to finish
    else
    {
        wait(NULL);

        // read from shared memory
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        // remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) < 0)
        {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}