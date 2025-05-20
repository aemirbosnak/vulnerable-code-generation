//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

void executeCommand(char* command, char** args) {
    // fork a child process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
        printf("Failed to create child process.\n");
        return;
    } else if (pid == 0) {
        // child process
        if (execvp(command, args) == -1) {
            printf("Failed to execute command.\n");
        }
        exit(EXIT_FAILURE);
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char** argv) {
    char line[MAX_LINE_LENGTH];
    char* args[MAX_ARGS];
    int numArgs;

    while (1) {
        // print shell prompt
        printf("myshell> ");

        // read in user input
        fgets(line, MAX_LINE_LENGTH, stdin);
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';  // remove newline character
        }

        // tokenize the user input
        char* token = strtok(line, " ");
        numArgs = 0;
        while (token != NULL) {
            args[numArgs++] = token;
            token = strtok(NULL, " ");
        }
        args[numArgs] = NULL;

        // check for exit command
        if (strcmp(args[0], "exit") == 0) {
            exit(EXIT_SUCCESS);
        }

        // execute the command
        executeCommand(args[0], args);
    }

    return 0;
}