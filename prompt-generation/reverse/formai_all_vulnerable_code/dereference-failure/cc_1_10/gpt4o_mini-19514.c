//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate checksum of a given string
unsigned long calculateChecksum(const char *data) {
    unsigned long checksum = 0;
    int length = strlen(data);

    for(int i = 0; i < length; i++) {
        checksum += data[i]; // Add the ASCII value of each character
    }

    return checksum; // Return the final checksum
}

// Function to calculate checksum of a file
unsigned long calculateFileChecksum(const char *filename) {
    unsigned long checksum = 0;
    char buffer[1024]; // Buffer size for reading file
    FILE *file = fopen(filename, "rb");

    if (!file) {
        fprintf(stderr, "Could not open file %s for reading!\n", filename);
        exit(EXIT_FAILURE);
    }

    size_t bytesRead;

    // Read the file in chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for(size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    fclose(file);
    return checksum; // Return the final checksum of the file
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <option> <input>\n", argv[0]);
        printf("Options:\n");
        printf("  -s  : Calculate checksum of a string\n");
        printf("  -f  : Calculate checksum of a file\n");
        return EXIT_FAILURE;
    }

    unsigned long checksum;

    // Check for string input
    if (strcmp(argv[1], "-s") == 0) {
        checksum = calculateChecksum(argv[2]);
        printf("Checksum for string \"%s\": %lu\n", argv[2], checksum);
    }
    // Check for file input
    else if (strcmp(argv[1], "-f") == 0) {
        checksum = calculateFileChecksum(argv[2]);
        printf("Checksum for file \"%s\": %lu\n", argv[2], checksum);
    } else {
        printf("Invalid option! Use -s for string or -f for file.\n");
        return EXIT_FAILURE;
    }

    printf("Checksum calculation completed successfully!\n");
    return EXIT_SUCCESS; // Indicate successful termination
}