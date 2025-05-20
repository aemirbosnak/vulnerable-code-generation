//GEMINI-pro DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    // Check if the user provided enough arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the filename from the command line arguments.
    char *filename = argv[1];

    // Open the file for reading.
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the file size.
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to hold the file contents.
    char *buffer = malloc(st.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer.
    if (read(fd, buffer, st.st_size) != st.st_size) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Close the file.
    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    // Print the file contents to the standard output.
    printf("%s", buffer);

    // Free the buffer.
    free(buffer);

    return EXIT_SUCCESS;
}