//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 256

// Function to read the JPEG file and extract metadata
void extract_jpeg_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    unsigned char buffer[2];
    fseek(file, 0, SEEK_SET);

    // Read through the JPEG file to find the Exif segment
    while (fread(buffer, 1, 2, file) == 2) {
        if (buffer[0] == 0xFF && buffer[1] == 0xE1) { // APP1 marker
            // Found the Exif segment, read its length
            unsigned short length;
            fread(&length, 2, 1, file);
            length = ntohs(length);

            unsigned char *metadata = (unsigned char *)malloc(length);
            fread(metadata, 1, length, file);
            printf("Exif Metadata:\n");

            // Print out the metadata as a string (limited to MAX_METADATA_SIZE)
            printf("%.*s\n", length - 6, metadata + 6);  // Skip the Exif header
            free(metadata);
            break;
        }
        // Move to the next segment
        fseek(file, 2, SEEK_CUR);
    }

    fclose(file);
}

// Function to print usage instructions
void print_usage(const char *program_name) {
    printf("Usage: %s <jpeg-file>\n", program_name);
}

// Main entry point
int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Extract metadata from the provided JPEG file
    extract_jpeg_metadata(argv[1]);

    return EXIT_SUCCESS;
}