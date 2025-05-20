//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char *prog_name;

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    prog_name = argv[0];
    char **args = (char **)malloc(sizeof(char *) * (argc - 1));
    if (args == NULL) {
        error("malloc");
    }

    int i = 1;
    while (i < argc) {
        args[i - 1] = argv[i];
        i++;
    }

    pid_t pid = fork();
    if (pid == -1) {
        error("fork");
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            error("execvp");
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    free(args);
    return 0;
}