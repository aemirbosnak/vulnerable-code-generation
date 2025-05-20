//MISTRAL-7B DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_TOKENS 64
#define MAX_CMD_LEN 256

char **tokens;
char input[MAX_INPUT];
char cmd[MAX_CMD_LEN];
pid_t pid;
int status;

void split_line(char *line) {
    char *token;
    int i = 0;

    tokens = malloc(MAX_TOKENS * sizeof(char *));

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

void execute_command() {
    int i;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    pid = fork();
    if (pid == 0) { // child process
        if (execvp(tokens[0], tokens) < 0) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) { // error forking
        perror("Error forking process");
        exit(1);
    } else { // parent process
        wait(&status);
    }
}

int main() {
    int i;

    while (1) {
        printf("shell> ");
        fgets(input, MAX_INPUT, stdin);
        input[strlen(input)] = '\0'; // remove newline character

        strcpy(cmd, input);
        split_line(cmd);

        if (strcmp(cmd, "") == 0) {
            continue;
        }

        execute_command();
    }

    return 0;
}