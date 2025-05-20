//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
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

char input[MAX_INPUT_SIZE];
char **tokens;
int num_tokens;

void parse_input(char *line) {
    char *token;
    int i = 0;

    num_tokens = 0;
    tokens = (char **) malloc(MAX_NUM_TOKENS * sizeof(char *));

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;

        token = strtok(NULL, " ");
    }
    tokens[num_tokens] = NULL;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("Error changing directory");
        }
    } else if (strcmp(tokens[0], "echo") == 0) {
        int i;
        for (i = 1; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    } else if (strcmp(tokens[0], "ls") == 0) {
        system("ls");
    } else if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else {
        pid = fork();

        if (pid < 0) {
            perror("Error forking process");
            exit(1);
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(tokens[0], tokens) < 0) {
                perror("Error executing command");
                exit(1);
            }
        }
    }
}

int main() {
    char *line;
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf("> ");
        read = getline(&line, &len, stdin);
        if (read < 0) {
            break;
        }

        parse_input(line);
        execute_command(tokens);
        free(line);
    }

    free(tokens);

    return 0;
}