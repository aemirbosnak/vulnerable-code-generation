//Falcon-180B DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **arguments);

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Welcome to the C Shell!\n");
    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input_buffer);

        pid_t child_pid = fork();

        if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (child_pid < 0) {
            printf("Error forking process.\n");
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);
    int argument_count = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argument_count < MAX_ARGUMENTS) {
        arguments[argument_count++] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argument_count] = NULL;

    return arguments;
}

pid_t fork(void) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process.\n");
        exit(1);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid = fork();

    if (pid == 0) {
        if (arguments[0] == NULL) {
            printf("Error: No command specified.\n");
            return 1;
        }

        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command: %s\n", strerror(errno));
            return 1;
        }
    } else if (pid < 0) {
        printf("Error forking process.\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}