//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd[2];
    pid_t pid;

    char writeBuff[50] = "Hello! This is a message from the parent process to the child process."; // message to send

    char readBuff[50];  // buffer to receive message

    if(pipe(fd) == -1)  // creating pipe
    {
        printf("Error creating pipe\n");
        exit(1);
    }

    pid = fork();  // creating child process

    if(pid == -1)  // error forking new process
    {
        printf("Error forking new process\n");
        exit(1);
    }

    if(pid == 0)  // child process
    {
        close(fd[1]);  // child process only needs to read, so closing write end of pipe here

        read(fd[0], readBuff, sizeof(readBuff));  // read from pipe

        printf("Child process: Message received - %s\n", readBuff);

        close(fd[0]);  // close read end of pipe
    }

    else  // parent process
    {
        close(fd[0]);  // parent process only needs to write, so closing read end of pipe here

        write(fd[1], writeBuff, strlen(writeBuff)+1);  // write message to pipe

        printf("Parent process: Message sent - %s\n", writeBuff);

        close(fd[1]);  // close write end of pipe
    }

    return 0;
}