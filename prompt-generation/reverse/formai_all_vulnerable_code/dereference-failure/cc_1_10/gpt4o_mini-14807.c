//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold file metadata
typedef struct {
    char *filename;
    long size;
    char *type;
} FileMetadata;

// Function to get file size
long getFileSize(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Open file in binary mode
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    fseek(file, 0, SEEK_END); // Move to end of file
    long size = ftell(file);  // Get position, which equals size
    fclose(file);
    return size; // Return file size
}

// Function to determine file type
const char *getFileType(const char *filename) {
    const char *dot = strrchr(filename, '.'); // Look for last dot
    if (!dot || dot == filename) return "Unknown"; // No extension found
    if (strcmp(dot, ".txt") == 0) return "Text File";
    else if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0) return "JPEG Image";
    else if (strcmp(dot, ".png") == 0) return "PNG Image";
    else if (strcmp(dot, ".pdf") == 0) return "PDF Document";
    else if (strcmp(dot, ".mp3") == 0) return "Audio File";
    else return "Other"; // For other file types
}

// Function to create file metadata
FileMetadata* createFileMetadata(const char *filename) {
    FileMetadata *metadata = malloc(sizeof(FileMetadata)); // Allocate memory for metadata
    if (!metadata) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    metadata->filename = strdup(filename); // Copy filename to metadata
    metadata->size = getFileSize(filename); // Get file size
    metadata->type = strdup(getFileType(filename)); // Get file type
    return metadata; // Return the allocated metadata
}

// Function to print file metadata
void printFileMetadata(const FileMetadata *metadata) {
    if (metadata) {
        printf("File Name: %s\n", metadata->filename);
        printf("File Size: %ld bytes\n", metadata->size);
        printf("File Type: %s\n\n", metadata->type);
    }
}

// Function to free metadata
void freeFileMetadata(FileMetadata *metadata) {
    if (metadata) {
        free(metadata->filename); // Free the filename string
        free(metadata->type);     // Free the type string
        free(metadata);           // Free the metadata structure itself
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) { // Check for parameters
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE; // Terminate if no files provided
    }

    for (int i = 1; i < argc; i++) {
        FileMetadata *metadata = createFileMetadata(argv[i]); // Create metadata for each file
        printFileMetadata(metadata); // Print the metadata
        freeFileMetadata(metadata); // Free the allocated memory
    }

    return EXIT_SUCCESS; // Return success code
}