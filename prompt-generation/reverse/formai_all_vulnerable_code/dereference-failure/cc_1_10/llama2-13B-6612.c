//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    char *filename = "example.txt";
    int fd;
    char buffer[BUFFER_SIZE];
    off_t file_size;

    // Open the file in read-write mode
    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Error seeking to end of file");
        close(fd);
        return 1;
    }

    // Map the file into memory
    void *map = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    // Write some data to the file
    char *p = (char *)map;
    memset(p, 'A', 100);
    p += 100;
    strcpy(p, "This is a test\n");

    // Unmap the file from memory
    munmap(map, file_size);

    // Close the file
    close(fd);

    // Read the data back from the file
    fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *q = (char *)map;
    size_t bytes_read = read(fd, q, file_size);
    if (bytes_read != file_size) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    // Check that the data is still there
    if (memcmp(q, "This is a test\n", 13)) {
        printf("Data corrupted\n");
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}