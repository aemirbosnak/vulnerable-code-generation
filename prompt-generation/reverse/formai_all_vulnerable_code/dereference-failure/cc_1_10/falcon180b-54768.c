//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: ultraprecise
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

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **command_argv = NULL;
    int command_argc = 0;
    int status;

    while (1) {
        memset(input_buffer, 0, MAX_COMMAND_LENGTH);
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command_argv = split_command(input_buffer);
        command_argc = argc;

        status = execute_command(command_argv);
        if (status == 0) {
            printf("\n");
        }
    }

    return 0;
}