//Falcon-180B DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

char **arguments;
int argument_count;

void execute_command(char *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        char *new_argv[MAX_ARGUMENTS];
        int i;

        for (i = 0; i < argument_count; i++) {
            new_argv[i] = arguments[i];
        }
        new_argv[argument_count] = NULL;

        execvp(new_argv[0], new_argv);
        fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(child_pid, &status, 0);
    }
}

void signal_handler(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user\n");
            break;
        case SIGTERM:
            fprintf(stdout, "Terminated by system\n");
            break;
        default:
            fprintf(stdout, "Received signal %d\n", signum);
            break;
    }
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command;
    char *token;
    int i;

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Welcome to the SHOCKED System Administration Shell!\n");

    while (1) {
        fprintf(stdout, "> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command = strtok(input_buffer, "\n");

        if (command == NULL) {
            continue;
        }

        argument_count = 0;
        arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

        token = strtok(command, " ");

        while (token!= NULL) {
            arguments[argument_count] = token;
            argument_count++;

            if (argument_count >= MAX_ARGUMENTS) {
                fprintf(stderr, "Too many arguments for command\n");
                exit(1);
            }

            token = strtok(NULL, " ");
        }

        execute_command(command);
    }

    return 0;
}