//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 256
#define MAX_FILE_SIZE 100000

// Structure to store file information
typedef struct {
    char name[MAX_NAME_LENGTH];
    long size;
} file_info_t;

// Function to read file information
file_info_t read_file_info(const char *filename) {
    file_info_t fi;
    int fd;
    struct stat stat_info;

    // Open the file in read mode
    fd = open(filename, O_RDONLY, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return fi;
    }

    // Get file size and name
    if (fstat(fd, &stat_info) == -1) {
        perror("Error getting file size and name");
        close(fd);
        return fi;
    }

    fi.size = stat_info.st_size;
    strncpy(fi.name, filename, MAX_NAME_LENGTH);

    close(fd);

    return fi;
}

// Function to write file information
void write_file_info(const char *filename, file_info_t fi) {
    int fd;
    struct stat stat_info;

    // Open the file in write mode
    fd = open(filename, O_RDWR, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Get file size and name
    if (fstat(fd, &stat_info) == -1) {
        perror("Error getting file size and name");
        close(fd);
        return;
    }

    // Check if file size is within limit
    if (fi.size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds limit\n");
        close(fd);
        return;
    }

    // Write file information
    strncpy(filename, fi.name, MAX_NAME_LENGTH);
    printf("File name: %s\n", filename);
    printf("File size: %ld\n", fi.size);

    // Close the file
    close(fd);
}

int main() {
    file_info_t fi;

    // Read file information
    fi = read_file_info("example.txt");
    if (fi.size == -1) {
        perror("Error reading file information");
        return 1;
    }

    // Write file information
    write_file_info("example2.txt", fi);

    return 0;
}