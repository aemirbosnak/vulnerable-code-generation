//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\n"

void shellPrompt() {
    printf("MyShell> ");
}

char *readLine() {
    char *buffer = NULL;
    ssize_t bufferSize = 0;

    if (getline(&buffer, &bufferSize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        } else {
            perror("readLine");
            exit(EXIT_FAILURE);
        }
    }

    return buffer;
}

char **splitCommand(char *line) {
    int bufferSize = BUFFER_SIZE, position = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;
    
    if (!tokens) {
        perror("splitCommand allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITER);

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufferSize) {
            bufferSize += BUFFER_SIZE;
            tokens = realloc(tokens, bufferSize * sizeof(char*));

            if (!tokens) {
                perror("splitCommand reallocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }

    tokens[position] = NULL;
    return tokens;
}

int executeCommand(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork error");
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("executeCommand error");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main(int argc, char *argv[]) {
    char *line;
    char **args;
    int status;

    printf("Welcome to MyShell!\n");

    do {
        shellPrompt();
        line = readLine();
        args = splitCommand(line);
        status = executeCommand(args);
        
        free(line);
        free(args);
    } while (status);

    return 0;
}