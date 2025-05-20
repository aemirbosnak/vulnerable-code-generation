//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("Exec");
        exit(1);
    } else {
        wait(NULL);
    }
    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        char **args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }
        execute_command(args);
    }
    return 0;
}