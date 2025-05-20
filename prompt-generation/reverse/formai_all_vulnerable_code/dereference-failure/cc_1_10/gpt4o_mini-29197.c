//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants to simulate our file structure
#define METADATA_SIZE 10
#define FILE_TYPE_OFFSET 0
#define FILE_SIZE_OFFSET 2
#define WIDTH_OFFSET 6
#define HEIGHT_OFFSET 10

typedef struct {
    char fileType[3];
    unsigned int fileSize;
    unsigned int width;
    unsigned int height;
} Metadata;

// Function prototypes
Metadata extract_metadata(const char *filename);
void print_metadata(const Metadata *metadata);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata metadata = extract_metadata(argv[1]);
    
    // After extracting, print the metadata
    print_metadata(&metadata);

    return EXIT_SUCCESS;
}

// Function to extract metadata from the file
Metadata extract_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    // Read raw bytes into a buffer
    unsigned char buffer[METADATA_SIZE];
    fread(buffer, sizeof(unsigned char), METADATA_SIZE, file);
    fclose(file);

    // Create a Metadata instance and fill it with extracted values
    Metadata metadata;
    strncpy(metadata.fileType, (char *)&buffer[FILE_TYPE_OFFSET], 2);
    metadata.fileType[2] = '\0'; // null-terminate the string
    metadata.fileSize = *(unsigned int *)&buffer[FILE_SIZE_OFFSET];
    metadata.width = *(unsigned int *)&buffer[WIDTH_OFFSET];
    metadata.height = *(unsigned int *)&buffer[HEIGHT_OFFSET];

    return metadata;
}

// Function to print the extracted metadata
void print_metadata(const Metadata *metadata) {
    printf("Extracted Metadata:\n");
    printf("File Type: %s\n", metadata->fileType);
    printf("File Size: %u bytes\n", metadata->fileSize);
    printf("Width: %u pixels\n", metadata->width);
    printf("Height: %u pixels\n", metadata->height);
}