//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Open the input file in read-only mode
    int input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the input file
    struct stat input_file_stat;
    if (fstat(input_fd, &input_file_stat) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to store the contents of the input file
    char *input_buffer = malloc(input_file_stat.st_size);
    if (input_buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the contents of the input file into the buffer
    ssize_t bytes_read = read(input_fd, input_buffer, input_file_stat.st_size);
    if (bytes_read == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Close the input file
    if (close(input_fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    // Open the output file in write-only mode
    int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Write the contents of the buffer to the output file
    ssize_t bytes_written = write(output_fd, input_buffer, bytes_read);
    if (bytes_written == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Close the output file
    if (close(output_fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    // Free the buffer
    free(input_buffer);

    return EXIT_SUCCESS;
}