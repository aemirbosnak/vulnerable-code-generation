//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int argument_count;
} Command;

int create_child_process(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        char *args[MAX_ARGUMENTS];
        int arg_count = 0;

        args[arg_count++] = command->arguments[0];

        for (int i = 1; i < command->argument_count; i++) {
            args[arg_count++] = command->arguments[i];
        }

        args[arg_count] = NULL;

        execvp(args[0], args);
        fprintf(stderr, "Exec failed\n");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return 0;
    }
}

int main() {
    FILE *file = fopen("boot.log", "r");

    if (file == NULL) {
        fprintf(stderr, "Boot log not found\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    Command command;

    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        int argument_count = 0;
        char *token = strtok(line, " ");

        while (token!= NULL) {
            if (argument_count >= MAX_ARGUMENTS) {
                fprintf(stderr, "Too many arguments\n");
                return 1;
            }

            command.arguments[argument_count] = strdup(token);
            argument_count++;

            token = strtok(NULL, " ");
        }

        command.argument_count = argument_count;
        create_child_process(&command);
    }

    fclose(file);
    return 0;
}