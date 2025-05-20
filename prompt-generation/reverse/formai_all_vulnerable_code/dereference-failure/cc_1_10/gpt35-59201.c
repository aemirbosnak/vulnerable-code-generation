//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 64

void printPrompt() {
    char *username = getenv("USER");
    char *hostname = malloc(256 * sizeof(char));
    gethostname(hostname, 256);
    printf("%s@%s$ ", username, hostname);
}

int readCommand(char **args) {
    char *line = NULL;
    ssize_t line_size = 0;
    if (getline(&line, &line_size, stdin) == -1) {
        free(line);
        return -1;
    }

    int i = 0;
    char *token = strtok(line, " \n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    free(line);
    return i;
}

int executeCommand(char **args) {
    if (args[0] == NULL) {
        // empty command
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        // exit command
        return 0;
    }

    pid_t pid = fork();
    if (pid == -1) {
        // fork failure
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // child process
        execvp(args[0], args);
        perror(args[0]);
        exit(EXIT_FAILURE);
    } else {
        // parent process
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {
    char *args[MAX_ARGUMENTS];

    while (1) {
        printPrompt();
        int num_args = readCommand(args);
        if (num_args == -1) {
            break;
        }
        int should_continue = executeCommand(args);
        if (should_continue == 0) {
            break;
        }
    }

    return 0;
}