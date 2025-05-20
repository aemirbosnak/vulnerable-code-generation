//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    uint32_t magic;
    uint32_t checksum;
    uint32_t size;
    uint8_t data[MAX_FILE_SIZE];
} file_header_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the file header
    file_header_t header;
    if (fread(&header, sizeof(header), 1, file) != 1) {
        perror("fread");
        return EXIT_FAILURE;
    }

    // Check the magic number
    if (header.magic != 0x12345678) {
        printf("Invalid file format\n");
        return EXIT_FAILURE;
    }

    // Compute the checksum
    uint32_t checksum = 0;
    for (size_t i = 0; i < header.size; i++) {
        checksum += header.data[i];
    }

    // Compare the checksum
    if (checksum != header.checksum) {
        printf("File corrupted\n");
        return EXIT_FAILURE;
    }

    // Scan the file for viruses
    // ...

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}