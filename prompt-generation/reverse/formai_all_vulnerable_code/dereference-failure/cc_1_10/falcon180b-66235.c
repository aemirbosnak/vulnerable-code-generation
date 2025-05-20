//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

void sync_files(char* source_file, char* dest_file) {
    int source_fd, dest_fd;
    char buffer[BUF_SIZE];
    off_t source_size, dest_size, bytes_copied;

    // Open source file for reading
    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    // Get size of source file
    if (fstat(source_fd, &source_size) == -1) {
        fprintf(stderr, "Error getting size of source file: %s\n", strerror(errno));
        exit(1);
    }

    // Open destination file for writing
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    // Get size of destination file
    if (fstat(dest_fd, &dest_size) == -1) {
        fprintf(stderr, "Error getting size of destination file: %s\n", strerror(errno));
        exit(1);
    }

    // Check if files are already in sync
    if (source_size == dest_size) {
        fprintf(stdout, "Files are already in sync.\n");
        exit(0);
    }

    // Copy contents of source file to destination file
    while ((bytes_copied = read(source_fd, buffer, BUF_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_copied)!= bytes_copied) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (bytes_copied == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        exit(1);
    }

    close(source_fd);
    close(dest_fd);

    fprintf(stdout, "Files synchronized successfully.\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}