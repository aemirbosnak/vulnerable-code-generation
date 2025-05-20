//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main() {
    // Open the file in read-only mode
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Check if the file exists
    if (access(fd, F_OK) == -1) {
        perror("File does not exist");
        close(fd);
        return 1;
    }

    // Get the file size
    off_t filesize = lseek(fd, 0, SEEK_END);
    if (filesize == -1) {
        perror("Error seeking to end of file");
        close(fd);
        return 1;
    }

    // Allocate memory for the file
    char* buffer = mmap(NULL, filesize, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    // Read the file into the allocated memory
    size_t bytes_read = read(fd, buffer, filesize);
    if (bytes_read != filesize) {
        perror("Error reading file");
        munmap(buffer, filesize);
        close(fd);
        return 1;
    }

    // Print the contents of the file
    printf("File contents: %s\n", buffer);

    // Unmap the memory
    munmap(buffer, filesize);

    // Close the file
    close(fd);

    return 0;
}