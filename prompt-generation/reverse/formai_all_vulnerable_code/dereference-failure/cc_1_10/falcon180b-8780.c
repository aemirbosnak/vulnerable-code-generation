//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIMITER " "

typedef struct {
    char *command;
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    if (command->argument_count == 0) {
        if (system(command->command) == -1) {
            fprintf(stderr, "Error executing command: %s\n", command->command);
            exit(EXIT_FAILURE);
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error forking process\n");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char *args[MAX_ARGUMENTS];
            int i;

            for (i = 0; i < command->argument_count; i++) {
                args[i] = command->arguments[i];
            }
            args[i] = NULL;

            if (execvp(command->command, args) == -1) {
                fprintf(stderr, "Error executing command: %s\n", command->command);
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void parse_command(char *input, Command *command) {
    char *token;
    int i;

    command->command = strtok(input, DELIMITER);
    command->argument_count = 0;

    while ((token = strtok(NULL, DELIMITER))!= NULL) {
        if (command->argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments for command\n");
            exit(EXIT_FAILURE);
        }

        command->arguments[command->argument_count] = token;
        command->argument_count++;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}