//Falcon-180B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
void execute_command(char **arguments);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    while (1) {
        printf("Surprise! ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);
        child_pid = fork();

        if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (child_pid < 0) {
            perror("fork");
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **arguments = NULL;
    char *token;
    int argument_count = 0;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argument_count);
        arguments[argument_count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argument_count] = NULL;

    return arguments;
}

pid_t fork(void) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
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
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, WUNTRACED);
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
        case SIGTERM:
            exit(0);
        default:
            signal(signum, SIG_IGN);
    }
}