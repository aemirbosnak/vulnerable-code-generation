//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
//This program demonstrates Interprocess communication between parent and child processes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int shmid, status;
    char *shm, *s;
    key_t key = 1234; //Unique key for shared memory

    //Create shared memory
    if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    //Attach shared memory to process address space
    if((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    //Fork a child process
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    //Parent process
    if(pid > 0)
    {
        printf("Parent Process: Enter a message for the child process: ");
        fgets(shm, SHM_SIZE, stdin); //Read message from user and write it to shared memory

        wait(&status); //Wait for child process to complete

        printf("Parent Process: Message from child process: %s", shm); //Read message written by child process
    }

    //Child process
    else
    {
        s = shm; //Point to shared memory location

        while(*s == '\0') //Wait for parent process to write message to shared memory
            sleep(1);

        printf("Child Process: Message from parent process: %s", s); //Read message written by parent

        strcat(s, " - Message processed by child process"); //Modify message and write it back to shared memory

        exit(0); //Terminate child process
    }

    //Detach shared memory from process address space
    if(shmdt(shm) == -1)
    {
        perror("shmdt");
        exit(1);
    }

    //Delete shared memory
    if(shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(1);
    }

    return 0;
}