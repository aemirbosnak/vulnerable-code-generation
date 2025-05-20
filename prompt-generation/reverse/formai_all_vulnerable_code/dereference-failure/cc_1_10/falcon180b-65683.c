//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"
#define PATH "/usr/bin:/bin:/usr/sbin:/sbin"

char **split_string(char *input);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        int status = execute_command(args);
        if (status == 1) {
            printf("Command not found.\n");
        } else if (status == 2) {
            printf("Invalid argument.\n");
        } else if (status == 127) {
            printf("Command not found.\n");
        }
    }
    return 0;
}

char **split_string(char *input) {
    int count = 0;
    char *token;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    token = strtok(input, DELIM);
    while (token!= NULL) {
        args[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    char *path = getenv("PATH");
    char *new_path = malloc(strlen(PATH) + strlen(path) + 2);
    strcpy(new_path, PATH);
    strcat(new_path, ":");
    strcat(new_path, path);
    setenv("PATH", new_path, 1);
    if (execvp(args[0], args) == -1) {
        perror("Command not found");
        return 127;
    }
    waitpid(pid, &status, WUNTRACED);
    return status;
}