//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_command(input);
        pid_t pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            fprintf(stderr, "Error forking process\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }

        print_prompt();
    }

    return EXIT_SUCCESS;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *));

    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process\n");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}