//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SIZE 10

int shmid;
int shmaddr;
int *shmptr;

int main()
{
    int id,i;
    pid_t pid;
    key_t key;

    key = 12345;

    if((shmid = shmget(key,SIZE*sizeof(int),0666)) < 0)
    {
        printf("Failed to create shared memory segment\n");
        exit(1);
    }

    shmaddr = (int)shmat(shmid,NULL,0);
    shmptr = (int *)shmaddr;

    for(i=0;i<SIZE;i++)
    {
        shmptr[i] = 0;
    }

    for(i=0;i<3;i++)
    {
        if((id = fork()) == 0)
        {
            pid = getpid();
            shmptr[pid] = 1;
            printf("Child process %d created with id %d\n",i+1,pid);
            break;
        }
        else
        {
            wait(NULL);
        }
    }

    sleep(2);

    for(i=0;i<3;i++)
    {
        if((id = fork()) == 0)
        {
            pid = getpid();
            shmptr[pid] = 2;
            printf("Child process %d created with id %d\n",i+4,pid);
            break;
        }
        else
        {
            wait(NULL);
        }
    }

    sleep(2);

    for(i=0;i<6;i++)
    {
        printf("Value of shared memory for process %d is %d\n",i+1,shmptr[i]);
    }

    for(i=0;i<6;i++)
    {
        shmptr[i] = 0;
    }

    printf("Shared memory segment deleted successfully\n");

    return 0;
}