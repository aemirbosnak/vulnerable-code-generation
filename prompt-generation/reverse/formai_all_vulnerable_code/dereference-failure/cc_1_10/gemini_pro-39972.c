//GEMINI-pro DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a custom data structure to hold file metadata
typedef struct file_metadata {
    char *filename;
    size_t filesize;
    char *filedata;
} file_metadata;

// Function to read a file into memory
file_metadata *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    rewind(file);

    // Allocate memory for the file data
    char *filedata = malloc(filesize + 1);
    if (!filedata) {
        perror("Error allocating memory for file data");
        exit(EXIT_FAILURE);
    }

    // Read the file data into memory
    size_t bytes_read = fread(filedata, 1, filesize, file);
    if (bytes_read != filesize) {
        perror("Error reading file data");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(file);

    // Allocate memory for the file metadata structure
    file_metadata *metadata = malloc(sizeof(file_metadata));
    if (!metadata) {
        perror("Error allocating memory for file metadata");
        exit(EXIT_FAILURE);
    }

    // Initialize the file metadata structure
    metadata->filename = strdup(filename);
    metadata->filesize = filesize;
    metadata->filedata = filedata;

    // Return the file metadata structure
    return metadata;
}

// Function to write a file from memory
void write_file(file_metadata *metadata) {
    FILE *file = fopen(metadata->filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the file data to the file
    size_t bytes_written = fwrite(metadata->filedata, 1, metadata->filesize, file);
    if (bytes_written != metadata->filesize) {
        perror("Error writing file data");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(file);
}

// Function to free the memory allocated for a file metadata structure
void free_file_metadata(file_metadata *metadata) {
    free(metadata->filename);
    free(metadata->filedata);
    free(metadata);
}

// Main function
int main() {
    // Read a file into memory
    file_metadata *metadata = read_file("test.txt");

    // Print the file metadata
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %zu\n", metadata->filesize);

    // Modify the file data
    char *filedata = metadata->filedata;
    for (size_t i = 0; i < metadata->filesize; i++) {
        filedata[i] = toupper(filedata[i]);
    }

    // Write the file back to disk
    write_file(metadata);

    // Free the memory allocated for the file metadata structure
    free_file_metadata(metadata);

    return 0;
}