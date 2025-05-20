//GEMINI-pro DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 128

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char **args = malloc(sizeof(char *) * MAX_ARGS);
    if (args == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    int status;
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return EXIT_FAILURE;
    }

    if (WIFEXITED(status)) {
        printf("Child exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("Child terminated abnormally\n");
    }

    free(args);
    return EXIT_SUCCESS;
}