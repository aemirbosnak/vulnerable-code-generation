//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the visionary shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        execute_command(args);
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);

    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);

        if (args == NULL) {
            printf("Error: Out of memory.\n");
            exit(1);
        }

        args[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 0;

    if (strcmp(args[0], "exit") == 0) {
        return 1;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Error: No directory specified.\n");
        } else {
            if (chdir(args[1])!= 0) {
                printf("Error: Could not change directory.\n");
            }
        }
    } else {
        pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else if (pid < 0) {
            printf("Error: Could not fork.\n");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}