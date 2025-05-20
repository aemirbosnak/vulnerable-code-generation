//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        printf("Error: Command not found.\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        return;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            printf("Error: Failed to execute command.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop() {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **argv = split_line(input);
    execute_command(argv);
}

int main() {
    loop();

    return 0;
}