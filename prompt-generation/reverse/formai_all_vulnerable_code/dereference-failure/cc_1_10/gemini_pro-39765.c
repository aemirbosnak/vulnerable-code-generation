//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

typedef struct {
    int fd;
    char *buf;
    size_t len;
} cat_file;

void cat_async(cat_file *file) {
    ssize_t n;

    while ((n = read(file->fd, file->buf, file->len)) > 0) {
        write(STDOUT_FILENO, file->buf, n);
    }

    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int i;
    cat_file *files;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    files = malloc(sizeof(cat_file) * argc);
    if (files == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < argc; i++) {
        files[i].fd = open(argv[i], O_RDONLY);
        if (files[i].fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        files[i].len = lseek(files[i].fd, 0, SEEK_END);
        if (files[i].len == -1) {
            perror("lseek");
            exit(EXIT_FAILURE);
        }

        files[i].buf = malloc(files[i].len);
        if (files[i].buf == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        lseek(files[i].fd, 0, SEEK_SET);
    }

    for (i = 0; i < argc; i++) {
        cat_async(&files[i]);
    }

    for (i = 0; i < argc; i++) {
        free(files[i].buf);
        close(files[i].fd);
    }

    free(files);

    return 0;
}