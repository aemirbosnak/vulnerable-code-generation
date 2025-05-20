//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

#define MAX_LINE_LEN 1024

char *get_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *buffer = NULL;
    char *temp = NULL;

    buffer = malloc(MAX_LINE_LEN);
    if (buffer == NULL) {
        fprintf(stderr, "Error: malloc() failed.\n");
        exit(1);
    }

    while ((read = getline(&buffer, &len, fp))!= -1) {
        if (buffer[read - 1] == '\n') {
            buffer[--read] = '\0';
        } else {
            temp = realloc(buffer, len + 1);
            if (temp == NULL) {
                fprintf(stderr, "Error: realloc() failed.\n");
                exit(1);
            }
            buffer = temp;
        }

        line = strdup(buffer);
        if (line == NULL) {
            fprintf(stderr, "Error: strdup() failed.\n");
            exit(1);
        }
        break;
    }

    free(buffer);

    return line;
}

int main() {
    char *line = NULL;
    FILE *fp;
    pid_t pid;
    int status;

    fp = popen("ps -ef", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: popen() failed.\n");
        exit(1);
    }

    while ((line = get_line(fp))!= NULL) {
        pid_t child_pid;
        char *cmd = strtok(line, " ");
        int i;

        for (i = 0; i < strlen(cmd); i++) {
            if (cmd[i] == '/') {
                cmd = &cmd[i + 1];
                break;
            }
        }

        child_pid = fork();
        if (child_pid == 0) {
            execlp(cmd, cmd, NULL);
            fprintf(stderr, "Error: execlp() failed.\n");
            exit(1);
        } else if (child_pid < 0) {
            fprintf(stderr, "Error: fork() failed.\n");
            exit(1);
        } else {
            waitpid(child_pid, &status, 0);
        }

        free(line);
    }

    pclose(fp);

    return 0;
}