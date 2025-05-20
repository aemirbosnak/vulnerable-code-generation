//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// Define a custom metadata structure
typedef struct {
    uint64_t timestamp;
    char *author;
    char *description;
} Metadata;

// Extract metadata from a file
Metadata extract_metadata(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file header
    uint64_t magic_number;
    fread(&magic_number, sizeof(uint64_t), 1, fp);
    if (magic_number != 0xDEADBEEF) {
        fprintf(stderr, "Error: Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    // Read the metadata
    Metadata metadata;
    fread(&metadata.timestamp, sizeof(uint64_t), 1, fp);
    fread(&metadata.author, sizeof(char *), 1, fp);
    fread(&metadata.description, sizeof(char *), 1, fp);

    // Close the file
    fclose(fp);

    return metadata;
}

// Print metadata to the console
void print_metadata(const Metadata *metadata) {
    printf("Timestamp: %" PRIu64 "\n", metadata->timestamp);
    printf("Author: %s\n", metadata->author);
    printf("Description: %s\n", metadata->description);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Metadata metadata = extract_metadata(argv[1]);
    print_metadata(&metadata);

    free(metadata.author);
    free(metadata.description);

    return EXIT_SUCCESS;
}