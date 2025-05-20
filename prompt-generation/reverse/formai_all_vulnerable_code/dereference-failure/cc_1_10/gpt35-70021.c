//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // maximum number of characters for a command
#define MAX_ARGS 10 // maximum number of arguments for a command

int main(void) {
    char *args[MAX_ARGS]; // array of arguments
    char command[MAX_LINE]; // buffer for the command string
    int should_run = 1; // flag to control the main loop

    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        fgets(command, MAX_LINE, stdin); // read the command from the user input

        // tokenize the command by spaces
        int i = 0;
        char *token = strtok(command, " ");
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i-1][strlen(args[i-1])-1] = '\0'; // remove the newline character at the end of the command

        if (strcmp(args[0], "exit") == 0) { // handle the exit command
            should_run = 0;
            continue;
        }

        pid_t pid = fork(); // fork a new child process

        if (pid < 0) { // error creating the child process
            printf("Fork failed\n");
            continue;
        } else if (pid == 0) { // child process code
            if (execvp(args[0], args) == -1) { // try to execute the command
                printf("Command not found: %s\n", args[0]);
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        } else { // parent process code
            int status;
            waitpid(pid, &status, 0); // wait for the child process to finish
        }
    }

    return 0;
}