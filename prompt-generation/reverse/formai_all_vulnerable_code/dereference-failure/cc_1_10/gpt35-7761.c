//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80  // Maximum length of command
#define MAX_ARGS 10  // Maximum number of command line arguments

int main(void)
{
    char *args[MAX_ARGS];  // Array to store command line arguments
    char *token, *line;
    int should_run = 1;  // Flag to determine when to exit program
    int background = 0;  // Flag to determine if command should run in background
    pid_t pid;  // Process ID for the child process

    while (should_run)
    {
        printf("shell> ");
        fflush(stdout);  // Flush output to make sure it is printed before input

        line = (char*) malloc(MAX_LINE * sizeof(char));  // Allocate memory for input
        fgets(line, MAX_LINE, stdin);  // Get input from user

        // Separate input into arguments using whitespace as delimiter
        int i = 0;
        token = strtok(line, " ");
        while (token != NULL && i < (MAX_ARGS - 1))  // Leave last element for NULL terminator
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // NULL terminator for execvp

        // Check if last argument is '&' to run command in background
        if (i > 0 && strcmp(args[i-1], "&\n") == 0)
        {
            background = 1;
            args[i-1] = NULL;  // Remove '&' from args
        }

        // Fork a child process to execute command
        pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)  // Child process
        {
            if (background)  // Ignore SIGINT for background processes
                signal(SIGINT, SIG_IGN);

            execvp(args[0], args);
            perror("Exec failed");
            exit(1);
        }
        else  // Parent process
        {
            if (!background)
                waitpid(pid, NULL, 0);

            background = 0;
        }

        free(line);  // Free memory allocated for input
    }

    return 0;
}