//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = 0, word_count = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            word_count++;
        }
        str++;
    }

    tokens = malloc((word_count + 1) * sizeof(char *));

    str = strtok(str, DELIM);
    while (str) {
        tokens[word_count] = strdup(str);
        word_count++;
        str = strtok(NULL, DELIM);
    }
    tokens[word_count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Command not found.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);

    if (args[0] == NULL) {
        printf("No command entered.\n");
    } else {
        execute_command(args);
    }

    return 0;
}