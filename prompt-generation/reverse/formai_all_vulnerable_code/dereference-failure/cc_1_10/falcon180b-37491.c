//Falcon-180B DATASET v1.0 Category: System administration ; Style: shape shifting
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

typedef struct {
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork process\n");
        exit(1);
    } else if (pid == 0) {
        if (command->argument_count > 0) {
            execvp(command->arguments[0], command->arguments);
        } else {
            fprintf(stderr, "No command specified\n");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    char input_buffer[MAX_COMMAND_LENGTH];
    strcpy(input_buffer, argv[1]);

    char *token = strtok(input_buffer, " ");
    Command command = {0};

    while (token!= NULL) {
        if (command.argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }

        command.arguments[command.argument_count++] = token;
        token = strtok(NULL, " ");
    }

    execute_command(&command);

    return 0;
}