//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

void executeCommand(char* args[MAX_NUM_ARGUMENTS], int indexOfFirstArgument);

void recursiveShell()
{
    char* input = NULL;
    char* args[MAX_NUM_ARGUMENTS];

    input = (char*) malloc(MAX_COMMAND_LENGTH * sizeof(char));

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    int indexOfFirstArgument = 0;
    args[indexOfFirstArgument] = strtok(input, " \n");

    while (args[indexOfFirstArgument] != NULL && indexOfFirstArgument < MAX_NUM_ARGUMENTS - 1)
    {
        indexOfFirstArgument++;
        args[indexOfFirstArgument] = strtok(NULL, " \n");
    }

    if (args[0] == NULL)
    {
        recursiveShell();
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting Recursive Shell...\n");
        free(input);
        exit(0);
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            printf("Error: Invalid command: %s\n\n", args[0]);
        }
        else
        {
            if (chdir(args[1]) != 0)
            {
                printf("Error: Cannot find the directory: %s\n\n", args[1]);
            }
        }
    }
    else
    {
        executeCommand(args, indexOfFirstArgument);
    }

    free(input);
    recursiveShell();
}

void executeCommand(char* args[MAX_NUM_ARGUMENTS], int indexOfFirstArgument)
{
    int pid, status;
    pid = fork();

    if (pid < 0)
    {
        printf("Error: Fork failed\n");
        return;
    }

    if (pid == 0)
    {
        if (execvp(args[0], &args[indexOfFirstArgument]) < 0)
        {
            printf("Error: exevp failed\n");
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

int main()
{
    recursiveShell();
    return 0;
}