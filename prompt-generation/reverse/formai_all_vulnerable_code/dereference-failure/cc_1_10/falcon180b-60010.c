//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t execute_command(char **arguments);
void print_prompt(char *username);

int main(int argc, char *argv[]) {
    char username[64];
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command;
    char *arguments[MAX_ARGUMENTS];
    int argument_count;
    pid_t child_pid;

    strcpy(username, argv[0]);
    printf("Welcome, %s!\n", username);

    while (1) {
        strcpy(input_buffer, "");
        printf("%s> ", username);
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command = strtok(input_buffer, DELIM);
        if (command == NULL) {
            continue;
        }

        arguments[0] = command;
        argument_count = 1;
        while ((command = strtok(NULL, DELIM))!= NULL) {
            if (argument_count >= MAX_ARGUMENTS) {
                printf("Error: Too many arguments.\n");
                continue;
            }
            arguments[argument_count++] = command;
        }

        child_pid = execute_command(arguments);
        if (child_pid == -1) {
            printf("Error: Failed to execute command.\n");
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **tokens;
    char *token;
    int count;

    tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    if (tokens == NULL) {
        return NULL;
    }

    count = 0;
    token = strtok(command, DELIM);
    while (token!= NULL) {
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t execute_command(char **arguments) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        return -1;
    } else if (child_pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

void print_prompt(char *username) {
    printf("%s> ", username);
}