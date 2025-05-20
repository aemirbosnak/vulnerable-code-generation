//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " "

typedef struct {
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command.arguments[0], command.arguments);
        perror("Execvp failed");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_input(char *input) {
    char *token;
    Command command;

    token = strtok(input, DELIM);
    command.arguments[0] = token;
    command.argument_count = 1;

    while ((token = strtok(NULL, DELIM))!= NULL) {
        if (command.argument_count >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            return;
        }
        command.arguments[command.argument_count] = token;
        command.argument_count++;
    }

    execute_command(command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}