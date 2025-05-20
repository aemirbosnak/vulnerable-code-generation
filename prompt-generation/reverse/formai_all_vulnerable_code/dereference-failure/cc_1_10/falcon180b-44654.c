//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork_and_exec(char **args);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_command(input);
        pid_t pid = fork_and_exec(args);

        if (pid == -1) {
            printf("Error forking process\n");
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        execlp(args[0], args[0], NULL);
        printf("Error executing %s\n", args[0]);
        exit(1);
    } else if (pid < 0) {
        printf("Error forking process\n");
        exit(1);
    }

    return pid;
}

void print_prompt() {
    printf("> ");
}