//Falcon-180B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int argument_count;
    char *command;
} Command;

void execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(command->arguments[0], command->arguments);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}

void parse_command(char *buffer, Command *command) {
    char *token = strtok(buffer, " ");
    int argument_count = 0;

    while (token!= NULL) {
        if (argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(EXIT_FAILURE);
        }

        command->arguments[argument_count] = token;
        argument_count++;

        token = strtok(NULL, " ");
    }

    command->argument_count = argument_count;
    command->command = strdup(buffer);
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input_buffer, "exit\n") == 0) {
            break;
        }

        parse_command(input_buffer, &command);
        execute_command(&command);
    }

    return 0;
}