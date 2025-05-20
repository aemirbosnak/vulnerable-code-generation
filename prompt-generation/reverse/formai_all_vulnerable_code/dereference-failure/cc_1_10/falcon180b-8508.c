//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return EXIT_SUCCESS;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_line(input);
    int status = execute_command(args);

    if (WIFEXITED(status)) {
        printf("Exit status: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Killed by signal %d\n", WTERMSIG(status));
    } else {
        printf("Unknown exit status\n");
    }

    free(args);
}

char **split_line(char *line) {
    int argc = 0;
    int len = strlen(line);
    char **args = malloc((len + 1) * sizeof(char *));

    char *token = strtok(line, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);

        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
    }
    args[argc] = NULL;

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
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
            return 1;
        }
        if (chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
        return 0;
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                return 1;
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}