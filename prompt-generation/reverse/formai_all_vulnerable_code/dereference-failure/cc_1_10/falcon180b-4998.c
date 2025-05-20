//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIMITER " \t\r\n\a"

char **split_command(char *command, int *num_arguments);
void execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int num_arguments;

    print_prompt();

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "exit\n") == 0) {
            break;
        }

        arguments = split_command(input_buffer, &num_arguments);
        execute_command(arguments);

        free(arguments);
    }

    return 0;
}

char **split_command(char *command, int *num_arguments) {
    char **arguments = malloc((MAX_ARGUMENTS / 2) * sizeof(char *));
    int argument_index = 0;
    char *token;

    token = strtok(command, DELIMITER);
    while (token!= NULL && argument_index < MAX_ARGUMENTS - 1) {
        arguments[argument_index] = token;
        argument_index++;
        token = strtok(NULL, DELIMITER);
    }
    arguments[argument_index] = NULL;

    *num_arguments = argument_index;

    return arguments;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Error: Command not found.\n");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void print_prompt(void) {
    printf("Romeo: ");
}