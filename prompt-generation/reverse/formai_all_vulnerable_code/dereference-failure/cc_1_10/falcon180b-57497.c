//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_SIZE 1024

char *command = NULL;

void execute_command() {
    char *args[MAX_COMMAND_SIZE];
    int argc = 0;

    char *delimiter = " ";
    char *token = strtok(command, delimiter);

    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, delimiter);
    }

    args[argc] = NULL;
    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process.\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}

void read_command() {
    char buffer[MAX_COMMAND_SIZE];
    memset(buffer, 0, MAX_COMMAND_SIZE);

    printf("> ");
    fgets(buffer, MAX_COMMAND_SIZE, stdin);

    if (command!= NULL) {
        free(command);
    }

    command = strdup(buffer);
    execute_command();
}

int main() {
    char *prompt = "> ";

    while (1) {
        printf("%s", prompt);
        read_command();
    }

    return 0;
}