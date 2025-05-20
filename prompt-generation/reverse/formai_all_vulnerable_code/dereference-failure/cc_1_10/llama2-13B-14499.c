//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

int main(void) {
    char *cmd;
    char *args[MAX_ARGS];
    int status;

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = 0; // trim the newline

        if (cmd[0] == '\0') {
            continue;
        }

        if (sscanf(cmd, "%63[a-zA-Z0-9_-]+", args[0]) != 1) {
            printf("Invalid command: %s\n", cmd);
            continue;
        }

        args[1] = NULL;
        if (cmd[strlen(cmd) - 1] == ' ') {
            // check for additional arguments
            if (sscanf(cmd + strlen(cmd) - 1, "%63[a-zA-Z0-9_-]+", args[1]) != 1) {
                printf("Invalid argument: %s\n", cmd);
                continue;
            }
        }

        switch (execv(args[0], args)) {
            case -1:
                perror("execv");
                break;
            case 0:
                // command succeeded, exit
                break;
            default:
                // command failed, wait for the child process to exit
                wait(&status);
                break;
        }
    }

    return 0;
}