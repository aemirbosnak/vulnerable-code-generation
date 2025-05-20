//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    int input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct stat input_stat;
    if (fstat(input_fd, &input_stat) == -1) {
        fprintf(stderr, "Error getting input file stats: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *input_buffer = malloc(input_stat.st_size);
    if (input_buffer == NULL) {
        fprintf(stderr, "Error allocating memory for input buffer: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (read(input_fd, input_buffer, input_stat.st_size) == -1) {
        fprintf(stderr, "Error reading input file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(input_fd);

    int num_bytes_written = write(output_fd, input_buffer, input_stat.st_size);
    if (num_bytes_written == -1) {
        fprintf(stderr, "Error writing to output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(output_fd);

    free(input_buffer);

    return EXIT_SUCCESS;
}