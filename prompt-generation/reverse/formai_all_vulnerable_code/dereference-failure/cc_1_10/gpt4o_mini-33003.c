//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define JPEG_HEADER_SIZE 20

// Function prototypes
void print_usage(const char *program_name);
int extract_jpeg_metadata(const char *filename);

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Ensure maximum filename size limits to avoid buffer overflow
    char filename[MAX_FILENAME_LENGTH];
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH - 1);
    filename[MAX_FILENAME_LENGTH - 1] = '\0';  // Null-terminate to prevent overflow

    // Extract JPEG metadata
    if (extract_jpeg_metadata(filename) != 0) {
        fprintf(stderr, "Failed to extract metadata from %s\n", filename);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <jpeg-file>\n", program_name);
}

int extract_jpeg_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    unsigned char header[JPEG_HEADER_SIZE];
    // Read the first few bytes of the image to get metadata
    if (fread(header, sizeof(unsigned char), JPEG_HEADER_SIZE, file) != JPEG_HEADER_SIZE) {
        fprintf(stderr, "Error reading the JPEG header from %s\n", filename);
        fclose(file);
        return -1;
    }

    // Simple validation for JPEG by checking the SOI marker
    if (header[0] != 0xFF || header[1] != 0xD8) {
        fprintf(stderr, "Not a valid JPEG file\n");
        fclose(file);
        return -1;
    }

    // Move the file pointer to the start of the width/height segment
    fseek(file, 5, SEEK_SET);
    unsigned short width = (header[6] << 8) | header[7];
    unsigned short height = (header[8] << 8) | header[9];

    // Print metadata
    printf("File: %s\n", filename);
    printf("Width: %d pixels\n", width);
    printf("Height: %d pixels\n", height);

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    printf("File size: %ld bytes\n", size);
    
    fclose(file);
    return 0;
}