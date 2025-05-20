//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKEN_LEN 64
#define MAX_NUM_TOKENS 64

char **tokens;
char *token;
char cmd[MAX_CMD_LEN];
char *av[2];
char *tokenized_cmd;
int num_tokens;
int status;

void split_line(char *line) {
    char *delim = " \t\r\n\a";
    char *token = strtok(line, delim);
    num_tokens = 0;

    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, delim);
    }
    tokens[num_tokens] = NULL;
}

void exec_command() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Error: Fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        if (execvp(tokens[0], tokens) < 0) {
            fprintf(stderr, "Error: Execution failed\n");
            exit(1);
        }
    }

    waitpid(pid, &status, 0);
}

int main() {
    char line[MAX_CMD_LEN];
    int i;

    printf(">>> Welcome to the Knights' Command Line Shell <<<\n");
    printf("Enter commands in the following format: command argument argument ...\n");

    while (1) {
        printf("> ");
        fgets(line, MAX_CMD_LEN, stdin);
        line[strlen(line)] = '\0'; // remove newline character

        num_tokens = 0;
        split_line(line);

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        tokenized_cmd = (char *) malloc(strlen(tokens[0]) + 1);
        strcpy(tokenized_cmd, tokens[0]);

        av[0] = tokenized_cmd;
        av[1] = NULL;

        exec_command();

        free(tokenized_cmd);
    }

    return 0;
}