//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAXLINE 80
#define TOK_DELIM " \t\r\n\a"

int main()
{
    char *args[MAXLINE / 2 + 1]; // array of arguments
    int should_run = 1; // flag for running the loop
    char *cmd; // pointer to user input
    pid_t pid; // process ID

    printf("Welcome to the Unix-like Shell!\n");

    while (should_run) {
        printf(">>> "); // prompt
        fflush(stdout);

        // Read user input
        cmd = calloc(MAXLINE, sizeof(char));
        fgets(cmd, MAXLINE, stdin);

        // Parse arguments
        int i = 0;
        args[i] = strtok(cmd, TOK_DELIM);
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, TOK_DELIM);
        }

        // Check for exit command
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            printf("Goodbye!\n");
            continue;
        }

        // Fork process
        pid = fork();

        if (pid == -1) {
            printf("Error: Fork failed\n");
        } else if (pid == 0) {
            // Child process executes command
            if (execvp(args[0], args) == -1) {
                printf("Error: Command not found\n");
            }
            exit(EXIT_FAILURE);
        } else {
            // Parent process waits for child
            int status;
            waitpid(pid, &status, 0);
        }

        free(cmd);
    }

    return 0;
}