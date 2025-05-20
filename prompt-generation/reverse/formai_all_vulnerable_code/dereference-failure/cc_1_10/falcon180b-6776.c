//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(line, " ");

    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, " ");
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s not found.\n", argv[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_LINE_SIZE];
    char **args;

    printf("Enter commands, type 'exit' to quit\n");

    while (fgets(input, MAX_LINE_SIZE, stdin)!= NULL) {
        args = split_line(input);
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            execute_command(args);
        }
    }

    return 0;
}