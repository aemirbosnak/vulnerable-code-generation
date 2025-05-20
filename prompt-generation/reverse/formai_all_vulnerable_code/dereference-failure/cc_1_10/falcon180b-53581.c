//Falcon-180B DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            return 1;
        }
        arguments[num_arguments++] = token;
        token = strtok(NULL, DELIM);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(command, arguments) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}