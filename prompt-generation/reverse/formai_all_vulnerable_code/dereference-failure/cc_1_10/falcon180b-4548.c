//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

char **split_command(char *command);
int execute_command(char **args);
void print_prompt(char *username);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *username = "LoveBird";
    print_prompt(username);

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        int status = execute_command(args);

        if (status == 1) {
            print_prompt(username);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *) * MAX_COMMAND_LENGTH);
    char *token = strtok(command, " ");

    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void print_prompt(char *username) {
    printf("LoveBird@LoveNest ~ $ ");
}