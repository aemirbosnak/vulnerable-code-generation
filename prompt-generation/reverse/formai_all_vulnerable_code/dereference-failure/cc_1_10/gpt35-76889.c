//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void display_prompt() {
    printf("turtle-shell> ");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int status, process_count = 0;

    while (1) {
        display_prompt();
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Removing '\n' from the end of the command string
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        // Splitting the command into arguments
        char *token;
        int arg_count = 0;
        token = strtok(command, " ");
        while (token != NULL) {
            arguments[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        arguments[arg_count] = NULL;

        // Checking if the user wants to exit the shell
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Exiting turtle-shell. Bye!\n");
            exit(0);
        }

        // Creating a new process to execute command
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error unable to fork process");
        } else if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) {
                perror("Error executing command");
            }
            exit(0);
        } else {
            process_count++;
            waitpid(pid, &status, 0);
            printf("child process %d has completed\n", process_count);
        }
    }

    return 0;
}