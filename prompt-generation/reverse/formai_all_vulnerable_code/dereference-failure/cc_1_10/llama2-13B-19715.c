//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main() {
    // Example 1: Reading and Writing to a File
    char filename[] = "example_file.txt";
    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write some data to the file
    fprintf(file, "This is a sample file written by C programming.\n");
    fclose(file);

    // Example 2: Reading from a File
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read some data from the file
    char buffer[BUFFER_SIZE];
    fread(buffer, 1, BUFFER_SIZE, file);
    printf("Read data: %s\n", buffer);
    fclose(file);

    // Example 3: Append to a File
    file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write some data to the end of the file
    fprintf(file, "This is an append operation.\n");
    fclose(file);

    // Example 4: Mapping a File to Memory
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Map the file to memory
    void *addr = mmap(NULL, 0, 0, PROT_READ, MAP_FILE | MAP_PRIVATE, file);
    if (addr == MAP_FAILED) {
        perror("Error mapping file to memory");
        return 1;
    }

    // Read data from the mapped memory
    char *mem = addr;
    printf("Memory contents: %s\n", mem);

    // Unmap the memory
    munmap(addr, 0);

    return 0;
}