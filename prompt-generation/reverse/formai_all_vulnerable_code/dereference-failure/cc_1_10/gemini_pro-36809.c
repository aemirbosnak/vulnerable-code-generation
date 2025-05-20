//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the source file
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Open the destination file
    int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(fd_src);
        return EXIT_FAILURE;
    }

    // Read the source file in chunks and write it to the destination file
    char buf[BUF_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd_src, buf, BUF_SIZE)) > 0) {
        if (write(fd_dst, buf, bytes_read) != bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            close(fd_src);
            close(fd_dst);
            return EXIT_FAILURE;
        }
    }

    // Check for errors while reading the source file
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        close(fd_src);
        close(fd_dst);
        return EXIT_FAILURE;
    }

    // Close the files
    close(fd_src);
    close(fd_dst);

    return EXIT_SUCCESS;
}