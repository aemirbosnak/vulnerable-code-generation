//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH/2 + 1)); // Add one for null terminator
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        i++;
        if (argc >= MAX_COMMAND_LENGTH/2) {
            fprintf(stderr, "Error: Command too long.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: Empty command.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) { // Child process
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s not found.\n", argv[0]);
            return 1;
        }
    } else if (pid < 0) { // Error forking
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else { // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Error: Command terminated by signal %d.\n", WTERMSIG(status));
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **command_argv;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        command_argv = split_command(input);
        execute_command(command_argv);
    }

    return 0;
}