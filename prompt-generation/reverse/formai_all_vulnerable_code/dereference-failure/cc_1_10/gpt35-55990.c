//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int source_fd, dest_fd;
    ssize_t write_count, read_count;
    char buffer[BUFFER_SIZE];

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening %s: %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((read_count = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(dest_fd, buffer, read_count);
        if (write_count != read_count) {
            printf("Error writing to %s: %s\n", argv[2], strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (read_count == -1) {
        printf("Error reading from %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(source_fd) == -1) {
        printf("Error closing %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        printf("Error closing %s: %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("File synchronized from %s to %s.\n", argv[1], argv[2]);

    return 0;
}