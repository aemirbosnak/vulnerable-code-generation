//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = ">> ";

void parseCmd(char **cmd) {
    char **argv = NULL;
    int i = 0;
    char cmdBuf[MAX_CMD_LEN];

    printf("%s", shellPrompt);
    fgets(cmdBuf, MAX_CMD_LEN, stdin);

    *cmd = strdup(cmdBuf);

    argv = malloc(sizeof(char *) * MAX_CMD_LEN);

    // Split the command into arguments
    char *token = strtok(cmdBuf, " ");
    while (token) {
        argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    argv[i] = NULL;

    *cmd = argv;
}

int main() {
    char **cmd = NULL;

    while (1) {
        parseCmd(cmd);

        // Execute the command
        execvp(cmd[0], cmd);

        // Wait for the child process to complete
        wait(NULL);

        // Free resources
        free(cmd);
        cmd = NULL;
    }

    return 0;
}