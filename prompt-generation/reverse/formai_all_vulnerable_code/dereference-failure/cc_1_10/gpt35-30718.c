//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_NUM_ARGUMENTS 10

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_NUM_ARGUMENTS];
    int num_arguments;

    while (1)
    {
        printf("unix-like shell>");

        fgets(command, MAX_COMMAND_LENGTH, stdin); // read command from stdin

        // remove newline character from the end of the command
        int len = strlen(command);
        if (len > 0 && command[len - 1] == '\n')
            command[len - 1] = '\0';

        // tokenize the command into arguments
        char *token = strtok(command, " ");
        num_arguments = 0;
        while (token != NULL && num_arguments < MAX_NUM_ARGUMENTS)
        {
            arguments[num_arguments] = token;
            token = strtok(NULL, " ");
            num_arguments++;
        }
        arguments[num_arguments] = NULL;

        // if the command is exit, terminate the program
        if (strcmp(arguments[0], "exit") == 0)
            return 0;

        pid_t pid = fork(); // create a child process
        if (pid == 0)
        {
            // child process
            // execute the command
            execvp(arguments[0], arguments);

            // if the command failed to execute, return an error message
            printf("command not found: %s\n", arguments[0]);
            exit(1);
        }
        else if (pid > 0)
        {
            // parent process
            // wait for the child process to terminate
            wait(NULL);
        }
        else
        {
            // fork failed
            printf("fork failed\n");
            exit(1);
        }
    }

    return 0;
}