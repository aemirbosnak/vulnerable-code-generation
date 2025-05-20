//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop() {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    char **argv = split_command(input);
    execute_command(argv);
}

int main() {
    loop();
    return 0;
}