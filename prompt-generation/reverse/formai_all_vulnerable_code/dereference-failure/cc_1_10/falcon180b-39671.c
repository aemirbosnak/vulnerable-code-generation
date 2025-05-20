//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

#define MAX 10

int main()
{
    int shmid, semid;
    key_t key;
    char *shm;
    int i;
    pid_t pid;

    // Create shared memory segment
    key = ftok("shm_file", 65);
    shmid = shmget(key, sizeof(int)*MAX, IPC_CREAT | IPC_EXCL | 0600);

    // Attach shared memory segment to process
    if((shm = shmat(shmid, NULL, 0)) == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for(i=0; i<MAX; i++)
    {
        *(shm+i) = 0;
    }

    // Create semaphore set
    key = ftok("sem_file", 65);
    semid = semget(key, 2, IPC_CREAT | IPC_EXCL | 0600);

    // Initialize semaphore set
    if(semctl(semid, 0, SETVAL, 1) == -1)
    {
        perror("semctl");
        exit(1);
    }

    // Fork child process
    pid = fork();

    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        // Child process writes to shared memory segment
        sleep(1);
        for(i=0; i<MAX; i++)
        {
            *(shm+i) = i;
        }
        exit(0);
    }
    else
    {
        // Parent process reads from shared memory segment
        sleep(2);
        for(i=0; i<MAX; i++)
        {
            printf("%d ", *(shm+i));
        }
        exit(0);
    }
}