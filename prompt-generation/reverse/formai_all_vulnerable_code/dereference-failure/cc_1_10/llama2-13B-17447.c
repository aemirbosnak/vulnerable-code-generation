//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

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
    struct stat file_stat;
    fstat(fileno(file), &file_stat);
    long file_size = file_stat.st_size;

    // Map the file into memory
    char *file_content = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fileno(file), 0);
    if (file_content == MAP_FAILED) {
        perror("Error mapping file");
        return 1;
    }

    // Write some data to the file
    char *p = file_content;
    for (int i = 0; i < 10; i++) {
        p[i] = 'A' + (i % 2);
    }

    // Unmap the file from memory
    munmap(file_content, file_size);

    // Close the file
    fclose(file);

    // Open the file again in read-only mode
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read data from the file
    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}