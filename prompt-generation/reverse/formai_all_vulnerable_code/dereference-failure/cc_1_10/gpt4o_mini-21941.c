//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define POLYNOMIAL 0xEDB88320L

// Function to compute the CRC32 checksum
uint32_t crc32(unsigned char *message, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; i++) {
        crc ^= message[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc >> 1) ^ (POLYNOMIAL & -(crc & 1));
        }
    }
    return ~crc;
}

// Function to calculate checksum for files
uint32_t calculate_file_crc(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    uint32_t checksum = 0;
    unsigned char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        checksum = crc32(buffer, bytesRead);
    }

    fclose(file);
    return checksum;
}

// Function to display help information
void display_help() {
    printf("Checksum Calculator\n");
    printf("Usage: checksum_calculator [options] <file>\n");
    printf("Options:\n");
    printf("  -h, --help      Show this help message\n");
    printf("  -t, --text      Calculate checksum for text files\n");
    printf("  -b, --binary    Calculate checksum for binary files\n");
    printf("If no option is specified, it defaults to binary file processing.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return EXIT_FAILURE;
    }

    char *filename = NULL;
    int is_text_file = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            display_help();
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--text") == 0) {
            is_text_file = 1;
        } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--binary") == 0) {
            is_text_file = 0;
        } else {
            filename = argv[i];
        }
    }

    if (filename == NULL) {
        fprintf(stderr, "No file specified.\n");
        return EXIT_FAILURE;
    }

    uint32_t checksum = calculate_file_crc(filename);

    if (is_text_file) {
        printf("Checksum for text file '%s': 0x%08X\n", filename, checksum);
    } else {
        printf("Checksum for binary file '%s': 0x%08X\n", filename, checksum);
    }

    return EXIT_SUCCESS;
}