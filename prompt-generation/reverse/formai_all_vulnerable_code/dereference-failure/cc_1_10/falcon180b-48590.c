//Falcon-180B DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char *split_command(char *command, char **arguments);
void execute_command(char **arguments);
void handle_child_process(int status);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command;
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command = strtok(input_buffer, DELIM);
        arguments = split_command(command, arguments);

        if (arguments[0] == NULL) {
            printf("Invalid command.\n");
            continue;
        }

        execute_command(arguments);
    }

    return 0;
}

char *split_command(char *command, char **arguments) {
    char *token;
    int argument_count = 0;

    token = strtok(command, DELIM);
    while (token!= NULL && argument_count < MAX_ARGUMENTS) {
        arguments[argument_count] = token;
        argument_count++;
        token = strtok(NULL, DELIM);
    }

    arguments[argument_count] = NULL;
    return command;
}

void execute_command(char **arguments) {
    pid_t child_pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    child_pid = fork();

    if (child_pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else if (child_pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(child_pid, &status, 0);
        handle_child_process(status);
    }
}

void handle_child_process(int status) {
    if (WIFEXITED(status)) {
        printf("Child process exited with status %d.\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child process terminated by signal %d.\n", WTERMSIG(status));
    } else {
        printf("Child process terminated abnormally.\n");
    }
}