//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_REDIRECTIONS 10

char **split_command(char *command, int *num_arguments);
int execute_command(char **arguments);
void handle_signal(int signal);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    int num_arguments;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (input[0] == '\n') {
            continue;
        }

        arguments = split_command(input, &num_arguments);
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command, int *num_arguments) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;
    int count = 0;

    token = strtok(command, " \t\r\n");
    while (token!= NULL && count < MAX_ARGUMENTS) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, " \t\r\n");
    }

    *num_arguments = count;
    return tokens;
}

int execute_command(char **arguments) {
    int i;
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    if (strcmp(arguments[0], "exit") == 0) {
        return 0;
    }

    for (i = 0; i < MAX_REDIRECTIONS; i++) {
        if (arguments[i]!= NULL && strcmp(arguments[i], ">") == 0) {
            int fd = open(arguments[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                return 1;
            }
            dup2(fd, 1);
            close(fd);
            i++;
        } else if (arguments[i]!= NULL && strcmp(arguments[i], "<") == 0) {
            int fd = open(arguments[i + 1], O_RDONLY);
            if (fd == -1) {
                perror("open");
                return 1;
            }
            dup2(fd, 0);
            close(fd);
            i++;
        }
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nInterrupted\n");
    }
}