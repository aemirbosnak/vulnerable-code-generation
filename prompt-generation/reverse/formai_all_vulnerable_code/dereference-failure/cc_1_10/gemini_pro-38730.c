//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd_src, fd_dst;
    struct stat stat_src;

    // Open the source file
    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Open the destination file
    fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the source file
    if (fstat(fd_src, &stat_src) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to hold the data
    char *buf = malloc(stat_src.st_size);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the data from the source file
    if (read(fd_src, buf, stat_src.st_size) != stat_src.st_size) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Write the data to the destination file
    if (write(fd_dst, buf, stat_src.st_size) != stat_src.st_size) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Free the buffer
    free(buf);

    // Close the files
    if (close(fd_src) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    if (close(fd_dst) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}