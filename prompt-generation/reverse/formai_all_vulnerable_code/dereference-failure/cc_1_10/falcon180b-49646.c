//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);
void handle_signal(int signal_number);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);

        if (arguments[0] == NULL)
            continue;

        pid = fork();

        if (pid == -1) {
            perror("Fork Failed");
            exit(1);
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_string(char *string) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;

        if (count >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }

        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL)
        return 1;

    pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        exit(1);
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Exec Failed");
            exit(1);
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return 0;
}

void handle_signal(int signal_number) {
    if (signal_number == SIGINT) {
        printf("\nInterrupted\n");
    }
}