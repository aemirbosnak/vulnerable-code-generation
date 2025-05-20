//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

// Implementation of the Unix-like shell
int main(int argc, char **argv) {
    char buffer[MAX_BUFFER];
    char *args[MAX_BUFFER/2];
    int should_run = 1;

    while (should_run) {
        printf("Unix-like Shell >> ");
        fflush(stdout);

        // Read the command
        fgets(buffer, MAX_BUFFER, stdin);

        // Parse the arguments
        int i = 0;
        args[i] = strtok(buffer, " \n");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " \n");
        }

        // Check if we need to exit
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            break;
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed.\n");
            return -1;
        } else if (pid == 0) {
            // Child process

            // Execute the command
            execvp(args[0], args);

            // If we get here, the execvp failed
            fprintf(stderr, "Command '%s' not found.\n", args[0]);
            return -1;
        } else {
            // Parent process

            // Wait for the child process to complete
            waitpid(pid, NULL, 0);
        }
    }

    printf("Goodbye!\n");
    return 0;
}