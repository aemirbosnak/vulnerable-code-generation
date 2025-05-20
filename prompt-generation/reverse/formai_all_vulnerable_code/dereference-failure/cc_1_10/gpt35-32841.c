//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *data;
    int pid;
    if ((key = ftok("shmfile", 'R')) == -1)
    {
        perror("ftok");
        exit(1);
    }
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
    {
        perror("shmget");
        exit(1);
    }
    if ((data = shmat(shmid, (void *)0, 0)) == (char *)(-1))
    {
        perror("shmat");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        printf("Error forking.\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child: wrote Hello into shared memory.\n");
        memcpy(data, "Hello", sizeof("Hello"));
    }
    else
    {
        sleep(1);
        printf("Parent: read from shared memory: %s\n", data);
    }
    if (shmdt(data) == -1)
    {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(1);
    }
    return 0;
}