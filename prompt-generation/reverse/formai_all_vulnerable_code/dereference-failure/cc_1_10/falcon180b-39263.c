//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS 100
#define DELIM " "
#define TRUE 1
#define FALSE 0

typedef struct {
    char **args;
    int num_args;
} command_t;

void execute_command(command_t *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command->args[0], command->args);
        perror("Error executing command");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

command_t *parse_command(char *input) {
    command_t *command = malloc(sizeof(command_t));
    char *token;
    int argc = 0;

    token = strtok(input, DELIM);
    while (token!= NULL && argc < MAX_ARGS) {
        command->args[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    command->num_args = argc;

    return command;
}

void loop() {
    char input[MAX_COMMAND_LENGTH];
    command_t *command;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    command = parse_command(input);
    execute_command(command);
}

int main() {
    loop();

    return 0;
}