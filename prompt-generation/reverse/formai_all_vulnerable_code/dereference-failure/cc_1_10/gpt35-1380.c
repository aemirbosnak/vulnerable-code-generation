//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    // Check if file exists
    struct stat buffer;
    if (stat(filename, &buffer) != 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Get file permissions
    int permissions = buffer.st_mode & ~(S_IFMT);
    printf("File permissions: %o\n", permissions);

    // Change file permissions to read only
    if (chmod(filename, S_IRUSR | S_IRGRP) != 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("File is now read only.\n");
    
    // Read first line of file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buf[512];
    ssize_t bytes_read = read(fd, buf, sizeof(buf));
    if (bytes_read == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(fd);
        exit(EXIT_FAILURE);
    }
    buf[bytes_read] = '\0';
    printf("First line of file: %s\n", buf);

    // Append a line to the file
    const char *line = "This is a new line.";
    if (write(fd, line, strlen(line)) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Added new line to file.\n");

    // Close file
    if (close(fd) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Delete file
    if (unlink(filename) != 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("File deleted.\n");
    
    return 0;
}