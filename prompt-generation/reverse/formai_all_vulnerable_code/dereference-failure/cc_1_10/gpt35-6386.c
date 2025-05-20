//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 500
#define MAX_ARGUMENTS 20

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while(1) {
        printf("myShell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // remove newline character if present
        int len = strlen(command);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        // split command into arguments
        char *token = strtok(command, " ");
        int count = 0;
        while (token != NULL) {
            arguments[count] = token;
            count++;
            token = strtok(NULL, " ");
        }
        arguments[count] = NULL; // set last argument to NULL

        // check for built-in commands
        if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        }

        // fork process and execute command
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error: Unable to fork process\n");
        } else if (pid == 0) {
            // child process
            if (execvp(arguments[0], arguments) == -1) {
                printf("Error: Unable to execute command\n");
            }
            exit(0);
        } else {
            // parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}