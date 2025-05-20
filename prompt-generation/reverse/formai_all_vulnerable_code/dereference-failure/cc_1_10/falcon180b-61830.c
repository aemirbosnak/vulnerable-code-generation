//Falcon-180B DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

typedef struct {
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        execvp(command->arguments[0], command->arguments);
        fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    command.argument_count = 0;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input_buffer, DELIM);
        if (token == NULL) {
            continue;
        }

        command.arguments[command.argument_count] = token;
        command.argument_count++;

        if (command.argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            for (int i = 0; i < command.argument_count; i++) {
                free(command.arguments[i]);
            }
            free(command.arguments);
            command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
            command.argument_count = 0;
        }
    }

    return 0;
}