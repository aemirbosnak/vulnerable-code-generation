//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define CHUNK 1024

static int cpfile(char *f1, char *f2, char *f3)
{
    int fd1, fd2, fd3;
    int n, e;
    char buf[CHUNK];

    fd1 = open(f1, O_RDONLY);
    if (fd1 < 0) {
        perror("open");
        return -1;
    }

    fd2 = open(f2, O_RDONLY);
    if (fd2 < 0) {
        perror("open");
        return -1;
    }

    fd3 = open(f3, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd3 < 0) {
        perror("open");
        return -1;
    }

    while ((n = read(fd1, buf, CHUNK)) > 0) {
        if (write(fd3, buf, n) < 0) {
            perror("write");
            return -1;
        }
    }
    e = errno;
    if (n < 0) {
        perror("read");
        return -1;
    }

    while ((n = read(fd2, buf, CHUNK)) > 0) {
        if (write(fd3, buf, n) < 0) {
            perror("write");
            return -1;
        }
    }
    errno = e;
    if (n < 0) {
        perror("read");
        return -1;
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}

int main(int argc, char *argv[])
{
    int i;

    if (argc < 4) {
        fprintf(stderr, "usage: %s file1 file2 file3\n", argv[0]);
        return 1;
    }

    for (i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-") == 0) {
            fprintf(stderr, "usage: %s file1 file2 file3\n", argv[0]);
            return 1;
        }
    }

    if (cpfile(argv[1], argv[2], argv[3]) < 0) {
        return 1;
    }

    return 0;
}