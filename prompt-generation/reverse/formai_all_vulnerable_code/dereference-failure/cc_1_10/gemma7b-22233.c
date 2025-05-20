//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_cmd(char **cmd) {
    char **args = NULL;
    int i = 0;
    char cmd_line[MAX_CMD_LEN];

    printf("%s", shell_prompt);
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    *cmd = strdup(cmd_line);

    // Split the command line into arguments
    args = malloc(sizeof(char *) * MAX_CMD_LEN);
    i = 0;
    while (*cmd_line) {
        args[i++] = strtok(*cmd_line, " ");
        *cmd_line = strchr(*cmd_line, " ") + 1;
    }

    *args = args;
}

int main() {
    char *cmd = NULL;
    char **args = NULL;

    while (1) {
        parse_cmd(&cmd);

        if (strcmp(cmd, "exit") == 0) {
            exit(0);
        }

        // Fork and execute the command
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            exit(1);
        }

        wait(NULL);
    }

    return 0;
}