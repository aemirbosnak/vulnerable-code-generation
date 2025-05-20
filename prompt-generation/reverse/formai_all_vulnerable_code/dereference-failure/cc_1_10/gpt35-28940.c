//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUMBER_OF_ARGUMENTS 64

int execute_command(char** tokens) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            printf("Could not execute command.\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        printf("Error while forking.\n");
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

char** get_tokens(char* command) {
    char** tokens = malloc(MAX_NUMBER_OF_ARGUMENTS * sizeof(char*));
    char* token;
    int i = 0;

    token = strtok(command, " \n\r\t\a");
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \n\r\t\a");
    }
    tokens[i] = NULL;
    return tokens;
}

int main(int argc, char const *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    int running = 1;

    while (running) {
        printf("> ");
        if (!fgets(command, MAX_COMMAND_LENGTH, stdin)) {
            break;
        }

        char** tokens = get_tokens(command);
        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            running = 0;
        } else {
            execute_command(tokens);
        }

        free(tokens);
    }
    return 0;
}