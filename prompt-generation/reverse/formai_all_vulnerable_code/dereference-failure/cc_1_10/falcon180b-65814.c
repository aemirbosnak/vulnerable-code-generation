//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        execute_command(argv);
        free(argv);
    }
}

int main() {
    loop(">");
    return 0;
}