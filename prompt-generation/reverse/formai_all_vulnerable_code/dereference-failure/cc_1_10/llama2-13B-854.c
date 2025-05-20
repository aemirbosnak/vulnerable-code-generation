//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_PROCESS_COUNT 10

// Structure to store the command and its arguments
typedef struct {
    char *command;
    char *arguments;
} command_t;

// Function to execute a command and wait for its completion
void execute_command(command_t *cmd) {
    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In the child process, execute the command
        if (execv(cmd->command, cmd->arguments) < 0) {
            perror("execv failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // In the parent process, wait for the child to complete
        wait(NULL);
    }
}

int main() {
    // Create an array of command_t structures to store the commands to execute
    command_t commands[MAX_PROCESS_COUNT];

    // Read commands from the user
    int i;
    for (i = 0; i < MAX_PROCESS_COUNT; i++) {
        printf("Enter command %d: ", i + 1);
        fgets(commands[i].command, MAX_CMD_LENGTH, stdin);
        commands[i].arguments = strtok(commands[i].command, " ");

        // Check if the command is empty
        if (commands[i].command[0] == '\0') {
            printf("Error: Command cannot be empty\n");
            continue;
        }
    }

    // Execute the commands
    for (i = 0; i < MAX_PROCESS_COUNT; i++) {
        execute_command(&commands[i]);
    }

    return 0;
}