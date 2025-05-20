//FormAI DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_LINE 256

int main()
{
    char *cmdLine;
    char *args[MAX_ARGS];
    char *token;

    pid_t childPID;

    while (1) {
        cmdLine = (char *) malloc(sizeof(char) * MAX_LINE);
        printf(">> ");
        // Read input from user
        fgets(cmdLine, MAX_LINE, stdin);
        // Remove newline character
        cmdLine[strlen(cmdLine) - 1] = '\0';
        // Split input into arguments
        token = strtok(cmdLine, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; // Set last argument as NULL

        // Check if user wants to quit
        if (strcmp(args[0], "quit") == 0) {
            exit(0);
        }

        // Fork child process
        childPID = fork();

        if (childPID < 0) {
            printf("Error: Could not create child process\n");
        } else if (childPID == 0) {
            // Child process
            execvp(args[0], args);
            printf("Error: Could not execute command\n");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
        free(cmdLine);
    }

    return 0;
}