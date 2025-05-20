//GEMINI-pro DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to securely read a file
int secure_read_file(const char *filename, char **buffer) {
    int fd;
    struct stat file_stat;
    int ret;

    // Open the file in read-only mode
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return -1;
    }

    // Get the file size
    ret = fstat(fd, &file_stat);
    if (ret == -1) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    // Allocate a buffer to hold the file contents
    *buffer = malloc(file_stat.st_size + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    // Read the file contents into the buffer
    ret = read(fd, *buffer, file_stat.st_size);
    if (ret == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        free(*buffer);
        close(fd);
        return -1;
    }

    // Null-terminate the buffer
    (*buffer)[file_stat.st_size] = '\0';

    // Close the file
    close(fd);

    return 0;
}

// Function to securely write a file
int secure_write_file(const char *filename, const char *buffer, size_t size) {
    int fd;
    struct stat file_stat;
    int ret;

    // Open the file in write-only mode, creating it if necessary
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return -1;
    }

    // Get the file size
    ret = fstat(fd, &file_stat);
    if (ret == -1) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    // Write the buffer to the file
    ret = write(fd, buffer, size);
    if (ret == -1) {
        fprintf(stderr, "Error writing file: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    // Close the file
    close(fd);

    return 0;
}

// Main function
int main() {
    char *buffer;
    int ret;

    // Read the file "input.txt" securely
    ret = secure_read_file("input.txt", &buffer);
    if (ret == -1) {
        fprintf(stderr, "Error reading file\n");
        return EXIT_FAILURE;
    }

    // Process the file contents...

    // Write the modified file contents to "output.txt" securely
    ret = secure_write_file("output.txt", buffer, strlen(buffer));
    if (ret == -1) {
        fprintf(stderr, "Error writing file\n");
        return EXIT_FAILURE;
    }

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}