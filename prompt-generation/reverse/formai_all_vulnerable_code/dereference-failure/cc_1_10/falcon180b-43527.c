//Falcon-180B DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096

// Function prototypes
void execute_command(char *command, int async);
void handle_child_process(int status);

// Main function
int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char command_buffer[MAX_COMMAND_LENGTH];
    int async = 0;

    printf("Enter commands to execute. Type 'async' to run commands asynchronously.\n");

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "async") == 0) {
            async = 1;
        } else {
            strcpy(command_buffer, input_buffer);
            execute_command(command_buffer, async);
        }
    }

    return 0;
}

// Function to execute a command
void execute_command(char *command, int async) {
    pid_t child_pid;
    int status;

    if (async) {
        child_pid = fork();

        if (child_pid == 0) {
            // Child process
            if (execlp(command, command, NULL) == -1) {
                fprintf(stderr, "Error executing command: %s\n", strerror(errno));
                exit(1);
            }
        } else if (child_pid < 0) {
            fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        } else {
            // Parent process
            do {
                waitpid(child_pid, &status, WNOHANG);
            } while (status == 0);
        }
    } else {
        // Synchronous execution
        if (system(command) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    }
}

// Function to handle child process termination
void handle_child_process(int status) {
    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);

        if (exit_status!= 0) {
            fprintf(stderr, "Command exited with non-zero status: %d\n", exit_status);
        }
    } else if (WIFSIGNALED(status)) {
        fprintf(stderr, "Command terminated by signal: %d\n", WTERMSIG(status));
    } else {
        fprintf(stderr, "Command terminated abnormally\n");
    }
}