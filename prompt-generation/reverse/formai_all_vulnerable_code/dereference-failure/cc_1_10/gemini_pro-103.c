//GEMINI-pro DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        err(EXIT_FAILURE, "open");
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        err(EXIT_FAILURE, "fstat");
    }

    if (!S_ISREG(sb.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *buf = malloc(sb.st_size);
    if (buf == NULL) {
        err(EXIT_FAILURE, "malloc");
    }

    if (read(fd, buf, sb.st_size) != sb.st_size) {
        err(EXIT_FAILURE, "read");
    }

    close(fd);

    for (int i = 0; i < sb.st_size; i++) {
        buf[i] ^= 0xFF;
    }

    fd = open(argv[1], O_WRONLY | O_TRUNC);
    if (fd == -1) {
        err(EXIT_FAILURE, "open");
    }

    if (write(fd, buf, sb.st_size) != sb.st_size) {
        err(EXIT_FAILURE, "write");
    }

    close(fd);

    free(buf);

    return EXIT_SUCCESS;
}