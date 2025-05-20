//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<signal.h>

void handler(int sig) //handles signals from child process
{
    if(sig==SIGUSR1)
        printf("Child process is sending data to the parent process\n");
}

int main()
{
    pid_t pid;
    int fd1[2],fd2[2];
    char buffer1[30],buffer2[30],status[10]="Success";
    struct sigaction mysig;//signal handler object

    if(pipe(fd1)<0 || pipe(fd2)<0)//checking for pipe failure
    {
        perror("Pipe failed!\n");
        exit(1);
    }

    pid=fork();//forking the process

    if(pid<0)
    {
        perror("Fork failed!\n");
        exit(1);
    }

    if(pid>0)//parent process
    {
        printf("I am the parent process with process ID %d, waiting for the child process to send message...\n",getpid());

        close(fd1[0]);//closing read end of pipe1
        close(fd2[1]);//closing write end of pipe2

        mysig.sa_handler=handler;
        sigaction(SIGUSR1,&mysig,NULL);//registering signal handler for SIGUSR1


        printf("Waiting for signal from child process....\n");
        pause();//waiting for SIGUSR1 signal from child process

        read(fd2[0],buffer1,30);//reading data from pipe2
        printf("Message from child process: %s\n",buffer1);

        write(fd1[1],status,strlen(status)+1);//writing status message to pipe1
        close(fd1[1]);//closing write end of pipe1
        close(fd2[0]);//closing read end of pipe2
        printf("Parent process is exiting now....\n");
        exit(0);
    }

    else//child process
    {
        printf("I am the child process with process ID %d, sending message to the parent process...\n",getpid());

        close(fd1[1]);//closing write end of pipe1
        close(fd2[0]);//closing read end of pipe2

        strcpy(buffer2,"Hello parent, this is the child process speaking");//assigning value to buffer2
        printf("Sending message to parent process...\n");
        write(fd2[1],buffer2,strlen(buffer2)+1);//writing data to pipe2

        kill(getppid(),SIGUSR1);//sending signal to parent process
        printf("Signal sent to parent process...\n");

        read(fd1[0],buffer1,30);//reading data from pipe1
        printf("Status from parent process: %s\n",buffer1);

        close(fd1[0]);//closing read end of pipe1
        close(fd2[1]);//closing write end of pipe2
        printf("Child process is exiting now....\n");
        exit(0);
    }  
}