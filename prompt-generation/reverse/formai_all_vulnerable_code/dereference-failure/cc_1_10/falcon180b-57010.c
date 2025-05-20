//Falcon-180B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execvp(command->command, command->arguments);
        perror("Error:");
        exit(1);
    } else if (pid < 0) {
        perror("Error:");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void read_command(char *buffer, Command *command) {
    char *token;
    int num_arguments = 0;

    token = strtok(buffer, " ");
    strcpy(command->command, token);

    while ((token = strtok(NULL, " "))!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        command->arguments[num_arguments] = strdup(token);
        num_arguments++;
    }

    command->num_arguments = num_arguments;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        read_command(input, &command);
        execute_command(&command);
    }

    return 0;
}