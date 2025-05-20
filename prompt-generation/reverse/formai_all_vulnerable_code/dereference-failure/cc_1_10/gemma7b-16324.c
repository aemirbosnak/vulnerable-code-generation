//Gemma-7B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

int main() {
    char cmd[MAX_CMD_LEN];
    char *argv[MAX_CMD_LEN];
    int argc;
    struct stat sb;
    pid_t pid;

    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    argc = parse_cmd(cmd, argv);

    if (argc > 0) {
        if (stat(argv[0], &sb) == 0) {
            if (S_ISDIR(sb.st_mode)) {
                execvp("./shell", argv);
            } else if (S_ISREG(sb.st_mode)) {
                pid = fork();
                if (pid == 0) {
                    execvp(argv[0], argv);
                } else {
                    wait(NULL);
                }
            } else {
                printf("Error: invalid command.\n");
            }
        } else {
            printf("Error: command not found.\n");
        }
    } else {
        printf("Error: invalid command.\n");
    }

    return 0;
}

int parse_cmd(char *cmd, char **argv) {
    char *p;
    int argc = 0;

    p = strtok(cmd, " ");
    while (p) {
        argv[argc++] = strdup(p);
        p = strtok(NULL, " ");
    }

    return argc;
}