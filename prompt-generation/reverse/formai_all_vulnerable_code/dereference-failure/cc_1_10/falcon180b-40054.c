//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strlen(input) == 0) {
            continue;
        }

        arguments = split_command(input);

        if (arguments[0] == NULL) {
            printf("Invalid command\n");
            continue;
        }

        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
        } else if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

pid_t fork() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    if (strcmp(arguments[0], "exit") == 0) {
        return 0;
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            if (chdir(arguments[1]) == -1) {
                perror("chdir");
            }
        }
    } else if (strcmp(arguments[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) {
                perror("execvp");
            }
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void print_prompt() {
    printf("> ");
}