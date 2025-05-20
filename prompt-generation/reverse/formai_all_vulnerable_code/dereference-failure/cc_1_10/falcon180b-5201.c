//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

typedef struct {
    char **args;
    int argc;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        if (command->argc == 0) {
            printf("No command specified\n");
            exit(1);
        }

        execvp(command->args[0], command->args);

        printf("Error executing command: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void add_command(Command *commands, int *command_count, char *input) {
    int argc = 0;
    char *token;
    char *args[MAX_ARGS];

    token = strtok(input, " ");

    while (token!= NULL) {
        args[argc++] = token;

        if (argc >= MAX_ARGS) {
            printf("Too many arguments\n");
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    (*command_count)++;
    commands = realloc(commands, sizeof(Command) * (*command_count));

    commands[*command_count - 1].args = args;
    commands[*command_count - 1].argc = argc;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_COMMAND_LENGTH];
    Command commands[MAX_COMMAND_LENGTH];
    int command_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        add_command(commands, &command_count, line);
    }

    fclose(file);

    for (int i = 0; i < command_count; i++) {
        execute_command(&commands[i]);
    }

    return 0;
}