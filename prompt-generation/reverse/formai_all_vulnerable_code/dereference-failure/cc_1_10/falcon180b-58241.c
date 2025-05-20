//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delimiter[] = DELIM;

    token = strtok(string, delimiter);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delimiter);
    }

    tokens = (char **)malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        return NULL;
    }

    tokens[words] = NULL;
    token = strtok(string, delimiter);
    int i = 0;
    while (token!= NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delimiter);
    }

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **tokens = split_string(input);
    execute_command(tokens);
    for (int i = 0; tokens[i]!= NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main(void) {
    loop();
    return 0;
}