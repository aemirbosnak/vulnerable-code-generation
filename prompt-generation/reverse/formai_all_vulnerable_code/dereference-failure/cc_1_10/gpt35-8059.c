//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

void printSignature()
{
    printf("My Shell v1.0\n");
    printf("Author: You\n");
    printf("---------------------------------\n");
}

int runCommand(char* command)
{
    // Tokenize command into individual arguments
    char* arguments[MAX_NUM_ARGUMENTS];
    char* token = strtok(command, " ");
    int numArgs = 0;
    while (token != NULL)
    {
        arguments[numArgs++] = token;
        token = strtok(NULL, " ");
    }
    arguments[numArgs] = NULL;

    if (strcmp(arguments[0], "exit") == 0)
    {
        // Exit the shell
        exit(0);
    }
    else if (strcmp(arguments[0], "cd") == 0)
    {
        // Change directory
        if (numArgs > 1)
        {
            chdir(arguments[1]);
        }
        else
        {
            chdir(getenv("HOME"));
        }
    }
    else
    {
        // Handle external command
        pid_t pid = fork();
        if (pid == 0)
        {
            // Child process
            int res = execvp(arguments[0], arguments);
            if (res == -1)
            {
                printf("Unknown command: %s\n", arguments[0]);
                return -1;
            }
        }
        else if (pid > 0)
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

int main(int argc, char* argv[])
{
    printSignature();

    char command[MAX_COMMAND_LENGTH];
    while (1)
    {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) == 0)
        {
            continue;
        }

        runCommand(command);
    }
    
    return 0;
}