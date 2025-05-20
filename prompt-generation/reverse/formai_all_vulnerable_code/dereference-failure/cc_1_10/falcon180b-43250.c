//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t launch_shell(char **arguments);
int execute_command(char **arguments);
void print_prompt(void);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        arguments = split_string(input);
        execute_command(arguments);
        print_prompt();
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Error: command not found\n");
        return 1;
    }

    pid = launch_shell(arguments);
    if (pid == -1) {
        return 1;
    }

    waitpid(pid, &status, WUNTRACED);
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}