//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH  1024

void execute_command(char *command) {
    char *parsed_tokens[20];
    int num_tokens = 0;

    // Parse the command into individual tokens
    char *token = strtok(command, " ");
    while(token != NULL) {
        parsed_tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Handle exit command
    if(strcmp(parsed_tokens[0], "exit") == 0) {
        exit(0);
    }

    // Spawn a new child process to execute the command
    pid_t pid = fork();
    if(pid == 0) {
        // This is the child process
        execvp(parsed_tokens[0], parsed_tokens);
        perror("execvp failed");
        exit(1);
    } else if(pid > 0) {
        // This is the parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Error
        perror("fork failed");
    }
}

int main() {
    char command[MAX_CMD_LENGTH];

    printf("Welcome to my shell! Enter 'exit' to quit.\n");

    while(1) {
        printf("> ");
        fgets(command, MAX_CMD_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        execute_command(command);
    }

    return 0;
}