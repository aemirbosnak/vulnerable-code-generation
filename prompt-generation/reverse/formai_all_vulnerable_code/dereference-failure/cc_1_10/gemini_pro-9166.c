//GEMINI-pro DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    // Open the file for reading
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the file size
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer
    if (read(fd, buffer, statbuf.st_size) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    // Process the file contents
    // ...

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}