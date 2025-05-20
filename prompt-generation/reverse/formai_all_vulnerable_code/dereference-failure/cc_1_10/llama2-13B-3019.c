//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    // Example 1: Reading and Writing to a File
    // Open a file in binary mode
    FILE *file = fopen("example_file.txt", "rb+");

    // Check if the file exists
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read from the file
    char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file);

    // Print the contents of the buffer
    printf("Contents of the file before modifying: %s\n", buffer);

    // Modify the contents of the file
    buffer[10] = 'A';

    // Write the modified contents back to the file
    size_t bytes_written = fwrite(buffer, 1, BUFFER_SIZE, file);

    // Check if the write operation was successful
    if (bytes_written != BUFFER_SIZE) {
        perror("Error writing to file");
        return 2;
    }

    // Close the file
    fclose(file);

    // Example 2: Mapping a File into Memory
    // Open the same file in binary mode
    file = fopen("example_file.txt", "rb+");

    // Mmap the file into memory
    void *mapped_file = mmap(NULL, 0, 0, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fileno(file));

    // Check if the mmap operation was successful
    if (mapped_file == MAP_FAILED) {
        perror("Error mapping file into memory");
        return 3;
    }

    // Modify the contents of the file in memory
    buffer[10] = 'A';

    // Unmap the file from memory
    munmap(mapped_file, 0);

    // Close the file
    fclose(file);

    return 0;
}