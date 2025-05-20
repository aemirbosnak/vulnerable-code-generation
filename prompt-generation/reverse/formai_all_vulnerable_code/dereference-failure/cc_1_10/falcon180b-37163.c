//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);
void loop(void);

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the shell!\n");
    loop();
    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to 'cd'\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    execute_command(args);

    free(args);
}