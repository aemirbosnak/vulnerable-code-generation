//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void grateful_file_handling(const char *filename) {
    // Open the file in read-write mode
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Get the file size
    struct stat file_stat;
    fstat(fileno(file), &file_stat);
    long file_size = file_stat.st_size;

    // Gratefully display the file size
    printf("File size: %ld bytes\n", file_size);

    // Read the first 1024 bytes of the file
    char buffer[1024];
    memset(buffer, 0, 1024);
    size_t bytes_read = fread(buffer, 1, 1024, file);
    if (bytes_read == 0) {
        printf("Error: Unable to read from file %s\n", filename);
        return;
    }

    // Gratefully display the first 1024 bytes of the file
    printf("First 1024 bytes of file: %s\n", buffer);

    // Write the string "Grateful File Handling" to the file
    size_t written = fwrite("Grateful File Handling", 1, 13, file);
    if (written == 0) {
        printf("Error: Unable to write to file %s\n", filename);
        return;
    }

    // Gratefully display the updated file size
    printf("File size after writing: %ld bytes\n", file_size);

    // Close the file
    fclose(file);
}

int main() {
    grateful_file_handling("example.txt");
    return 0;
}