//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PATH ":/bin:/usr/bin"

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

    if (argv[0] == NULL || strcmp(argv[0], "") == 0) {
        fprintf(stderr, "launch_shell: Command not found.\n");
        return -1;
    }

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        fprintf(stderr, "launch_shell: Fork failed.\n");
    } else {
        waitpid(pid, NULL, 0);
    }

    return pid;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = split_command(input);
    pid = launch_shell(argv);
}

int main(void) {
    setenv("PATH", PATH, 1);

    loop();

    return EXIT_SUCCESS;
}