//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    printf("\nInterrupted\n");
    exit(1);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int background = 0;
    int exit_status;

    signal(SIGINT, handle_sigint);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            break;
        } else if (strcmp(argv[0], "bg") == 0 || strcmp(argv[0], "&") == 0) {
            background = 1;
        } else if (strcmp(argv[0], "fg") == 0) {
            background = 0;
        }

        if (background) {
            if (execute_command(argv) == -1) {
                exit(1);
            }
        } else {
            execute_command(argv);
            waitpid(0, &exit_status, WUNTRACED);
        }
    }

    return 0;
}