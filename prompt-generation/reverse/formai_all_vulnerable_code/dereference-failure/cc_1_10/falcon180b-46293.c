//Falcon-180B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS_LENGTH 4096

typedef struct {
    char **args;
    int count;
} Args;

int main(int argc, char *argv[]) {
    int status;
    pid_t pid;
    char input[MAX_COMMAND_LENGTH];
    Args args;

    args.count = 0;
    args.args = malloc(MAX_ARGS_LENGTH);

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        args.args[args.count] = strdup(token);
        args.count++;
        token = strtok(NULL, " ");
    }

    pid = fork();

    if (pid == 0) {
        execvp(args.args[0], args.args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }

    for (int i = 0; i < args.count; i++) {
        free(args.args[i]);
    }
    free(args.args);

    return 0;
}