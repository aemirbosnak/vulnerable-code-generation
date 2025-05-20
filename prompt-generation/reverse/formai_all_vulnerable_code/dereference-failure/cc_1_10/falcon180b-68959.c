//Falcon-180B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    int i, j, num_commands = 0, background_processes = 0;
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command;
    pid_t pid;

    // Initialize the signal handler for SIGINT
    signal(SIGINT, SIG_IGN);

    // Loop until the user enters "exit"
    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character from the input buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Check if the user entered "exit"
        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        // Split the input buffer into individual commands
        command = strtok(input_buffer, " ");
        while (command!= NULL) {
            num_commands++;

            // Check if the command should be run in the background
            if (strcmp(command, "&") == 0) {
                background_processes++;
            }

            // Fork a child process to execute the command
            pid = fork();

            if (pid == 0) {
                // Child process
                if (execvp(command, argv) == -1) {
                    fprintf(stderr, "Error: %s\n", strerror(errno));
                    exit(1);
                }
            } else if (pid < 0) {
                // Error forking process
                fprintf(stderr, "Error: %s\n", strerror(errno));
            } else {
                // Parent process
                if (background_processes == 0) {
                    // Wait for the child process to finish
                    waitpid(pid, NULL, 0);
                }
            }

            command = strtok(NULL, " ");
        }
    }

    return 0;
}