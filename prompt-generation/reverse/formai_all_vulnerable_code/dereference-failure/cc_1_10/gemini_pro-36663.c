//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint32_t magic;
    uint32_t version;
    uint32_t signature_count;
    uint32_t signature_offset;
} antivirus_header_t;

typedef struct {
    uint32_t signature;
    uint32_t offset;
    uint32_t length;
} antivirus_signature_t;

int main(int argc, char *argv[]) {
    // Open the antivirus database file
    FILE *db = fopen("antivirus.db", "rb");
    if (db == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the antivirus header
    antivirus_header_t header;
    fread(&header, sizeof(antivirus_header_t), 1, db);

    // Check the antivirus header magic number
    if (header.magic != 0x41564952) {
        fprintf(stderr, "Invalid antivirus database file\n");
        return EXIT_FAILURE;
    }

    // Check the antivirus header version
    if (header.version != 1) {
        fprintf(stderr, "Unsupported antivirus database version\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the antivirus signatures
    antivirus_signature_t *signatures = malloc(sizeof(antivirus_signature_t) * header.signature_count);
    if (signatures == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the antivirus signatures
    fseek(db, header.signature_offset, SEEK_SET);
    fread(signatures, sizeof(antivirus_signature_t), header.signature_count, db);

    // Open the input file
    FILE *input = fopen("input.txt", "rb");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the input file into memory
    fseek(input, 0, SEEK_END);
    size_t input_size = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *input_data = malloc(input_size);
    if (input_data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    fread(input_data, input_size, 1, input);

    // Scan the input file for viruses
    for (int i = 0; i < header.signature_count; i++) {
        char *match = strstr(input_data, (char *)&signatures[i].signature);
        if (match != NULL) {
            printf("Virus detected at offset %ld\n", match - input_data);
            return EXIT_FAILURE;
        }
    }

    // No viruses detected
    printf("No viruses detected\n");
    return EXIT_SUCCESS;
}