//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_CMD_TOKEN_SIZE 64
#define MAX_NUM_OF_CMD_TOKENS 64

void print_satisfied_message() {
    printf("\033[1;32m>>> \033[1;31mSHELL\033[1;32m SATISFIED <<<\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_OF_CMD_TOKENS];
    pid_t pid;
    int status;

    while (1) {
        print_satisfied_message();
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strchr(input, '\n') != NULL) {
            input[strcspn(input, "\n")] = '\0';
        }

        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL) {
            tokens[i++] = strdup(token);
            token = strtok(NULL, " ");
        }

        tokens[i] = NULL;

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        pid = fork();

        if (pid == 0) {
            // Child process
            execvp(tokens[0], tokens);
            perror("execvp failed");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            waitpid(pid, &status, 0);
        } else {
            perror("fork failed");
            exit(1);
        }

        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
    }

    return 0;
}