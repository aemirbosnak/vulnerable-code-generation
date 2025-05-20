//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define BUFFER_SIZE 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    char **arguments = (char **) malloc(MAX_ARGUMENTS * sizeof(char *));
    int count = 0;
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    arguments[count] = NULL;
    return arguments;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;
    if (arguments[0] == NULL) {
        return;
    }
    if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            fprintf(stderr, "Error: Directory not specified.\n");
        } else {
            if (chdir(arguments[1])!= 0) {
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
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(arguments[0], arguments);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char input[BUFFER_SIZE];
    char **arguments;
    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        arguments = split_command(input);
        execute_command(arguments);
    }
    return 0;
}