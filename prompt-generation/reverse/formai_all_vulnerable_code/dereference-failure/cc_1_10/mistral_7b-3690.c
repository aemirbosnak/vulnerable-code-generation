//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Metadata structure for a custom image file format
typedef struct {
    char magic_number[4];          // First 4 bytes: "IMG" or "IMDG" for data or metadata
    unsigned int width;            // Width of the image
    unsigned int height;           // Height of the image
    char data_or_metadata[1];      // Flag: 'D' for data, 'M' for metadata
} ImageMetadata;

// Function to extract metadata from an image file
ImageMetadata extract_metadata(FILE *file) {
    ImageMetadata metadata;
    fread(metadata.magic_number, sizeof(char), 4, file);

    // Check if it's a valid image file format
    if (strncmp(metadata.magic_number, "IMG\0", 4) && strncmp(metadata.magic_number, "IMDG\0", 4)) {
        fprintf(stderr, "Invalid image file format.\n");
        exit(EXIT_FAILURE);
    }

    fread(&metadata.width, sizeof(unsigned int), 1, file);
    fread(&metadata.height, sizeof(unsigned int), 1, file);
    fread(&metadata.data_or_metadata, sizeof(char), 1, file);

    return metadata;
}

// Function to print metadata information
void print_metadata(ImageMetadata metadata) {
    printf("Image Metadata:\n");
    printf("Magic Number: %s\n", metadata.magic_number);
    printf("Width: %u\n", metadata.width);
    printf("Height: %u\n", metadata.height);
    printf("Type: %s\n", metadata.data_or_metadata == 'D' ? "Data" : "Metadata");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ImageMetadata metadata = extract_metadata(file);
    print_metadata(metadata);

    fclose(file);
    return EXIT_SUCCESS;
}