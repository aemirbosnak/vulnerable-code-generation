//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Custom error handling function
void my_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    // Open input file for reading
    int fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) my_error("Can't open input file");

    // Get file size
    struct stat file_stat;
    if (fstat(fd_in, &file_stat) == -1) my_error("Can't get file size");

    // Allocate memory for input buffer
    char *buffer = (char *) malloc(file_stat.st_size);
    if (!buffer) my_error("Can't allocate memory for input buffer");

    // Read input file into buffer
    ssize_t bytes_read = read(fd_in, buffer, file_stat.st_size);
    if (bytes_read != file_stat.st_size) my_error("Error reading input file");

    // Close input file
    close(fd_in);

    // Open output file for writing
    int fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out == -1) my_error("Can't open output file");

    // Write buffer to output file
    if (write(fd_out, buffer, file_stat.st_size) != file_stat.st_size) my_error("Error writing output file");

    // Close output file
    close(fd_out);

    // Free memory
    free(buffer);

    printf("Copied %ld bytes from %s to %s.\n", (long int) file_stat.st_size, argv[1], argv[2]);

    return 0;
}