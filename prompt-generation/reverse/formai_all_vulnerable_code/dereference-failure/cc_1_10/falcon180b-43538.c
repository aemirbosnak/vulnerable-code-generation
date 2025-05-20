//Falcon-180B DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_PATH_LENGTH 1024
#define MAX_SOCKET_LENGTH 1024

char *split_string(char *str, char delimiter) {
    char *token = strtok(str, delimiter);
    return token;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            return 1;
        }
        arguments[num_arguments] = token;
        num_arguments++;
        token = strtok(NULL, " ");
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Exec failed\n");
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}