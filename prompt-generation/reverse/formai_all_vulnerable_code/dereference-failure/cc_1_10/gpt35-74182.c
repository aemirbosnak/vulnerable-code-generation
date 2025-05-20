//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGS 256

int main() {
    char command[MAX_COMMAND_LENGTH]; // buffer to hold user input
    char *args[MAX_NUM_ARGS]; // buffer to hold argument list
    int should_run = 1; // flag to determine when to exit the shell
    int status;

    while(should_run) {
        printf("> ");

        // read user input
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // remove trailing newline from input string
        command[strcspn(command, "\n")] = '\0';

        // parse input string into argument list
        char *token = strtok(command, " ");
        int i = 0;
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; // add NULL terminator to argument list

        // check for built-in exit command
        if(strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        pid_t pid = fork();

        if(pid == -1) {
            fprintf(stderr, "Error: fork failed\n");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // child process, execute command
            if(execvp(args[0], args) == -1) {
                fprintf(stderr, "Error: command not found\n");
                exit(EXIT_FAILURE);
            }
        } else {
            // parent process, wait for child to finish
            do {
                waitpid(pid, &status, WUNTRACED);
            } while(!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}