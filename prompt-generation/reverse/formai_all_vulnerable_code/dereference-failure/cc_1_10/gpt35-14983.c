//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LENGTH 100

void execute_command(char* command, char* args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Unable to fork\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command, args);
        printf("Error: Could not execute command\n");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Error: Command exited with non-zero status\n");
            exit(1);
        }
    }
}

void parse_command(char* command) {
    char* command_copy = strdup(command);

    char* args[MAX_ARGS];
    memset(args, 0, sizeof(args));

    int num_args = 0;

    char* token = strtok(command_copy, " ");
    while (token != NULL) {
        args[num_args++] = token;
        if (num_args >= MAX_ARGS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    execute_command(args[0], args);
    free(command_copy);
}

void print_prompt() {
    char cwd[MAX_LENGTH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s $ ", cwd);
    } else {
        printf("$ ");
    }
}

void run_shell() {
    print_prompt();
    char line[MAX_LENGTH];
    if (fgets(line, MAX_LENGTH, stdin) == NULL) {
        printf("\n");
        exit(0);
    }
    if (strcmp(line, "exit\n") == 0) {
        printf("Exiting shell\n");
        exit(0);
    }
    if (strcmp(line, "cd\n") == 0) {
        chdir("/");
        return run_shell();
    }
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
    parse_command(line);
    run_shell();
}

int main() {
    printf("Welcome to the Recursive Unix-like Shell\n");
    run_shell();
    return 0;
}