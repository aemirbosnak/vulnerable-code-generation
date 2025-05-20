//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(void)
{
    // Open the file in read-write mode
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Map the file into memory
    char *buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    // Read from the file and write to the buffer
    ssize_t read_size = read(fd, buffer, BUFFER_SIZE);
    if (read_size == -1) {
        perror("Error reading from file");
        munmap(buffer, BUFFER_SIZE);
        close(fd);
        return 1;
    }

    // Modify the buffer
    buffer[5] = 'x';

    // Write the modified buffer back to the file
    ssize_t write_size = write(fd, buffer, BUFFER_SIZE);
    if (write_size == -1) {
        perror("Error writing to file");
        munmap(buffer, BUFFER_SIZE);
        close(fd);
        return 1;
    }

    // Unmap the file from memory
    munmap(buffer, BUFFER_SIZE);

    // Close the file
    close(fd);

    return 0;
}