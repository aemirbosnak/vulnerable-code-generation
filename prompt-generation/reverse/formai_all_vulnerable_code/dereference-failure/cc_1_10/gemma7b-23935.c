//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
    int i = 0;
    char **argv = malloc(sizeof(char *) * MAX_CMD_LEN);
    char *arg = strtok(cmd, " ");
    while (arg) {
        argv[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }
    argv[i] = NULL;
    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        char **argv = parse_cmd(cmd);

        if (!strcmp(argv[0], "exit")) {
            exit(0);
        } else if (!strcmp(argv[0], "help")) {
            printf("Available commands:\n");
            printf("exit\n");
            printf("help\n");
            printf("dir\n");
            printf("cd\n");
            printf("touch\n");
            printf("rm\n");
            printf("mv\n");
            printf("cp\n");
            printf("cat\n");
            printf("pwd\n");
            printf("echo\n");
        } else if (!strcmp(argv[0], "dir")) {
            system("ls");
        } else if (!strcmp(argv[0], "cd")) {
            system("pwd");
        } else if (!strcmp(argv[0], "touch")) {
            system("touch");
        } else if (!strcmp(argv[0], "rm")) {
            system("rm");
        } else if (!strcmp(argv[0], "mv")) {
            system("mv");
        } else if (!strcmp(argv[0], "cp")) {
            system("cp");
        } else if (!strcmp(argv[0], "cat")) {
            system("cat");
        } else if (!strcmp(argv[0], "pwd")) {
            system("pwd");
        } else if (!strcmp(argv[0], "echo")) {
            system("echo");
        } else {
            printf("Unknown command.\n");
        }

        free(argv);
    }
}