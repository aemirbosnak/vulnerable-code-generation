//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGS_SIZE 64
#define MAX_ARG_LENGTH 256

void execute_command(char* command, char** args)
{
    pid_t pid = fork();
    int status;

    if (pid == 0)
    {
        // Execute command in child process
        if (execvp(command, args) < 0)
        {
            printf("Error: Failed to execute command.\n");
            exit(1);
        }
    }
    else if (pid > 0)
    {
        // Wait for child process to finish
        waitpid(pid, &status, 0);
    }
    else
    {
        printf("Error: Failed to create child process.\n");
        exit(1);
    }
}

int main()
{
    char command[MAX_COMMAND_SIZE];
    char* args[MAX_ARGS_SIZE];
    char* arg;
    int num_args;
    int finished = 0;

    while (!finished)
    {
        // Print shell prompt
        printf("> ");

        // Read input command
        if (fgets(command, MAX_COMMAND_SIZE, stdin) == NULL)
        {
            printf("Error: Failed to read command.\n");
            continue;
        }

        // Remove new line character from command
        command[strcspn(command, "\n")] = '\0';

        // Split command into arguments
        num_args = 0;
        arg = strtok(command, " ");
        while (arg != NULL && num_args < MAX_ARGS_SIZE-1)
        {
            args[num_args] = arg;
            num_args++;
            arg = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // Check for built-in commands
        if (strcmp(args[0], "cd") == 0)
        {
            // Change directory
            if (num_args != 2)
            {
                printf("Error: Invalid arguments for cd command.\n");
            }
            else if (chdir(args[1]) < 0)
            {
                printf("Error: Failed to change directory.\n");
            }
        }
        else if (strcmp(args[0], "exit") == 0)
        {
            // Exit shell
            finished = 1;
        }
        else
        {
            // Execute external command
            execute_command(args[0], args);
        }
    }

    return 0;
}