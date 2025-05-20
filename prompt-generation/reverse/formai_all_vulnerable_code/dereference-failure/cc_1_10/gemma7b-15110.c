//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    char *ptr = strtok(cmd, " ");
    int i = 0;

    while (ptr) {
        argv = realloc(argv, (i + 1) * sizeof(char *));
        argv[i++] = ptr;
        ptr = strtok(NULL, " ");
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

        if (argv[0] == NULL) {
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(argv[0], argv);
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Error");
        }

        free(argv);
    }

    return 0;
}