//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line) {
    int num_tokens = 0;
    char **tokens = (char **)calloc(MAX_NUM_TOKENS, sizeof(char *));
    char *token = strtok(line, " ");

    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    tokens[num_tokens] = NULL;
    free(line);

    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;
    int i;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        return 1;
    }

    if (pid == 0) {
        if (tokens[1][0] == '<') {
            int input_fd = open(tokens[1]+1, O_RDONLY);
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
            tokens[1] = tokens[1]+1;
        }

        if (execvp(tokens[0], tokens) == -1) {
            perror("Command Execution Failed");
            exit(1);
        }

        exit(0);
    }

    if (pid > 0) {
        waitpid(pid, &status, 0);
    }

    for (i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}

int main(int argc, char *argv[]) {
    char line[MAX_INPUT_SIZE];
    char **tokens;
    int i;

    while (1) {
        printf("myShell> ");
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line)-1] = '\0';

        tokens = tokenize(line);

        if (execute_command(tokens) != 0) {
            perror("Error executing command");
        }

        for (i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }

        free(tokens);
    }

    return 0;
}