//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PATH ":/bin:/sbin"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delimiter[2] = " ";

    token = strtok(string, delimiter);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delimiter);
    }

    tokens = (char **)malloc((words + 1) * sizeof(char *));

    bufsize = 0;
    words = 0;
    token = strtok(string, delimiter);
    while (token!= NULL) {
        tokens[words] = (char *)malloc(strlen(token) + 1);
        strcpy(tokens[words], token);
        bufsize += strlen(token) + 1;
        words++;
        token = strtok(NULL, delimiter);
    }
    tokens[words] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = vfork()) == 0) {
        return pid;
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the post-apocalyptic shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        execute_command(args);
    }

    return 0;
}