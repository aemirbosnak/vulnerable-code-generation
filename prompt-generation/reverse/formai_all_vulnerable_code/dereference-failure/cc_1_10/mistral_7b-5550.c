//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAGIC_NUMBER 0xdeadbeef
#define METADATA_SIZE 0x100

typedef struct {
    char signature[8];
    uint32_t version;
    uint64_t size;
    char data[METADATA_SIZE];
} metadata_t;

void extract_metadata(FILE *file) {
    metadata_t *metadata;
    uint8_t buffer[METADATA_SIZE];

    fseek(file, -METADATA_SIZE, SEEK_END);
    fread(buffer, 1, METADATA_SIZE, file);

    metadata = (metadata_t *) buffer;

    if (memcmp(metadata->signature, "METADATA", 8) != 0) {
        printf("Invalid metadata signature\n");
        exit(1);
    }

    printf("Metadata version: %u\n", metadata->version);
    printf("Metadata size: %llu\n", metadata->size);

    // Extracting data in an invasive way
    uint32_t data_offset = metadata->size;
    fseek(file, -(data_offset + METADATA_SIZE), SEEK_END);
    fread(buffer, 1, data_offset, file);

    printf("Extracted data: ");
    for (size_t i = 0; i < data_offset; i++) {
        putchar(buffer[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    extract_metadata(file);
    fclose(file);

    return 0;
}