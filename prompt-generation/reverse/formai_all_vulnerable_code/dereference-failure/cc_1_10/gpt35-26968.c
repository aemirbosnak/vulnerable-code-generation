//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <command>\n", argv[0]);
        return -1;
    }
    
    char full_command[100];
    strcpy(full_command, argv[1]);
    for(int i = 2; i < argc; i++)
    {
        strcat(full_command, " ");
        strcat(full_command, argv[i]);
    }
    
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("Error: could not fork process.\n");
        return -1;
    }
    else if(pid == 0)
    {
        int result = system(full_command);
        if(result == -1)
        {
            printf("Error: failed to execute command.\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        if(WIFEXITED(status))
        {
            printf("Child process completed with exit code %d.\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))
        {
            printf("Child process terminated due to signal %d.\n", WTERMSIG(status));
        }
        else if(WIFSTOPPED(status))
        {
            printf("Child process stopped due to signal %d.\n", WSTOPSIG(status));
        }
        else if(WIFCONTINUED(status))
        {
            printf("Child process continued from stop state.\n");
        }
    }
    
    return 0;
}