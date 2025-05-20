//Falcon-180B DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " "

typedef struct command {
    char **arguments;
    int background;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    if (command->background) {
        pid = fork();

        if (pid == 0) {
            execlp(command->arguments[0], command->arguments[0], NULL);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            printf("Error forking process\n");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    } else {
        pid = fork();

        if (pid == 0) {
            execlp(command->arguments[0], command->arguments[0], NULL);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            printf("Error forking process\n");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, WUNTRACED);
        }
    }
}

void parse_command(char *input, Command *command) {
    char *token = strtok(input, DELIM);
    command->arguments[0] = token;

    int argc = 1;
    while ((token = strtok(NULL, DELIM))!= NULL) {
        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(EXIT_FAILURE);
        }
        command->arguments[argc] = token;
        argc++;
    }

    command->background = 0;

    char *background_token = strtok(NULL, DELIM);

    if (background_token!= NULL && strcmp(background_token, "&") == 0) {
        command->background = 1;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}