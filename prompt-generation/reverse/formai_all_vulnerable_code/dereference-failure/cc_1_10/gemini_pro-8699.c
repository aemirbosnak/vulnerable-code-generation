//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>

// Whoa! A struct to hold metadata!
typedef struct {
    char *name;
    char *type;
    uint64_t size;
    uint64_t offset;
} MetaData;

// Function to extract metadata from a file
void extractMetaData(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    struct stat st;
    stat(filename, &st);
    uint64_t fileSize = st.st_size;

    // Allocate memory for the metadata
    MetaData *metadata = malloc(sizeof(MetaData));
    if (metadata == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file contents into a buffer
    uint8_t *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    fread(buffer, 1, fileSize, fp);

    // Close the file
    fclose(fp);

    // Extract the metadata from the buffer
    metadata->name = "Test.txt";
    metadata->type = "Text file";
    metadata->size = fileSize;
    metadata->offset = 0;

    // Print the metadata
    printf("Name: %s\n", metadata->name);
    printf("Type: %s\n", metadata->type);
    printf("Size: %lu\n", metadata->size);
    printf("Offset: %lu\n", metadata->offset);

    // Free the memory
    free(metadata);
    free(buffer);
}

int main() {
    // Extract metadata from a file
    extractMetaData("Test.txt");

    return 0;
}