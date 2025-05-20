//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILE_NAME "example.txt"

int main() {
    // Create a file with some contents
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    fprintf(file, "This is a test file created by the program.\n");
    fclose(file);

    // Open the file in read-write mode
    file = fopen(FILE_NAME, "r+");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Mmap the file into memory
    void *addr = mmap(NULL, 0, 0, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fileno(file));
    if (addr == MAP_FAILED) {
        perror("Error mmapping file");
        return 1;
    }

    // Modify the contents of the file in memory
    char *ptr = (char *)addr;
    ptr[0] = 'A';
    ptr[1] = 'B';
    ptr[2] = 'C';
    ptr[3] = 'D';

    // Unmap the file from memory
    munmap(addr, 4);

    // Reopen the file and check its contents
    file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    char buffer[4];
    fread(buffer, 1, 4, file);
    printf("File contents: %s\n", buffer);
    fclose(file);

    return 0;
}