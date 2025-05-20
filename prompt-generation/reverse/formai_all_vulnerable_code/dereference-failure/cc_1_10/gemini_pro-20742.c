//GEMINI-pro DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
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

    if (!S_ISREG(statbuf.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
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

    for (int i = 0; i < statbuf.st_size; i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            printf("%s\n", buf);
            buf += i + 1;
            i = -1;
        }
    }

    if (statbuf.st_size > 0) {
        printf("%s\n", buf);
    }

    free(buf);

    return EXIT_SUCCESS;
}