//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024

void execute_command(char *command) {
    char buffer[MAX_CMD_LENGTH];

    // We fork a new process to execute the shell command
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error creating process");
        return;
    }

    if (pid == 0) { // Child process
        // Execute the shell command
        system(command);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);

        // Check if the child process exited successfully
        if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
            snprintf(buffer, MAX_CMD_LENGTH, "Command `%s` executed successfully", command);
            printf("%s\n", buffer);
        } else {
            snprintf(buffer, MAX_CMD_LENGTH, "Failed to execute command `%s`", command);
            perror(buffer);
        }
    }
}

int main(int argc, char *argv[]) {
    // Parse command-line arguments
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Construct the shell command by concatenating all arguments
    char command[MAX_CMD_LENGTH];
    memset(command, 0, sizeof(command));
    for (int i = 1; i < argc; i++) {
        if (i > 1) strncat(command, " ", MAX_CMD_LENGTH - strlen(command) - 1);
        strncat(command, argv[i], MAX_CMD_LENGTH - strlen(command) - 1);
    }

    // Execute the command
    execute_command(command);

    return EXIT_SUCCESS;
}