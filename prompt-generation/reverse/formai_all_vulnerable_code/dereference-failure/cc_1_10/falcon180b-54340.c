//Falcon-180B DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file> <offset>\n", argv[0]);
        exit(1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    long offset = strtol(argv[3], NULL, 10);
    if (offset < 0) {
        fprintf(stderr, "Invalid offset\n");
        exit(1);
    }

    char buffer[4096];
    memset(buffer, '\0', 4096);

    long bytes_to_copy = 0;
    long bytes_copied = 0;
    long bytes_skipped = 0;

    while (bytes_to_copy < offset) {
        ssize_t bytes_read = read(src_fd, buffer, 4096);
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading source file: %s\n", strerror(errno));
            exit(1);
        }

        if (bytes_read == 0) {
            break;
        }

        bytes_to_copy += bytes_read;
    }

    ssize_t bytes_written;
    while ((bytes_written = write(dest_fd, buffer, 4096))!= -1) {
        if (bytes_written == 0) {
            break;
        }

        bytes_copied += bytes_written;
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}