//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS 80

int main(void) {
    char *args[MAX_ARGS / 2 + 1];
    char command[MAX_LINE];
    int shouldRun = 1;
    pid_t pid;
    int status;

    while (shouldRun) {
        printf("osh>");
        fflush(stdout);

        fgets(command, MAX_LINE, stdin);

        int numArgs = 0;
        args[numArgs] = strtok(command, " \n");
        while (args[numArgs] != NULL && numArgs < MAX_ARGS / 2) {
            numArgs++;
            args[numArgs] = strtok(NULL, " \n");
        }
        args[numArgs] = NULL;

        // check if the user wants to exit
        if (strcmp(args[0], "exit") == 0) {
            shouldRun = 0;
            continue;
        }

        // fork a child process to execute the command
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            continue;
        } else if (pid == 0) {
            // child process
            if (execvp(args[0], args) == -1) {
                printf("%s: command not found\n", args[0]);
            }
            exit(EXIT_FAILURE);
        } else {
            do {
                // wait for the child process to finish
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return EXIT_SUCCESS;
}