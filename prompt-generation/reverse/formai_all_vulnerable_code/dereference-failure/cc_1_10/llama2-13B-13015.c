//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(void)
{
    // Open a file in read-write mode
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    long file_size = ftell(file);
    if (file_size < 0) {
        perror("Error getting file size");
        return 1;
    }

    // Allocate memory for the file
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Read the file into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read < file_size) {
        perror("Error reading file");
        return 1;
    }

    // Mmap the buffer to create a file in memory
    int fd = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fileno(file), 0);
    if (fd == -1) {
        perror("Error mmapping file");
        return 1;
    }

    // Modify the file in memory
    char *ptr = buffer;
    size_t len = strcspn(ptr, "\n");
    ptr[len] = '*';

    // Unmap the file from memory
    munmap(buffer, file_size);

    // Close the file
    fclose(file);

    // Print the modified file to the console
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fwrite(buffer, 1, file_size, out);
    fclose(out);

    return 0;
}