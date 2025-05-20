//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define MAX_CMD_ARG 256

char **tokens;
int num_tokens;

void print_tokens() {
    int i;
    for (i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

void split_line(char *line) {
    char *token;
    num_tokens = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
}

void execute_command() {
    pid_t pid;
    int status;
    int i;

    if (num_tokens < 1) {
        printf("Error: No command provided\n");
        return;
    }

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    pid = fork();
    if (pid == 0) { // Child process
        if (num_tokens > 1) {
            for (i = 1; i < num_tokens; i++) {
                if (i > 1 && strcmp(tokens[i - 1], "<") == 0) {
                    int input_fd = open(tokens[i], O_RDONLY);
                    dup2(input_fd, 0);
                    close(input_fd);
                    tokens[i] = NULL;
                }
                if (i > 1 && strcmp(tokens[i], ">") == 0) {
                    int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                    dup2(output_fd, STDOUT_FILENO);
                    close(output_fd);
                    tokens[i] = NULL;
                }
            }

            execvp(tokens[0], tokens);
            perror("Error executing command");
            exit(1);
        } else {
            execvp(tokens[0], &tokens[0]);
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) { // Parent process
        wait(&status);
    } else { // Fork failed
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    int i;

    tokens = (char **) calloc(MAX_TOKENS, sizeof(char *));

    while (1) {
        printf("Shellquiz> ");
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line)] = '\0';
        split_line(line);
        execute_command();
    }

    for (i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}