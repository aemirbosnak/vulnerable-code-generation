//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int cmd_len;
    int i;

    while (1) {
        printf("$ ");
        fgets(cmd_name, MAX_CMD_LEN, stdin);
        cmd_len = strlen(cmd_name);
        cmd_name[cmd_len - 1] = '\0';

        for (i = 0; i < MAX_ARGS; i++) {
            cmd_args[i] = NULL;
        }

        // Parse command arguments
        char *token;
        token = strtok(cmd_name, " ");
        while (token != NULL && i < MAX_ARGS) {
            cmd_args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        // Execute command
        if (cmd_len == 0 || cmd_name[0] == '\0') {
            printf("Invalid command. Please enter a command followed by arguments.\n");
            continue;
        }

        // Create a new process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork() failed");
            continue;
        }

        if (pid == 0) {
            // Child process
            char **args = cmd_args;
            execv(cmd_name, args);
            perror("execv() failed");
            exit(1);
        }

        // Parent process
        wait(NULL);
    }

    return 0;
}