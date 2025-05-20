//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 10

void print_error(char *error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(1);
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        print_error("fork failed");
    } else if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            print_error("execvp failed");
        }
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char **argv) {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        printf("mysh> ");
        if (!fgets(line, MAX_LINE_LENGTH, stdin)) {
            break;
        }

        // tokenize the line into arguments
        int num_args = 0;
        char *token = strtok(line, " \n");
        while (token && num_args < MAX_ARGS) {
            args[num_args++] = token;
            token = strtok(NULL, " \n");
        }

        // handle special commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (num_args < 2) {
                print_error("cd requires at least one argument");
            }
            if (chdir(args[1]) == -1) {
                print_error("chdir failed");
            }
        } else {
            // execute the command
            execute_command(args);
        }
    }

    return 0;
}