//Falcon-180B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

typedef struct {
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command.arguments[0], command.arguments);
        fprintf(stderr, "Failed to execute command.\n");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    char input_buffer[MAX_COMMAND_LENGTH];
    memset(input_buffer, 0, MAX_COMMAND_LENGTH);

    FILE *input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        exit(1);
    }

    fgets(input_buffer, MAX_COMMAND_LENGTH, input_file);

    fclose(input_file);

    Command command;
    memset(&command, 0, sizeof(Command));

    char *token = strtok(input_buffer, DELIM);
    while (token!= NULL) {
        if (command.argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }

        command.arguments[command.argument_count] = strdup(token);
        command.argument_count++;

        token = strtok(NULL, DELIM);
    }

    execute_command(command);

    for (int i = 0; i < command.argument_count; i++) {
        free(command.arguments[i]);
    }

    free(command.arguments);

    return 0;
}