//GEMINI-pro DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the file size
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to hold the file contents
    char *buf = malloc(file_stat.st_size);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer
    ssize_t bytes_read = read(fd, buf, file_stat.st_size);
    if (bytes_read == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    // Print the file contents to the standard output
    printf("%s", buf);

    // Free the buffer
    free(buf);

    return EXIT_SUCCESS;
}