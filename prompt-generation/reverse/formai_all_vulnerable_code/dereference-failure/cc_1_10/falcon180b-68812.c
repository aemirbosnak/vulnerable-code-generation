//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define MAX_ARGUMENTS 50
#define PATH ":/bin:/usr/bin"
#define SHELL "/bin/sh"

char **split_command(char *command);
int execute_command(char **argv);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        if (strlen(input) == 0) {
            continue;
        }
        argv = split_command(input);
        execute_command(argv);
    }
    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc] = token;
        argc++;
        if (argc >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;
    if (argv[0] == NULL) {
        return 1;
    }
    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    }
    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            if (chdir(argv[1]) == -1) {
                perror("chdir");
            }
        }
        return 1;
    }
    if (argv[0][0]!= '/') {
        char *path = getenv("PATH");
        char *new_path = malloc(strlen(path) + strlen(argv[0]) + 2);
        strcpy(new_path, path);
        strcat(new_path, "/");
        strcat(new_path, argv[0]);
        argv[0] = new_path;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 1;
}