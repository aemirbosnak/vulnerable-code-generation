//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// Buffers
#define BUFFER_SIZE 1024

// File permissions 
#define FILE_PERMISSIONS 0644

// Helper function to check if a file exists given a path
int file_exists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0);
}

// Helper function to copy a file from source to destination
int copy_file(const char *source, const char *destination) {
    int source_fd, destination_fd;
    int bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open source file in read mode
    source_fd = open(source, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return -1;
    }

    // Open destination file in write mode
    destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
    if (destination_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return -1;
    }

    // Read from source file and write to destination file until the source file is empty
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(destination_fd);
            return -1;
        }
    }

    // Close both files
    close(source_fd);
    close(destination_fd);

    return 0;
}

// Helper function to compare two files and return true if they are different
int compare_files(const char *file1, const char *file2) {
    int file1_fd, file2_fd;
    int bytes_read1, bytes_read2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];

    // Open both files in read mode
    file1_fd = open(file1, O_RDONLY);
    if (file1_fd == -1) {
        fprintf(stderr, "Error opening file1: %s\n", strerror(errno));
        return -1;
    }

    file2_fd = open(file2, O_RDONLY);
    if (file2_fd == -1) {
        fprintf(stderr, "Error opening file2: %s\n", strerror(errno));
        close(file1_fd);
        return -1;
    }

    // Read from both files and compare the content until one of the files is empty
    while ((bytes_read1 = read(file1_fd, buffer1, BUFFER_SIZE)) > 0 && (bytes_read2 = read(file2_fd, buffer2, BUFFER_SIZE)) > 0) {
        if (bytes_read1 != bytes_read2 || memcmp(buffer1, buffer2, bytes_read1) != 0) {
            close(file1_fd);
            close(file2_fd);
            return 1;
        }
    }

    // If the files are of different sizes, they are also different
    if (bytes_read1 != bytes_read2) {
        close(file1_fd);
        close(file2_fd);
        return 1;
    }

    // Close both files
    close(file1_fd);
    close(file2_fd);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Check if the source file exists
    if (!file_exists(argv[1])) {
        fprintf(stderr, "Source file does not exist: %s\n", argv[1]);
        return 1;
    }

    // Check if the destination file exists and is different from the source file
    if (file_exists(argv[2]) && !compare_files(argv[1], argv[2])) {
        fprintf(stderr, "Destination file already exists and is up to date: %s\n", argv[2]);
        return 1;
    }

    // Copy the source file to the destination file
    if (copy_file(argv[1], argv[2]) == -1) {
        fprintf(stderr, "Error copying file: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}