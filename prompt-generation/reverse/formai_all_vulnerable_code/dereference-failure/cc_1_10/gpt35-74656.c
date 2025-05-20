//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGS 50

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_NUM_ARGS];
    int num_args, status;

    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character

        // split command into arguments
        char *token = strtok(command, " ");
        num_args = 0;
        while (token != NULL) {
            args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL; // last argument must be NULL

        // exit if command is "exit"
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // fork a child process to execute the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("Failed to fork");
            exit(1);
        } else if (pid == 0) {
            // child process
            execvp(args[0], args);
            perror("Failed to execute command");
            exit(1);
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}