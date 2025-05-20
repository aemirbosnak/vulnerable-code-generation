//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, " ");

    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    return argv;
}

int main() {
    char input[MAX_COMMAND_LEN];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_command(input);
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error: Fork failed.\n");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}