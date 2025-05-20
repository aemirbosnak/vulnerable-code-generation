//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t launch_shell(char **arguments);
void execute_command(char **arguments);

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_string(input_buffer);
        execute_command(arguments);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL && count < MAX_ARGUMENTS) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t launch_shell(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

void execute_command(char **arguments) {
    pid_t pid;

    if (arguments[0] == NULL) {
        printf("Error: Command not found\n");
        return;
    }

    if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            printf("Error: Directory not specified\n");
        } else {
            if (chdir(arguments[1]) == -1) {
                perror("chdir");
            }
        }
    } else {
        pid = launch_shell(arguments);
    }
}