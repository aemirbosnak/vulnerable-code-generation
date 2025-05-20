//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LEN 1024
#define BUFFER_SIZE 4096

int main() {
    char *filename = "invasive_example.txt";
    char *buffer = malloc(BUFFER_SIZE);
    size_t bytes_read = 0;
    int fd;

    // Open the file in read-write mode
    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Set the file's ownership and permissions
    if (fchown(fd, getuid(), getgid()) == -1) {
        perror("Error setting file ownership");
        close(fd);
        return 1;
    }

    // Set the file's permissions to read-write for the owner and group
    if (fchmod(fd, 0644) == -1) {
        perror("Error setting file permissions");
        close(fd);
        return 1;
    }

    // Map the file into memory
    void *addr = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping file into memory");
        close(fd);
        return 1;
    }

    // Read the file's contents into the buffer
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Error reading file");
        munmap(addr, BUFFER_SIZE);
        close(fd);
        return 1;
    }

    // Truncate the file to zero length
    if (truncate(fd, 0) == -1) {
        perror("Error truncating file");
        munmap(addr, BUFFER_SIZE);
        close(fd);
        return 1;
    }

    // Unmap the file from memory
    munmap(addr, BUFFER_SIZE);

    // Close the file
    close(fd);

    // Print the buffer contents
    printf("Buffer contents: %s\n", buffer);

    return 0;
}