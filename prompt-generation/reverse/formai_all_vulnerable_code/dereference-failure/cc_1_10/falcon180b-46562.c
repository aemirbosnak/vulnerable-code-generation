//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "malloc: %s\n", strerror(errno));
        return 1;
    }

    size_t offset = (st.st_size / BUFFER_SIZE) * BUFFER_SIZE;
    while (offset < st.st_size) {
        ssize_t bytes_read = pread(fd, buffer, BUFFER_SIZE, offset);
        if (bytes_read == -1) {
            perror("pread");
            return 1;
        }

        for (size_t i = 0; i < bytes_read; ++i) {
            if (buffer[i] == '\n') {
                buffer[i] = '\r';
            }
        }

        ssize_t bytes_written = pwrite(fd, buffer, bytes_read, offset);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "pwrite: %s\n", strerror(errno));
            return 1;
        }

        offset += bytes_read;
    }

    free(buffer);
    close(fd);

    return 0;
}