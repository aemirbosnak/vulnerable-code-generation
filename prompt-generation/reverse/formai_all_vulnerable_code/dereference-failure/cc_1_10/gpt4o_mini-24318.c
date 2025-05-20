//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 100

void execute_command(char **args);
void change_directory(char *path);
void parse_and_execute(char *input);
int is_builtin_command(char *cmd);
void handle_redirection(char **args, int *in_fd, int *out_fd);

int main() {
    char input[MAX_CMD_SIZE];

    while (1) {
        // Display shell prompt
        printf("mysh> ");
        fflush(stdout);

        // Read input
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        // Remove newline character from end if present
        input[strcspn(input, "\n")] = 0;

        // Execute the command
        parse_and_execute(input);
    }

    return 0;
}

void parse_and_execute(char *input) {
    char *args[MAX_ARG_SIZE];
    char *token;
    int count = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[count++] = token;
        token = strtok(NULL, " ");
    }
    args[count] = NULL;

    // Handle built-in commands
    if (is_builtin_command(args[0])) {
        return;
    }
    
    execute_command(args);
}

int is_builtin_command(char *cmd) {
    if (strcmp(cmd, "exit") == 0) {
        exit(0);
    } else if (strcmp(cmd, "cd") == 0) {
        change_directory(cmd[1] ? cmd + 3 : NULL); // Change to the directory after "cd "
        return 1;
    }
    return 0;
}

void change_directory(char *path) {
    if (path == NULL || chdir(path) != 0) {
        perror("mysh");
    }
}

void execute_command(char **args) {
    pid_t pid = fork();
    int status;

    if (pid == 0) { // Child process
        // Handle redirection if present
        int in_fd = 0, out_fd = 1;

        for (int i = 0; args[i] != NULL; i++) {
            if (strcmp(args[i], ">") == 0) {
                out_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                args[i] = NULL; // Split args for exec
                break;
            } else if (strcmp(args[i], "<") == 0) {
                in_fd = open(args[i + 1], O_RDONLY);
                args[i] = NULL; // Split args for exec
                break;
            }
        }

        // Redirect input and output
        if (in_fd != 0) {
            dup2(in_fd, 0);
            close(in_fd);
        }
        if (out_fd != 1) {
            dup2(out_fd, 1);
            close(out_fd);
        }

        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(0);
    } else if (pid < 0) { // Fork failed
        perror("mysh");
    } else { // Parent process
        do {
            wait(&status); // Wait for the child process to complete
        } while (!WIFEXITED(status));
    }
}