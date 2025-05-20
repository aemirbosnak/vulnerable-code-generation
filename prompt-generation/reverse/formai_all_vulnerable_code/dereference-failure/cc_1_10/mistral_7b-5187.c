//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void parse_input(char *line, char **tokens, int *num_tokens);
void execute_command(char **tokens, int num_tokens);

int main() {
    char line[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    int num_tokens;

    printf("Welcome to SimpleShell v1.0\n");
    printf("Type \"help\" for a list of available commands.\n");

    while (1) {
        printf("\nSimpleShell> ");
        bzero(line, MAX_INPUT_SIZE);
        fgets(line, MAX_INPUT_SIZE, stdin);

        line[strlen(line)] = '\0';

        parse_input(line, tokens, &num_tokens);

        if (strcmp(tokens[0], "help") == 0) {
            printf("Available commands:\n");
            printf("1. cd - Change directory\n");
            printf("2. ls - List files and directories\n");
            printf("3. echo - Print text to stdout\n");
            printf("4. exit - Exit the shell\n");
            continue;
        }

        if (num_tokens < 1) {
            printf("Invalid input\n");
            continue;
        }

        execute_command(tokens, num_tokens);
    }

    return 0;
}

void parse_input(char *line, char **tokens, int *num_tokens) {
    char *token;
    *num_tokens = 0;

    token = strtok(line, " ");

    while (token != NULL) {
        tokens[*num_tokens] = token;
        (*num_tokens)++;

        if ((*num_tokens) == MAX_NUM_TOKENS) {
            printf("Error: Too many tokens\n");
            break;
        }

        token = strtok(NULL, " ");
    }
}

void execute_command(char **tokens, int num_tokens) {
    pid_t pid;
    int status;

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("Error changing directory");
        }
        return;
    }

    if (strcmp(tokens[0], "echo") == 0) {
        int i;
        for (i = 1; i < num_tokens; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
        return;
    }

    pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        return;
    }

    if (pid > 0) {
        wait(&status);
        return;
    }

    if (execvp(tokens[0], tokens) < 0) {
        perror("Error executing command");
        exit(1);
    }
}