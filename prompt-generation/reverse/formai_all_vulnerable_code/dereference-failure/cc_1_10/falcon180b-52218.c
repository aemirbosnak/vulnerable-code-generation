//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = NULL;
    char *token;

    while ((token = strtok(command, DELIM))) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
    }

    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;

    if (argv[0] == NULL)
        return -1;

    switch (pid = fork()) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            if (execvp(argv[0], argv) == -1)
                perror("execvp");
            exit(EXIT_FAILURE);
        default:
            waitpid(pid, NULL, 0);
            break;
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t shell_pid;

    printf("Ken Thompson's Unix Shell\n");
    printf("Type 'exit' to quit\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0)
            break;

        args = split_command(input);
        shell_pid = launch_shell(args);
    }

    return 0;
}