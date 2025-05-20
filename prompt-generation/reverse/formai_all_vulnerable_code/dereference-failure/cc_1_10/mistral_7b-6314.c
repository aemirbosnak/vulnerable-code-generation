//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_TOKEN 64
#define MAX_CMD_ARR 32

char input[MAX_INPUT];
char token[MAX_TOKEN];
char **cmd_arr;
int num_tokens, i, j, status;
pid_t pid;

void split_input(char *line) {
    char *token_ptr;
    num_tokens = 0;

    token_ptr = strtok(line, " \t\r\n");
    while (token_ptr != NULL) {
        strcpy(token, token_ptr);
        cmd_arr[num_tokens] = token;
        num_tokens++;
        token_ptr = strtok(NULL, " \t\r\n");
    }
    cmd_arr[num_tokens] = NULL;
}

int main() {
    char *args[MAX_CMD_ARR];
    char buf[MAX_INPUT];

    while (1) {
        printf("shell> ");
        bzero(input, MAX_INPUT);
        fgets(input, MAX_INPUT, stdin);

        if (strncmp(input, "exit\n", 5) == 0) {
            break;
        }

        split_input(input);

        if (num_tokens > 0) {
            args[0] = cmd_arr[0];
            for (i = 1; i < num_tokens; i++) {
                args[i] = cmd_arr[i];
            }

            pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
                perror("exec error");
                exit(1);
            }

            wait(&status);
        }
    }

    return 0;
}