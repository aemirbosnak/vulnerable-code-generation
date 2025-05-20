//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

// Function declarations
void execute_command(char **args);
void parse_command(char *cmd, char **args);
void change_directory(char **args);
int is_builtin_command(char **args);
void handle_pipe(char *command);
void run_shell();

int main() {
    run_shell();
    return 0;
}

// Main shell loop
void run_shell() {
    char command[MAX_CMD_LEN];

    while (1) {
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("fgets failed");
            continue;
        }
        
        // Remove newline character from the command
        command[strcspn(command, "\n")] = 0;

        // Check for exit command
        if (strcmp(command, "exit") == 0) {
            break;
        }

        handle_pipe(command);
    }
}

// Function to handle command piping
void handle_pipe(char *command) {
    char *pipe_pos = strchr(command, '|');
    if (pipe_pos) {
        int pipe_fds[2];
        if (pipe(pipe_fds) == -1) {
            perror("pipe failed");
            return;
        }

        // Split command into two parts
        *pipe_pos = '\0';
        char *cmd1 = command;
        char *cmd2 = pipe_pos + 1;

        // Fork the first command
        if (fork() == 0) {
            // Redirect output to the write end of the pipe
            dup2(pipe_fds[1], STDOUT_FILENO);
            close(pipe_fds[0]);
            execute_command(cmd1);
            exit(0);
        }

        // Fork the second command
        if (fork() == 0) {
            // Redirect input to the read end of the pipe
            dup2(pipe_fds[0], STDIN_FILENO);
            close(pipe_fds[1]);
            execute_command(cmd2);
            exit(0);
        }

        close(pipe_fds[0]);
        close(pipe_fds[1]);

        // Wait for both commands to finish
        wait(NULL);
        wait(NULL);
    } else {
        // No pipe, execute command normally
        char *args[MAX_ARGS];
        parse_command(command, args);
        execute_command(args);
    }
}

// Function to parse command into arguments
void parse_command(char *cmd, char **args) {
    char *token = strtok(cmd, " ");
    int index = 0;
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " ");
    }
    args[index] = NULL; // Null terminate the args array
}

// Function to check if the command is a built-in command
int is_builtin_command(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        change_directory(args);
        return 1;
    }
    return 0;
}

// Change directory function
void change_directory(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }
    if (chdir(args[1]) != 0) {
        perror("cd failed");
    }
}

// Function to execute a command
void execute_command(char **args) {
    if (is_builtin_command(args)) {
        return; // It was a built-in command
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec failed");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork failed");
    } else {
        // Parent process
        wait(NULL);
    }
}