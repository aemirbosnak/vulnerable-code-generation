//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// File synchronizer function
void sync_files(char *source, char *destination) {
    // Open source file
    int fd_source = open(source, O_RDONLY);
    if (fd_source < 0) {
        perror("open source file");
        exit(1);
    }

    // Get source file size
    struct stat st_source;
    if (fstat(fd_source, &st_source) < 0) {
        perror("fstat source file");
        exit(1);
    }

    // Open destination file
    int fd_destination = open(destination, O_WRONLY | O_CREAT, st_source.st_mode);
    if (fd_destination < 0) {
        perror("open destination file");
        exit(1);
    }

    // Allocate buffer
    char *buffer = malloc(st_source.st_size);
    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    // Read source file
    ssize_t bytes_read = read(fd_source, buffer, st_source.st_size);
    if (bytes_read < 0) {
        perror("read source file");
        exit(1);
    }

    // Write destination file
    ssize_t bytes_written = write(fd_destination, buffer, st_source.st_size);
    if (bytes_written < 0) {
        perror("write destination file");
        exit(1);
    }

    // Free buffer
    free(buffer);

    // Close files
    close(fd_source);
    close(fd_destination);

    printf("Files synchronized successfully.\n");
}

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    // Synchronize files
    sync_files(argv[1], argv[2]);

    return 0;
}