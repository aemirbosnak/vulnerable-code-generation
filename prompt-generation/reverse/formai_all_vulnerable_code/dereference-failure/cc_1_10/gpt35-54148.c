//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    key_t key = 1234;
    char *shm, message[SHM_SIZE];

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);   //Creating shared memory
    if (shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);    //attaching shared memory
    if (shm == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    printf("Enter some message to be sent to child process: ");
    fgets(message, SHM_SIZE, stdin);
    memcpy(shm, message, SHM_SIZE); //Copying message to shared memory location

    pid = fork();       //Creating child process

    if (pid < 0)        //Error
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)  //Child process
    {
        printf("Child process received message: %s", shm);     //Reading message from shared memory location
        shmdt(shm);     //Detaching shared memory
        shmctl(shmid, IPC_RMID, NULL);  //Deleting shared memory
        exit(0);
    }
    else                //Parent process
    {
        wait(NULL);     //Waiting for child process to finish
        printf("\nChild process finished\n");
        shmdt(shm);     //Detaching shared memory
        shmctl(shmid, IPC_RMID, NULL);  //Deleting shared memory
    }

    return 0;
}