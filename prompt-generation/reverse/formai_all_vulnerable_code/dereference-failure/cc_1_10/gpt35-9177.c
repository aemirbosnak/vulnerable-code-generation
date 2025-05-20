//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_LINE_LENGTH 1024

int main(void) {
    char line[MAX_LINE_LENGTH];
    char* args[MAX_ARGS];

    pid_t pid;
    int status;

    while (1) {
        printf("$ ");

        // read line from stdin
        if (!fgets(line, MAX_LINE_LENGTH, stdin)) {
            break;
        }

        // remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // tokenize arguments
        char* tok = strtok(line, " ");
        int i = 0;
        while (tok != NULL && i < MAX_ARGS) {
            args[i] = tok;
            tok = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // exit shell when "exit" command is entered
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // fork process and execute command
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // child process
            execvp(args[0], args);
            // execvp only returns if an error occurs, so print error message
            perror("Exec failed");
            exit(1);
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}