//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to determine if file exists
bool fileExists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to extract metadata from file
void extractMetadata(const char *filename) {
    FILE *file = NULL;
    
    // Open file for reading in binary mode
    file = fopen(filename, "rb");
    
    // Check if file exists
    if (!fileExists(filename)) {
        printf("Error: File not found.\n");
        return;
    }
    
    // Check if file could be opened for reading
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    // Determine file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    
    // Allocate memory for storing file contents
    char *fileContents = (char*)malloc(sizeof(char) * fileSize);
    
    // Read file contents into memory
    fread(fileContents, sizeof(char), fileSize, file);
    
    // Close file
    fclose(file);
    
    // Extract metadata from fileContents here
    // Example metadata: file name, file size, creation date
    printf("Filename: %s\n", filename);
    printf("File size: %ld bytes\n", fileSize);
    printf("Creation date: not available\n");
    
    // Free allocated memory
    free(fileContents);
}

int main() {
    extractMetadata("example.txt");
    
    return 0;
}