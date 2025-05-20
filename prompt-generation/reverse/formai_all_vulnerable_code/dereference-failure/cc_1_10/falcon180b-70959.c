//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX 100

char **split(char* str,char delimiter)
{
    int count=0;
    char **tokens;
    char *token;
    tokens=(char**)malloc(sizeof(char*));
    token=strtok(str,delimiter);
    while(token!=NULL)
    {
        tokens[count]=token;
        count++;
        token=strtok(NULL,delimiter);
    }
    tokens[count]=NULL;
    return tokens;
}

void execute_command(char **args)
{
    pid_t pid;
    int status;
    if(args[0]==NULL)
    {
        printf("Error: Command not found\n");
        return;
    }
    pid=fork();
    if(pid==0)
    {
        if(execvp(args[0],args)==-1)
        {
            perror("Error");
            exit(1);
        }
    }
    else
    {
        waitpid(pid,&status,0);
    }
}

void handle_signal(int signum)
{
    if(signum==SIGINT)
    {
        printf("\nInterrupted\n");
    }
}

int main()
{
    char input[MAX];
    char **args;
    signal(SIGINT,handle_signal);
    while(1)
    {
        printf(">");
        fgets(input,MAX,stdin);
        args=split(input," ");
        execute_command(args);
    }
    return 0;
}