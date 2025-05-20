//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *line;
    char **args;

    printf("Enter commands, type 'exit' to quit\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        line = strtok(input_buffer, DELIM);

        if (strcmp(line, "exit") == 0) {
            break;
        }

        args = split_line(line);
        execute_command(args);
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Invalid command\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}