//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to split the input string into an array of arguments
char **split_args(char *line) {
    char **args = malloc(sizeof(char *) * 10);
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

// Function to execute a single command
int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            return 0;
        } else {
            return -1;
        }
    }
}

// Function to handle the shell loop
void shell_loop() {
    char *line;
    size_t len = 0;
    while (1) {
        printf("$ ");
        getline(&line, &len, stdin);
        if (strcmp(line, "exit\n") == 0) {
            break;
        } else {
            char **args = split_args(line);
            execute_command(args);
            free(args);
        }
    }
}

int main() {
    shell_loop();
    return 0;
}