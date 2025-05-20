//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

char **split_command(char *command);
pid_t execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command = NULL;
    char **arguments = NULL;
    pid_t child_pid;

    print_prompt();

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        command = strtok(input_buffer, "\n");
        arguments = split_command(command);

        child_pid = execute_command(arguments);
        waitpid(child_pid, NULL, 0);

        free(command);
        free(arguments);

        print_prompt();
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token;
    char *saveptr = NULL;

    token = strtok_r(command, " ", &saveptr);
    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argc);
        arguments[argc - 1] = token;
        token = strtok_r(NULL, " ", &saveptr);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t execute_command(char **arguments) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(child_pid, &status, 0);
        return child_pid;
    }
}

void print_prompt(void) {
    printf("> ");
    fflush(stdout);
}