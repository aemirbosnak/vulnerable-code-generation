//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

char **split_string(char *string);
int execute_command(char **args);
void sigint_handler(int signum);

int main(void) {
    char input_buffer[BUFFER_SIZE];
    char **args;
    pid_t pid;

    signal(SIGINT, sigint_handler);

    while (TRUE) {
        printf("> ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        args = split_string(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);

        if (tokens == NULL) {
            fprintf(stderr, "Memory error\n");
            exit(EXIT_FAILURE);
        }

        tokens[count - 1] = token;

        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
            return 1;
        } else {
            fprintf(stderr, "Unknown error\n");
            return 1;
        }
    }
}

void sigint_handler(int signum) {
    fprintf(stdout, "\n");
    exit(EXIT_SUCCESS);
}