//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 255

int main() {
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;
    pid_t pid;

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (strcmp(cmd, "exit") == 0) {
            exit(0);
        }

        argv = NULL;
        argc = 0;

        // Parse the command line arguments
        char *ptr = cmd;
        while (*ptr) {
            if (*ptr == ' ') {
                argv = realloc(argv, (argc + 1) * sizeof(char *));
                argv[argc++] = ptr;
                *ptr = '\0';
            }
            ptr++;
        }

        argv = realloc(argv, (argc + 1) * sizeof(char *));
        argv[argc++] = NULL;

        // Create a child process
        pid = fork();

        if (pid == 0) {
            execvp(argv[0], argv);
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("fork");
        }
    }
}