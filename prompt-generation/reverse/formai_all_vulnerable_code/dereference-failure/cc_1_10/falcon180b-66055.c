//Falcon-180B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 100

typedef struct {
    char **args;
    int num_args;
} command_t;

void execute_command(command_t *command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork()\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command->args[0], command->args) == -1) {
            fprintf(stderr, "Failed to execvp()\n");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted\n");
            break;
        case SIGTSTP:
            fprintf(stdout, "\nSuspended\n");
            break;
        case SIGCONT:
            fprintf(stdout, "\nResumed\n");
            break;
        default:
            fprintf(stdout, "Received signal %d\n", signum);
            break;
    }
}

void loop(char *prompt) {
    while (1) {
        fprintf(stdout, "%s", prompt);
        fflush(stdout);

        char input[MAX_COMMAND_LENGTH];
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stdout, "\n");
            exit(1);
        }

        char *token = strtok(input, " ");
        command_t command = {0};

        while (token!= NULL) {
            if (command.num_args >= MAX_ARGS) {
                fprintf(stderr, "Too many arguments\n");
                exit(1);
            }

            command.args[command.num_args] = token;
            command.num_args++;

            token = strtok(NULL, " ");
        }

        execute_command(&command);
    }
}

int main(int argc, char *argv[]) {
    loop("> ");

    return 0;
}