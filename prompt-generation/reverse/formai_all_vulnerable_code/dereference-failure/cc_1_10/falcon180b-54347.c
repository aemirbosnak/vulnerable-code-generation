//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t fork(void);
int execute_command(char **arguments);
void handle_signal(int signum);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        arguments = split_string(input_buffer);
        if (arguments == NULL) {
            continue;
        }

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        } else if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        count++;
        arguments = realloc(arguments, sizeof(char *) * (count + 1));
        arguments[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    arguments[count] = NULL;
    return arguments;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}