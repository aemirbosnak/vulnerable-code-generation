//Falcon-180B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execvp(command->arguments[0], command->arguments);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;
    int num_arguments = 0;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
        if (command.arguments == NULL) {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }

        char *token = strtok(input_buffer, " ");
        while (token!= NULL && num_arguments < MAX_ARGUMENTS) {
            command.arguments[num_arguments] = token;
            num_arguments++;
            token = strtok(NULL, " ");
        }

        execute_command(&command);

        for (int i = 0; i < num_arguments; i++) {
            free(command.arguments[i]);
        }
        free(command.arguments);
        num_arguments = 0;
    }

    return 0;
}