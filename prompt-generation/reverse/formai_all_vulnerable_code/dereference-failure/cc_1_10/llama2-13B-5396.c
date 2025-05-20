//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/mman.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

// Structure to store command and its arguments
typedef struct {
    char *cmd;
    char *args[MAX_ARGS];
} command_t;

// Function to execute a command
void execute_command(command_t *cmd) {
    // Open a pipe for the command
    int fd[2];
    pipe(fd);

    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process: close read end of pipe and wait for child process
        close(fd[0]);
        wait(NULL);
    } else {
        // Child process: close write end of pipe and execute command
        close(fd[1]);
        char *cmd_str = cmd->cmd;
        char *args_str[MAX_ARGS];
        for (int i = 0; i < MAX_ARGS; i++) {
            args_str[i] = cmd->args[i];
        }
        execvp(cmd_str, args_str);
        perror("execvp failed");
        exit(1);
    }
}

// Function to get command from user
char *get_command() {
    char *cmd = malloc(MAX_CMD_LENGTH);
    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LENGTH, stdin);
    return cmd;
}

// Function to parse command and its arguments
void parse_command(command_t *cmd, char *cmd_str) {
    char *token;
    int arg_count = 0;

    // Parse command and its arguments
    for (token = strtok(cmd_str, " "); token != NULL; token = strtok(NULL, " ")) {
        if (arg_count < MAX_ARGS) {
            cmd->args[arg_count] = token;
            arg_count++;
        } else {
            printf("Too many arguments\n");
            exit(1);
        }
    }
    cmd->cmd = cmd_str;
}

int main() {
    // Initialize command and its arguments
    command_t cmd;
    char *cmd_str = get_command();
    parse_command(&cmd, cmd_str);

    // Execute the command
    execute_command(&cmd);

    return 0;
}