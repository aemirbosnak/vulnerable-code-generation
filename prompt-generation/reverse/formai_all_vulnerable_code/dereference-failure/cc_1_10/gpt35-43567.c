//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1000
#define MAX_ARGS 100

char *get_input() {
    char *input = malloc(MAX_CMD_LENGTH);
    if (!fgets(input, MAX_CMD_LENGTH, stdin)) {
        free(input);
        input = NULL;
    }
    return input;
}

char **parse_input(char *input) {
    char **command = malloc(MAX_ARGS * sizeof(char *));
    int i = 0;
    while ((command[i] = strsep(&input, " \t\n")) != NULL) {
        if (*command[i] != '\0') {
            i++;
        }
    }
    return command;
}

int execute(char **command) {
    pid_t pid, wpid;
    int status;
    pid = fork();
    if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int main() {
    char *input;
    char **command;
    int status;
    printf("Welcome to MyShell!\n");
    printf("Enter 'exit' to exit.\n");
    do {
        printf("> ");
        input = get_input();
        command = parse_input(input);
        status = execute(command);
        free(input);
        free(command);
    } while (status);
    return 0;
}