//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int shmid;
    key_t key = IPC_PRIVATE;
    char *shared_memory;
    char message[100];
    pid_t pid;

    //creating shared memory
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget error");
        exit(1);
    }

    //attaching shared memory
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (char *)-1)
    {
        perror("shmat error");
        exit(1);
    }

    //forking child process
    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) //child process
    {
        printf("Child process started...\n");
        strcpy(shared_memory, "Hello Parent!");
        printf("Message sent to Parent process.\n");
        exit(0);
    }
    else //parent process
    {
        waitpid(pid, NULL, 0);
        printf("Parent process started...\n");
        printf("Message received from Child process: %s\n", shared_memory);
        printf("Enter response to Child process: ");
        fgets(message, 100, stdin);
        strcpy(shared_memory, message);
        printf("Response sent to Child process.\n");
        //detaching shared memory
        shmdt(shared_memory);
        //deallocating shared memory
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}