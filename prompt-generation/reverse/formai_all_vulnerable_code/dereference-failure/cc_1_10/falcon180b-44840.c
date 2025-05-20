//Falcon-180B DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

int num_commands = 0;
char **commands;

void execute_command(char **command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        exit(1);
    } else if (pid == 0) {
        execvp(command[0], command);
        perror("execvp Failed");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void read_commands(char *input) {
    char *token;
    int i = 0;

    token = strtok(input, DELIM);

    while (token!= NULL) {
        if (i >= MAX_COMMAND_LENGTH) {
            printf("Error: Too many commands.\n");
            exit(1);
        }

        commands[i] = malloc(strlen(token) + 1);
        strcpy(commands[i], token);

        token = strtok(NULL, DELIM);
        i++;
    }

    num_commands = i;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("fopen Failed");
        exit(1);
    }

    fgets(input, MAX_COMMAND_LENGTH, fp);

    read_commands(input);

    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i]);
    }

    for (int i = 0; i < num_commands; i++) {
        free(commands[i]);
    }

    free(commands);

    return 0;
}