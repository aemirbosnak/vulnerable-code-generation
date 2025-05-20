//Falcon-180B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 10

// Function to execute a command and wait for its completion
void execute_command(char* command) {
    pid_t pid = fork();

    if (pid == 0) {
        system(command);
        exit(0);
    } else if (pid < 0) {
        printf("Error: Failed to fork process\n");
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

// Function to read a line of input from the user
char* read_line() {
    char* line = malloc(MAX_COMMAND_LENGTH);
    printf("> ");
    fgets(line, MAX_COMMAND_LENGTH, stdin);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Main function for the shell
int main() {
    char* line;
    int num_processes = 0;

    while (1) {
        line = read_line();

        // Check if the user wants to exit the shell
        if (strcmp(line, "exit") == 0) {
            break;
        } else if (strcmp(line, "help") == 0) {
            printf("Available commands:\n");
            printf("  exit - Exit the shell\n");
            printf("  help - Display this help message\n");
        } else {
            // Execute the command in a new process
            execute_command(line);
        }

        num_processes++;
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached. Exiting shell.\n");
            break;
        }
    }

    return 0;
}