//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compute simple checksum (sum of bytes)
uint32_t simple_checksum(FILE *file) {
    uint32_t sum = 0;
    uint8_t buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            sum += buffer[i];
        }
    }
    
    if (ferror(file)) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    rewind(file); // Reset file pointer for next operation
    return sum;
}

// Function to compute CRC32 checksum
uint32_t crc32(uint32_t crc, const uint8_t *buf, size_t size) {
    static const uint32_t table[256] = {
        // Populate with CRC table values; omitted for brevity
    };
    
    crc = ~crc;
    for (size_t i = 0; i < size; i++) {
        crc = table[(crc ^ buf[i]) & 0xFF] ^ (crc >> 8);
    }
    return ~crc;
}

uint32_t crc32_checksum(FILE *file) {
    uint8_t buffer[BUFFER_SIZE];
    size_t bytesRead;
    uint32_t crc = 0;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        crc = crc32(crc, buffer, bytesRead);
    }

    if (ferror(file)) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    rewind(file); // Reset file pointer
    return crc;
}

// Function to display usage information
void display_usage(const char *programName) {
    printf("Usage: %s <filename> [--crc32 | --simple]\n", programName);
    printf("Calculate the checksum of a file using either CRC32 or simple summation.\n");
    printf("Options:\n");
    printf("  --crc32    Calculate CRC32 checksum.\n");
    printf("  --simple   Calculate simple byte sum checksum.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *filePath = argv[1];
    const char *method = argv[2];

    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    uint32_t checksum;
    if (strcmp(method, "--simple") == 0) {
        checksum = simple_checksum(file);
        printf("Simple Checksum: %u\n", checksum);
    } else if (strcmp(method, "--crc32") == 0) {
        checksum = crc32_checksum(file);
        printf("CRC32 Checksum: %u\n", checksum);
    } else {
        display_usage(argv[0]);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);
    return EXIT_SUCCESS;
}