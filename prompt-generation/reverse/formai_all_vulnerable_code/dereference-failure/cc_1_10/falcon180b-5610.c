//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/wait.h>


int main()
{
    int shmid, semid;
    key_t key;
    int i;
    pid_t pid;
    char *shmaddr;
    struct sembuf sembuf;

    key = ftok("shmfile", 65);
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        printf("Failed to get shared memory\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if ((long)shmaddr == -1)
    {
        printf("Failed to attach shared memory\n");
        exit(2);
    }

    for (i = 0; i < 1024; i++)
    {
        *(shmaddr + i) = 0;
    }

    key = ftok("semfile", 65);
    semid = semget(key, 3, IPC_CREAT | 0666);
    if (semid < 0)
    {
        printf("Failed to get semaphore\n");
        exit(3);
    }

    sembuf.sem_num = 0;
    sembuf.sem_op = -1;
    sembuf.sem_flg = SEM_UNDO;
    semop(semid, &sembuf, 1);

    pid = fork();
    if (pid == 0)
    {
        for (i = 0; i < 10; i++)
        {
            sleep(1);
            printf("Child writing: %d\n", i);
            *(shmaddr + i*4) = i;
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        for (i = 0; i < 10; i++)
        {
            sleep(1);
            printf("Parent reading: %d\n", *(shmaddr + i*4));
        }
    }

    sembuf.sem_num = 0;
    sembuf.sem_op = 1;
    sembuf.sem_flg = SEM_UNDO;
    semop(semid, &sembuf, 1);

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}