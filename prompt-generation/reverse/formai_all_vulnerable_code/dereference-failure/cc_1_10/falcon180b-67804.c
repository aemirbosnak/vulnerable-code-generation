//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define SIZE 10

int main()
{
    int shmid, fd, i;
    char *shmaddr;
    pid_t pid;
    char *args[] = {"child", NULL};

    if ((shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0600)) < 0)
    {
        printf("shmget failed\n");
        return 1;
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        printf("shmat failed\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++)
    {
        *(shmaddr + i) = i;
    }

    if ((pid = fork()) < 0)
    {
        printf("fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        if (execve("child", args, NULL) < 0)
        {
            printf("execve failed\n");
            return 1;
        }
    }
    else
    {
        wait(NULL);
    }

    if (shmdt(shmaddr) < 0)
    {
        printf("shmdt failed\n");
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) < 0)
    {
        printf("shmctl failed\n");
        return 1;
    }

    return 0;
}