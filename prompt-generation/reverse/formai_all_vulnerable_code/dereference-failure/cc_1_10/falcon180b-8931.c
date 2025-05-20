//Falcon-180B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;
    int status;

    // Check if the correct number of arguments were provided
    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    // Copy the command into our buffer
    strncpy(command, argv[1], MAX_COMMAND_LENGTH);

    // Parse the arguments
    char *token = strtok(argv[2], " ");
    while (token!= NULL && num_arguments < MAX_ARGUMENTS) {
        arguments[num_arguments++] = token;
        token = strtok(NULL, " ");
    }

    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        execvp(command, arguments);
        perror("execvp");
        return 1;
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command was terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Unknown exit status\n");
        }

        return 0;
    }
}