//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <temperature sensor file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    char *buf = malloc(statbuf.st_size);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (read(fd, buf, statbuf.st_size) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(fd);

    char *ptr = buf;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            *ptr = '\0';
            fprintf(stdout, "%s\n", buf);
            buf = ptr + 1;
        }
        ptr++;
    }

    free(buf);
    fclose(fp);
    
    return EXIT_SUCCESS;
}