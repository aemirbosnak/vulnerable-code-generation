//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **split_string(char *string, int *args_count) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    int i = 0;
    char *token = strtok(string, DELIM);
    while (token!= NULL && i < MAX_ARGUMENTS) {
        arguments[i] = malloc(strlen(token) + 1);
        strcpy(arguments[i], token);
        token = strtok(NULL, DELIM);
        i++;
    }
    *args_count = i;
    return arguments;
}

void execute_command(char **arguments) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(arguments[0], arguments);
        perror("Error executing command");
        exit(1);
    } else if (pid < 0) {
        perror("Error forking");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char input_buffer[MAX_COMMAND_LENGTH];
    strcpy(input_buffer, argv[1]);

    int args_count;
    char **arguments = split_string(input_buffer, &args_count);

    if (args_count == 0) {
        printf("Error: No command specified\n");
        return 1;
    }

    execute_command(arguments);

    for (int i = 0; i < args_count; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return 0;
}