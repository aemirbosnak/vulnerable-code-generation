//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum characters per line
#define MAX_ARGS 10 // Maximum arguments per command

int main(void) {
    char *args[MAX_ARGS]; // List of arguments
    char buff[MAX_LINE];  // Input buffer
    pid_t pid;            // Process ID
    int status;           // Execution status
    int run = 1;          // Program running status

    while (run) {
        printf(">>");
        fgets(buff, MAX_LINE, stdin);

        // Remove newline character if any
        if (buff[strlen(buff)-1] == '\n')
            buff[strlen(buff)-1] = '\0';

        // Break input into arguments
        char *token = strtok(buff, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS-1) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // If "exit" command is entered, exit program
        if (strcmp(args[0], "exit") == 0) {
            run = 0;
        } else {
            pid = fork();

            if (pid == 0) {
                // Child process
                if (execvp(args[0], args) == -1) {
                    printf("Error: command not found.\n");
                    exit(EXIT_FAILURE);
                }
            } else if (pid < 0) {
                // Fork error
                printf("Error: forking process failed.\n");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}