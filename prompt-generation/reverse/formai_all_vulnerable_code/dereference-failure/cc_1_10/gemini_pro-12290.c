//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_ARGS 32
#define MAX_LINE_LEN 1024

void trim(char *str) {
    char *p = str;
    while (*p && *p <= ' ') p++;
    char *start = p;
    while (*p) p++;
    while (p > start && *--p <= ' ');
    *++p = '\0';
}

int main() {
    char line[MAX_LINE_LEN];
    int status;
    while (1) {
        printf("quiet-shell$ ");
        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        trim(line);
        if (strcmp(line, "") == 0) continue;
        char *args[MAX_ARGS];
        int arg_count = 0;
        char *pch = strtok(line, " ");
        while (pch != NULL && arg_count < MAX_ARGS) {
            args[arg_count++] = pch;
            pch = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        if (strcmp(args[0], "exit") == 0) exit(EXIT_SUCCESS);
        pid_t child = fork();
        if (child == 0) {
            int fd;
            if ((fd = open("output.txt", O_CREAT | O_WRONLY, 0666)) < 0) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd, 1) < 0) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            if (execvp(args[0], args) < 0) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
            if (status == 0) {
                printf("child exited normally\n");
            } else {
                printf("child exited with status %d\n", status);
            }
        }
    }
    return 0;
}