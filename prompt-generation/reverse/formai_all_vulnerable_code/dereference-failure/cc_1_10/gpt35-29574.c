//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 100 // maximum length of a command
#define MAX_ARGS 10 // maximum number of arguments in a command

void execute_command(char **args);

int main()
{
    char input[MAX_LENGTH + 1]; // +1 for null character
    char *args[MAX_ARGS + 1]; // +1 for null pointer
    int status; // to hold status of child process
    int i, j; // counters for loops

    while(1)
    {
        // prompt user for command
        printf("myshell> ");
        fflush(stdout); // flush output buffer before input

        // read user command
        fgets(input, MAX_LENGTH, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // parse input into arguments
        args[0] = strtok(input, " ");
        for(i = 1; i < MAX_ARGS; i++)
        {
            args[i] = strtok(NULL, " ");
            if(args[i] == NULL)
            {
                break; // end of arguments
            }
        }
        args[i] = NULL; // mark end of arguments

        // check for built-in commands
        if(strcmp(args[0], "exit") == 0)
        {
            exit(0);
        }
        else if(strcmp(args[0], "cd") == 0)
        {
            if(args[1] == NULL)
            {
                chdir(getenv("HOME")); // go to home directory
            }
            else
            {
                chdir(args[1]); // go to specified directory
            }
            continue; // prompt user for next command
        }

        // execute command in a child process
        if(fork() == 0)
        {
            execute_command(args);
        }
        else
        {
            wait(&status); // wait for child process to finish
        }
    }

    return 0;
}

void execute_command(char **args)
{
    // search for command in PATH environment variable
    char *path = getenv("PATH");
    char full_path[MAX_LENGTH];
    char *dir;
    int found = 0; // 0 = not found, 1 = found

    // loop through each directory in PATH
    while((dir = strtok(path, ":")) != NULL)
    {
        path = NULL; // set to NULL to continue looping

        // combine directory and command to form full path
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, args[0]);

        // check if file exists and is executable
        if(access(full_path, X_OK) == 0)
        {
            found = 1;
            break;
        }
    }

    // execute command if found
    if(found == 1)
    {
        execv(full_path, args);
    }
    else
    {
        printf("%s: command not found\n", args[0]);
        exit(1);
    }
}