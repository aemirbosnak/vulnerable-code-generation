//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 8192

// Function to synchronize files
void synchronize_files(const char *src_file, const char *dest_file) {
    int src_fd, dest_fd;
    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open source file for reading
    src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    // Open destination file for writing
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    // Loop through source file and write to destination file
    while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buf, bytes_read);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    // Close source and destination files
    close(src_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file> <mode>\n", argv[0]);
        fprintf(stderr, "Modes:\n");
        fprintf(stderr, "  0 - Overwrite destination file\n");
        fprintf(stderr, "  1 - Append to destination file\n");
        exit(1);
    }

    // Get mode from command line argument
    int mode = atoi(argv[3]);

    // Synchronize files
    synchronize_files(argv[1], argv[2]);

    if (mode == 0) {
        fprintf(stdout, "Destination file overwritten with source file.\n");
    } else if (mode == 1) {
        fprintf(stdout, "Source file appended to destination file.\n");
    } else {
        fprintf(stdout, "Invalid mode specified.\n");
    }

    return 0;
}