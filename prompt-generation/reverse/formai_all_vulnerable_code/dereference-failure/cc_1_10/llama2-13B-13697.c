//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1024 * 1024 * 10

int main(void)
{
    // Open the file in read-write mode
    FILE *file = fopen("invasive_file.txt", "r+");
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

    // Map the file into memory
    char *map = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, -1, 0);
    if (map == MAP_FAILED) {
        perror("Error mapping file");
        return 1;
    }

    // Set the file position to the beginning
    rewind(file);

    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Modify the line in place
        char *ptr = strchr(line, ' ');
        if (ptr != NULL) {
            *ptr = '*';
        }
    }

    // Unmap the file from memory
    munmap(map, file_size);

    // Close the file
    fclose(file);

    return 0;
}