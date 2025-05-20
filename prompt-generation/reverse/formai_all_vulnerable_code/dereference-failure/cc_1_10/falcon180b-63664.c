//Falcon-180B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];

    if (argc < 2) {
        printf("Usage: %s command [argument1] [argument2]...\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    int num_args = 1;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_args >= MAX_ARGS) {
            printf("Too many arguments.\n");
            return 1;
        }
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    child_pid = fork();
    if (child_pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("execvp failed.\n");
        return 1;
    } else {
        // Parent process
        waitpid(child_pid, &status, WUNTRACED);
    }

    return 0;
}