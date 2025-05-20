//Falcon-180B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int num_arguments;
    pid_t pid;
} Command;

void execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork()\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            fprintf(stderr, "Failed to execvp()\n");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
        command.num_arguments = 0;
        char *token = strtok(input_buffer, " ");

        while (token!= NULL) {
            command.arguments[command.num_arguments] = token;
            command.num_arguments++;
            token = strtok(NULL, " ");
        }

        execute_command(&command);

        free(command.arguments);
    }

    return 0;
}