//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 8192

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *src_dir = argv[1];
    char *dst_dir = argv[2];

    char command[BUFSIZE];
    snprintf(command, BUFSIZE, "rsync -a %s/ %s", src_dir, dst_dir);

    printf("Running command: %s\n", command);

    FILE *pipe = popen(command, "r");
    if (!pipe) {
        fprintf(stderr, "Error running command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, pipe) != NULL) {
        printf("%s", buf);
    }

    int status = pclose(pipe);
    if (status == -1) {
        fprintf(stderr, "Error closing pipe: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (WIFEXITED(status)) {
        int exit_code = WEXITSTATUS(status);
        if (exit_code != 0) {
            fprintf(stderr, "Command exited with status %d\n", exit_code);
            exit(EXIT_FAILURE);
        } else {
            printf("Command completed successfully\n");
            exit(EXIT_SUCCESS);
        }
    } else {
        fprintf(stderr, "Command terminated abnormally\n");
        exit(EXIT_FAILURE);
    }
}