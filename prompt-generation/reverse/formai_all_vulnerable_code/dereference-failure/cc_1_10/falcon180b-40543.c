//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 0x1234

int main()
{
    int shmid;
    char *shmptr;
    int fd;
    char filename[50];
    pid_t pid;
    int status;
    int i;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1)
    {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++)
    {
        *shmptr++ = 0;
    }

    // Create child process
    if ((pid = fork()) == -1)
    {
        printf("Error creating child process\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        sleep(1);
        sprintf(filename, "child_%d", getpid());
        fd = open(filename, O_CREAT | O_RDWR, 0666);
        if (fd == -1)
        {
            printf("Error opening file in child process\n");
            exit(1);
        }
        write(fd, "Child process writing to file", 33);
        close(fd);
        exit(0);
    }
    else
    {
        // Parent process
        waitpid(pid, &status, WUNTRACED);
        sprintf(filename, "parent_%d", getpid());
        fd = open(filename, O_CREAT | O_RDWR, 0666);
        if (fd == -1)
        {
            printf("Error opening file in parent process\n");
            exit(1);
        }
        write(fd, "Parent process writing to file", 33);
        close(fd);
        exit(0);
    }

    return 0;
}