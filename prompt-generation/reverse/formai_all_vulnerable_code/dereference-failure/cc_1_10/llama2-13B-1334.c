//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define MAX_BUFFER 1024

int main() {
    char* filename = "example.txt";
    char* buffer = "Hello, world!";
    size_t buffer_size = strlen(buffer);
    int fd;

    // Open file in write-only mode
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write buffer to file
    write(fd, buffer, buffer_size);

    // Flush buffer to file
    fsync(fd);

    // Close file
    close(fd);

    // Read file
    fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read buffer from file
    char* read_buffer = malloc(buffer_size);
    read(fd, read_buffer, buffer_size);

    // Check if read buffer is equal to write buffer
    if (strcmp(buffer, read_buffer) != 0) {
        printf("Read buffer does not match write buffer\n");
        return 1;
    }

    // Close file
    close(fd);

    return 0;
}