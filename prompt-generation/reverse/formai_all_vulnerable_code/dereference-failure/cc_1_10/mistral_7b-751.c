//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024
#define FILENAME "example.txt"

int main(void) {
    int file_fd;
    char buffer[MAX_BUF_SIZE];
    char *str = "Hello World!";
    size_t len = strlen(str);

    // Open the file in write mode with error checking
    if ((file_fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        fprintf(stderr, "Failed to open file %s: %s\n", FILENAME, strerror(errno));
        exit(1);
    }

    // Write the string to the file with error checking
    if (write(file_fd, str, len) != len) {
        perror("Write error");
        close(file_fd);
        exit(1);
    }

    printf("String %s written to file %s successfully.\n", str, FILENAME);

    // Open the file in read mode with error checking
    if ((file_fd = open(FILENAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Failed to open file %s: %s\n", FILENAME, strerror(errno));
        exit(1);
    }

    // Read the file content into the buffer with error checking
    ssize_t bytes_read;
    if ((bytes_read = read(file_fd, buffer, MAX_BUF_SIZE)) < 0) {
        perror("Read error");
        close(file_fd);
        exit(1);
    }

    // Print the content of the file
    printf("Content of file %s:\n", FILENAME);
    printf("%s\n", buffer);

    // Close the file
    close(file_fd);

    // Remove the file with error checking
    if (unlink(FILENAME) < 0) {
        perror("Failed to remove file");
        exit(1);
    }

    printf("File %s removed successfully.\n", FILENAME);

    return 0;
}