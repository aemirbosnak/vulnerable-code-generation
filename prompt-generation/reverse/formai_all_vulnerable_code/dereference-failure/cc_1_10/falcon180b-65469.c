//Falcon-180B DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " "

typedef struct command_t {
    char *name;
    char *argument;
} command_t;

void execute_command(command_t *command) {
    pid_t pid = fork();

    if (pid == 0) {
        char *args[3];
        args[0] = command->name;
        args[1] = command->argument;
        args[2] = NULL;
        execvp(command->name, args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        wait(NULL);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument]\n", argv[0]);
        return 1;
    }

    char input[MAX_COMMAND_LENGTH];
    strcpy(input, argv[1]);
    command_t command;

    char *token = strtok(input, DELIM);
    command.name = token;

    if ((token = strtok(NULL, DELIM))!= NULL) {
        command.argument = token;
    } else {
        command.argument = "";
    }

    execute_command(&command);

    return 0;
}