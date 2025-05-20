//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    while (1) {
        // Print the prompt
        printf(">> ");

        // Get user input
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove newline character from input
        char *newline_ptr = strchr(buffer, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }

        // Split the input into command and arguments
        char *command = strtok(buffer, " ");
        char *args[BUFFER_SIZE];
        int i = 0;
        while (1) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL) {
                break;
            }
            i++;
        }

        // Exit the program if "exit" is entered
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Execute the command
        int pid = fork();
        if (pid == 0) {
            // Child process, execute the command
            int status = execvp(command, args);

            // If error occurred, alert the user and exit
            if (status == -1) {
                printf("Error: command not found\n");
                exit(1);
            }
        } else {
            // Parent process, wait for child process to finish
            waitpid(pid, NULL, 0);
        }

        // Clear the buffer
        memset(buffer, '\0', BUFFER_SIZE);
    }

    return 0;
}