//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

int main(void) {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    char *token;
    int status;
    pid_t pid;

    while (1) {
        // print the prompt
        printf(">> ");
        // read input from user
        fgets(input, MAX_INPUT_SIZE, stdin);
        // remove the trailing newline character
        input[strlen(input)-1] = '\0';

        // tokenize the input
        token = strtok(input, " ");
        args[0] = token;
        int i = 1;
        while (token != NULL && i < MAX_ARGS) {
            args[i] = token = strtok(NULL, " ");
            i++;
        }
        // set the last argument to NULL
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            // exit the shell
            break;
        }
        else {
            pid = fork();

            if (pid < 0) {
                // fork failed
                printf("Fork error.\n");
                exit(1);
            }
            else if (pid == 0) {
                // child process
                execvp(args[0], args);
                // if execvp returns, it must have failed
                printf("Command not found.\n");
                exit(1);
            }
            else {
                // parent process
                wait(&status);
            }
        }
    }
    return 0;
}