//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Function to compare two files
int compareFiles(char *file1, char *file2) {
    // Open the two files
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);

    // Get the file sizes
    struct stat stat1;
    struct stat stat2;
    fstat(fd1, &stat1);
    fstat(fd2, &stat2);

    // Check if the file sizes are the same
    if (stat1.st_size != stat2.st_size) {
        return 0;
    }

    // Read the files into buffers
    char *buf1 = malloc(stat1.st_size);
    char *buf2 = malloc(stat2.st_size);
    read(fd1, buf1, stat1.st_size);
    read(fd2, buf2, stat2.st_size);

    // Compare the buffers
    int cmp = memcmp(buf1, buf2, stat1.st_size);

    // Free the buffers
    free(buf1);
    free(buf2);

    // Close the files
    close(fd1);
    close(fd2);

    // Return the result of the comparison
    return cmp;
}

// Function to synchronize two files
void synchronizeFiles(char *file1, char *file2) {
    // Open the two files
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_WRONLY | O_TRUNC | O_CREAT, 0644);

    // Get the file sizes
    struct stat stat1;
    fstat(fd1, &stat1);

    // Read the file into a buffer
    char *buf = malloc(stat1.st_size);
    read(fd1, buf, stat1.st_size);

    // Write the buffer to the second file
    write(fd2, buf, stat1.st_size);

    // Free the buffer
    free(buf);

    // Close the files
    close(fd1);
    close(fd2);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments has been provided
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Check if the first file exists
    if (access(argv[1], F_OK) == -1) {
        printf("Error: File %s does not exist.\n", argv[1]);
        return 1;
    }

    // Check if the second file exists
    if (access(argv[2], F_OK) == -1) {
        printf("Error: File %s does not exist.\n", argv[2]);
        return 1;
    }

    // Compare the two files
    int cmp = compareFiles(argv[1], argv[2]);

    // If the files are different, synchronize them
    if (cmp != 0) {
        printf("Files are different. Synchronizing...\n");
        synchronizeFiles(argv[1], argv[2]);
    } else {
        printf("Files are the same.\n");
    }

    return 0;
}