//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Max size for command line input
#define MAX_CMD_SIZE 1024
// Max number of arguments
#define MAX_ARGS 100

// Function prototypes
void execute_command(char *cmd);
void parse_command(char *input, char **args);
void run_pipeline(char *input);

int main() {
    char input[MAX_CMD_SIZE];

    while (1) {
        printf("shannon-shell> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; // End on Ctrl+D
        }
        
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // If input is empty, continue
        if (strlen(input) == 0) {
            continue;
        }

        // Handle command pipeline
        run_pipeline(input);
    }

    return 0;
}

void run_pipeline(char *input) {
    char *cmd;
    char *saveptr;

    // strtok to tokenize the input by '|'
    cmd = strtok_r(input, "|", &saveptr);

    int prev_pipefd[2] = {-1, -1}; // Previous pipe file descriptor
    while (cmd != NULL) {
        int pipefd[2];
        if (strchr(cmd, '|') != NULL) {
            // Create pipe for the next command
            if (pipe(pipefd) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            if (prev_pipefd[0] != -1) { // If previous pipe exists
                dup2(prev_pipefd[0], STDIN_FILENO);
                close(prev_pipefd[0]);
            }

            if (strchr(cmd, '|') != NULL) {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            }

            char *args[MAX_ARGS];
            parse_command(cmd, args);

            // Execute the command
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            if (prev_pipefd[0] != -1) {
                close(prev_pipefd[0]);
            }
            if (strchr(cmd, '|') != NULL) {
                close(pipefd[1]);
            }
            prev_pipefd[0] = pipefd[0]; // Save current pipe read end
        }

        cmd = strtok_r(NULL, "|", &saveptr); // Get the next command
    }

    // Wait for all child processes
    while (wait(NULL) > 0);
}

void parse_command(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // Null-terminate the arguments list
}