//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
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

pid_t launch_process(char **argv) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    }
    return pid;
}

void monitor_process(pid_t pid) {
    int status;
    waitpid(pid, &status, 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char **argv_copy = build_argv(command);
    pid_t pid = launch_process(argv_copy);

    monitor_process(pid);

    return 0;
}