//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef enum {
    CHECKSUM_ADD,
    CHECKSUM_XOR
} ChecksumType;

unsigned long calculate_checksum(FILE *file, ChecksumType type) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    unsigned long checksum = (type == CHECKSUM_XOR) ? 0 : 1; // Start with 0 for XOR, 1 for ADD
    
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (type == CHECKSUM_ADD) {
                checksum += buffer[i];
            } else if (type == CHECKSUM_XOR) {
                checksum ^= buffer[i];
            }
        }
    }

    return checksum;
}

void display_usage() {
    printf("Usage: checksum_calculator <input_file> <output_file> <algorithm>\n");
    printf("Algorithms:\n");
    printf("  add  - Simple addition checksum\n");
    printf("  xor  - XOR checksum\n");
}

ChecksumType parse_algorithm(const char *arg) {
    if (strcmp(arg, "add") == 0) {
        return CHECKSUM_ADD;
    } else if (strcmp(arg, "xor") == 0) {
        return CHECKSUM_XOR;
    } else {
        fprintf(stderr, "Unknown algorithm: %s\n", arg);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *input_file_name = argv[1];
    const char *output_file_name = argv[2];
    ChecksumType algorithm = parse_algorithm(argv[3]);

    FILE *input_file = fopen(input_file_name, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    unsigned long checksum = calculate_checksum(input_file, algorithm);
    fclose(input_file);

    FILE *output_file = fopen(output_file_name, "w");
    if (!output_file) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    fprintf(output_file, "Checksum (%s): %lu\n", (algorithm == CHECKSUM_ADD) ? "Addition" : "XOR", checksum);
    fclose(output_file);

    printf("Checksum calculated and saved to %s\n", output_file_name);
    return EXIT_SUCCESS;
}