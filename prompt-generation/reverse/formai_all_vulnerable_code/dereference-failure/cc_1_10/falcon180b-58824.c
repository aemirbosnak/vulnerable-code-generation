//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PIPE_READ_FD 0
#define PIPE_WRITE_FD 1

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork_and_exec(char **argv) {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv);
    } else {
        waitpid(pid, NULL, 0);
    }

    return pid;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    printf("Enter commands followed by newline. Type 'exit' to quit.\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        argv = split_command(input_buffer);
        pid = fork_and_exec(argv);
    }

    return 0;
}