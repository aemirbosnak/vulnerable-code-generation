//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    char command[BUF_SIZE];
    char *args[10];
    int i, j;

    if (argc < 2) {
        printf("Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    i = 0;

    if (strcmp(command, "ls") == 0) {
        args[i++] = "ls";
    } else if (strcmp(command, "cd") == 0) {
        args[i++] = "cd";
    } else {
        args[i++] = command;
    }

    while (i < 10 && argc > 2) {
        args[i++] = argv[2];
        argc--;
    }

    args[i] = NULL;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Error executing command\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        return 0;
    }
}