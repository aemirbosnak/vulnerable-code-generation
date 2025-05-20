//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a metadata block
typedef struct {
    int type;
    int length;
    char *data;
} MetadataBlock;

// Function to extract metadata blocks from a file
void extractMetadata(FILE *file, MetadataBlock **metadata, int *metadataCount) {
    // Initialize metadata array
    MetadataBlock *tempMetadata = NULL;
    int tempMetadataCount = 0;

    // Read file header to determine metadata type and length
    int type, length;
    fread(&type, sizeof(int), 1, file);
    fread(&length, sizeof(int), 1, file);

    // Allocate memory for metadata block
    tempMetadata = realloc(tempMetadata, sizeof(MetadataBlock) * tempMetadataCount + 1);
    tempMetadata[tempMetadataCount].type = type;
    tempMetadata[tempMetadataCount].length = length;
    tempMetadata[tempMetadataCount].data = malloc(length * sizeof(char));

    // Read metadata data
    fread(tempMetadata[tempMetadataCount].data, sizeof(char), length, file);

    // Add metadata block to array
    tempMetadataCount++;
    *metadata = tempMetadata;
    *metadataCount = tempMetadataCount;
}

// Function to print metadata blocks
void printMetadata(MetadataBlock *metadata, int metadataCount) {
    for (int i = 0; i < metadataCount; i++) {
        printf("Type: %d\n", metadata[i].type);
        printf("Length: %d\n", metadata[i].length);
        printf("Data: ");
        for (int j = 0; j < metadata[i].length; j++) {
            printf("%c", metadata[i].data[j]);
        }
        printf("\n");
    }
}

int main() {
    // Open input file
    FILE *inputFile = fopen("input.file", "rb");

    // Check if input file is valid
    if (inputFile == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    // Initialize metadata array and count
    MetadataBlock *metadata = NULL;
    int metadataCount = 0;

    // Extract metadata blocks from file
    extractMetadata(inputFile, &metadata, &metadataCount);

    // Print extracted metadata
    printf("Metadata:\n");
    printMetadata(metadata, metadataCount);

    // Free memory allocated for metadata blocks
    for (int i = 0; i < metadataCount; i++) {
        free(metadata[i].data);
    }
    free(metadata);

    // Close input file
    fclose(inputFile);

    return 0;
}