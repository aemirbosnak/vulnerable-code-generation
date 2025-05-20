//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1000
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *str);
pid_t fork_process(char **args);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[BUFFER_SIZE];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        args = split_string(input_buffer);
        if (args[0] == NULL)
            continue;

        pid = fork_process(args);
        if (pid == -1) {
            printf("Error forking process\n");
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(MAX_COMMANDS * sizeof(char *));

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork_process(char **args) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

void handle_signal(int signum) {
    printf("Signal %d received\n", signum);
}