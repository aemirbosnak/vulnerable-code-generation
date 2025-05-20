//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char command[100];
    char **args;
    char *token;
    int numArgs;
    pid_t pid;
    int status;

    while(1)
    {
        printf("retro:$ ");

        fgets(command, 100, stdin);
        // Remove the newline character from the input
        strtok(command, "\n");

        // Parse the command into arguments
        numArgs = 0;
        token = strtok(command, " ");
        args = malloc(sizeof(char*) * 10);
        while(token != NULL)
        {
            args[numArgs] = token;
            numArgs++;
            token = strtok(NULL, " ");
        }
        args[numArgs] = NULL;

        // Exit the shell if the user types "exit"
        if(strcmp(args[0], "exit") == 0)
        {
            exit(0);
        }

        // Handle the "cd" command
        else if(strcmp(args[0], "cd") == 0)
        {
            if(chdir(args[1]) != 0)
            {
                printf("retro: Could not change directory\n");
            }
        }

        // Fork a child process to execute the command
        else
        {
            pid = fork();
            if(pid == 0)
            {
                execvp(args[0], args);
                printf("retro: Unknown command\n");
                exit(1);
            }
            else if(pid < 0)
            {
                printf("retro: Error forking child process\n");
            }
            else
            {
                waitpid(pid, &status, 0);
            }
        }

        free(args);
    }

    return 0;
}