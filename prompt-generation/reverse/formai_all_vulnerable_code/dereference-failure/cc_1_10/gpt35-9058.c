//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define MAXSIZE 100

void child_process(char *buffer)
{
    printf("Child Process: Message received: %s\n",buffer);
    strcat(buffer," - Modified by Child");
    printf("Child Process: Message sent: %s\n",buffer);
}

void parent_process(char *buffer, int shmid)
{
    printf("Parent Process: Enter message: ");
    fgets(buffer,MAXSIZE,stdin);

    // attach the shared memory
    char *shared_mem = (char*) shmat(shmid,(void*)0,0);
    strcpy(shared_mem,buffer);
    printf("Parent Process: Message sent: %s\n", shared_mem);

    // wait for the child to finish
    wait(NULL);

    printf("Parent Process: Message received: %s\n", shared_mem);

    // detach the shared memory
    shmdt(shared_mem);

    // delete the shared memory
    shmctl(shmid,IPC_RMID,NULL);
}

int main()
{
    key_t key = ftok("shmfile",65);

    int shmid = shmget(key,MAXSIZE,0666|IPC_CREAT);

    if(shmid<0)
    {
        printf("Error in creating shared memory!\n");
        return -1;
    }

    char *buffer = (char*) shmat(shmid,(void*)0,0);

    pid_t pid = fork();

    if(pid<0)
    {
        printf("Error in creating child process!\n");
        return -1;
    }

    if(pid==0)
    {
        // Child process
        child_process(buffer);
    }

    else
    {
        // Parent process
        parent_process(buffer, shmid);
    }
    return 0;
}