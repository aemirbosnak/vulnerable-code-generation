//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buf;
    return (stat(filename, &buf) == 0);
}

// Function to recover data from a file
int recover_data(const char *filename, const char *output_filename) {
    // Open the input file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // Get the file size
    struct stat buf;
    if (fstat(fd, &buf) == -1) {
        perror("fstat");
        close(fd);
        return -1;
    }

    // Allocate a buffer to store the file contents
    char *buffer = malloc(buf.st_size);
    if (buffer == NULL) {
        perror("malloc");
        close(fd);
        return -1;
    }

    // Read the file contents into the buffer
    if (read(fd, buffer, buf.st_size) != buf.st_size) {
        perror("read");
        close(fd);
        free(buffer);
        return -1;
    }

    // Close the input file
    close(fd);

    // Open the output file
    fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        free(buffer);
        return -1;
    }

    // Write the recovered data to the output file
    if (write(fd, buffer, buf.st_size) != buf.st_size) {
        perror("write");
        close(fd);
        free(buffer);
        return -1;
    }

    // Close the output file
    close(fd);

    // Free the buffer
    free(buffer);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check if the input file exists
    if (!file_exists(argv[1])) {
        fprintf(stderr, "Error: Input file does not exist\n");
        return -1;
    }

    // Check if the output file exists
    if (file_exists(argv[2])) {
        fprintf(stderr, "Error: Output file already exists\n");
        return -1;
    }

    // Recover the data from the input file
    if (recover_data(argv[1], argv[2]) != 0) {
        fprintf(stderr, "Error: Could not recover data\n");
        return -1;
    }

    // Success
    return 0;
}