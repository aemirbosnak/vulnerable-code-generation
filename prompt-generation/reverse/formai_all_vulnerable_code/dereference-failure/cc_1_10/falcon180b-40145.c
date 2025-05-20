//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char **args;
    int background = 0;
    int exit_status;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);
        args = split_line(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "bg") == 0) {
            background = 1;
        } else if (strcmp(args[0], "fg") == 0) {
            background = 0;
        } else if (strcmp(args[0], "jobs") == 0) {
            // TODO: Implement jobs command
        } else {
            execute_command(args);
        }
    }

    return 0;
}