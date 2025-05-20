//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;
    int i;

    // Check if the correct number of arguments were provided
    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    // Copy the command into a string
    strcpy(command, argv[1]);

    // Parse the arguments
    for (i = 2; i < argc; i++) {
        arguments[num_arguments] = argv[i];
        num_arguments++;
    }

    // Fork a child process to execute the command
    child_pid = fork();

    // If the fork failed, print an error message and exit
    if (child_pid == -1) {
        printf("Fork failed.\n");
        return 1;
    }

    // If the parent process, wait for the child to finish
    if (child_pid > 0) {
        waitpid(child_pid, &status, 0);
    }

    // If the child process, execute the command
    else {
        // Close the standard input to avoid infinite loops
        close(0);

        // Redirect the standard output and error to the parent's standard output and error
        dup2(1, 0);
        dup2(2, 1);

        // Change the working directory to the parent's working directory
        if (chdir("/") == -1) {
            printf("Chdir failed.\n");
            return 1;
        }

        // Execute the command
        execlp(command, command, NULL);

        // If execlp failed, print an error message and exit
        perror("Execlp");
        return 1;
    }

    return 0;
}