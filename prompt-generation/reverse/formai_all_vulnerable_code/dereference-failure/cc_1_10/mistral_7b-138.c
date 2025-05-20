//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CHILDREN 10
#define COMMAND_LENGTH 100

pid_t children[MAX_CHILDREN];
int status;

void usage() {
    printf("Usage: %s <command> [<argument> ...]\n", __FILE__);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int i, j, k, pid;
    char command[COMMAND_LENGTH];
    char *args[MAX_CHILDREN];

    if (argc > MAX_CHILDREN) {
        usage();
    }

    for (i = 0; i < argc; i++) {
        strcpy(command, argv[i]);
        args[0] = strtok(command, " ");

        for (j = 1; j < argc; j++) {
            args[j] = argv[j];
        }

        args[argc] = NULL;

        if ((pid = fork()) < 0) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("[%d] %s\n", pid, command);
            children[i] = pid;
            waitpid(pid, &status, 0);
        }
    }

    for (i = 0; i < argc; i++) {
        for (j = 0; j < argc; j++) {
            if (children[i] == children[j] && i != j) {
                printf("Process %d is a duplicate\n", children[i]);
            }
        }
    }

    return EXIT_SUCCESS;
}