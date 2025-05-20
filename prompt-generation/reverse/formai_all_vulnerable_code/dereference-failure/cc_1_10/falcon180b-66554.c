//Falcon-180B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_VARIABLES 10

int main(int argc, char **argv) {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    char *envp[MAX_ENV_VARIABLES];
    int num_arguments = 0;
    int i;

    // Check if the correct number of arguments were provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument]...\n", argv[0]);
        return 1;
    }

    // Copy the command into the command buffer
    strcpy(command, argv[1]);

    // Parse the arguments
    for (i = 2; i < argc; i++) {
        arguments[num_arguments] = argv[i];
        num_arguments++;

        // Check if we have reached the maximum number of arguments
        if (num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            return 1;
        }
    }

    // Set the environment variables
    envp[0] = "PATH=/bin:/usr/bin";

    // Fork a new process
    pid = fork();

    // Check if an error occurred
    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process

        // Replace the current process image with the new program
        execve(command, arguments, envp);

        // An error occurred
        fprintf(stderr, "Execve failed.\n");
        return 1;
    } else {
        // Parent process

        // Wait for the child process to exit
        waitpid(pid, &status, 0);

        // Check the exit status of the child process
        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child was terminated by signal %d.\n", WTERMSIG(status));
        } else {
            printf("Unknown exit status.\n");
        }

        return 0;
    }
}