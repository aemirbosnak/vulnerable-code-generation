//FormAI DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>

#define KEY 666

int main()
{
    int shmid, status, num;
    key_t key = KEY;
    char *const_data, *data;
    pid_t pid;

    // create shared memory
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget error");
        exit(1);
    }

    // attach shared memory
    const_data = (char *)shmat(shmid, NULL, 0);
    data = (char *)malloc(sizeof(char) * 1024);
    if (const_data == (char *)-1 || data == NULL)
    {
        perror("shmat error");
        exit(1);
    }

    // initialize shared memory
    strcpy(const_data, "Initial data");

    // fork child process
    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        printf("Child process read data from shared memory:\n");
        printf("%s\n", const_data);

        // modify shared memory
        strcpy(data, "Modified data");
        memcpy(const_data, data, sizeof(char) * 1024);

        printf("Child process write data to shared memory:\n");
        printf("%s\n", const_data);

        exit(0);
    }
    else
    {
        // parent process
        printf("Parent process wait for child process completion\n");

        // wait for child process
        if (waitpid(pid, &status, 0) < 0)
        {
            perror("waitpid error");
            exit(1);
        }

        printf("Parent process read data from shared memory:\n");
        printf("%s\n", const_data);
    }

    // detach shared memory
    if (shmdt(const_data) < 0)
    {
        perror("shmdt error");
        exit(1);
    }

    // remove shared memory
    if (shmctl(shmid, IPC_RMID, 0) < 0)
    {
        perror("shmctl error");
        exit(1);
    }

    return 0;
}