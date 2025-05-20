//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 256

void executeCommand(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Forking error
        printf("Error forking\n");
    } else {
        // Parent process
        int status = 0;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[BUFF_SIZE];
    char *args[BUFF_SIZE/2+1];
    int shouldExit = 0;

    while (!shouldExit) {
        printf(">>> ");
        fflush(stdout);

        fgets(command, BUFF_SIZE, stdin);

        int length = strlen(command);
        if (command[length-1] == '\n') {
            command[length-1] = '\0';
        }

        char *token = strtok(command, " ");
        int i = 0;

        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            shouldExit = 1;
        } else {
            executeCommand(args);
        }
    }

    printf("Exiting...\n");

    return 0;
}