//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input-file> <output-file>\n", argv[0]);
        return 1;
    }

    int fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        return 1;
    }

    int fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("open");
        return 1;
    }

    struct stat statbuf;
    if (fstat(fd_in, &statbuf) == -1) {
        perror("fstat");
        return 1;
    }

    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    ssize_t bytes_read = read(fd_in, buffer, statbuf.st_size);
    if (bytes_read == -1) {
        perror("read");
        return 1;
    }

    ssize_t bytes_written = write(fd_out, buffer, bytes_read);
    if (bytes_written == -1) {
        perror("write");
        return 1;
    }

    free(buffer);
    close(fd_in);
    close(fd_out);

    return 0;
}