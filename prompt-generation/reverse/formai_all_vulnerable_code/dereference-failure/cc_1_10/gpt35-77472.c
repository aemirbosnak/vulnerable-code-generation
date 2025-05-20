//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(const char* message) {
    fprintf(stderr, "Error detected: %s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    FILE* file;
    char* buffer;
    long size;
    
    // Open the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        handle_error("Failed to open file");
    }
    
    // Get the size of the file
    if (fseek(file, 0, SEEK_END) == -1) {
        handle_error("Failed to seek to end of file");
    }
    size = ftell(file);
    if (size == -1) {
        handle_error("Failed to get size of file");
    }
    rewind(file);
    
    // Allocate memory for the buffer
    buffer = (char*) malloc(size);
    if (buffer == NULL) {
        handle_error("Failed to allocate memory");
    }
    
    // Read the file into the buffer
    if (fread(buffer, sizeof(char), size, file) != size) {
        handle_error("Failed to read file into buffer");
    }
    
    // Close the file
    if (fclose(file) == EOF) {
        handle_error("Failed to close file");
    }
    
    // Print the contents of the buffer
    printf("%s", buffer);
    
    // Free the memory allocated for the buffer
    free(buffer);
    
    return 0;
}