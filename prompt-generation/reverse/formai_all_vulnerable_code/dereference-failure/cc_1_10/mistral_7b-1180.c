//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define METADATA_MAGIC 0x1A2B3C4D

typedef struct {
    uint32_t magic;
    uint32_t num_entries;
    uint32_t entry_size;
} metadata_header_t;

typedef struct {
    char key[32];
    uint64_t value;
} metadata_entry_t;

void read_metadata(FILE *fp, metadata_header_t *header, metadata_entry_t **entries, size_t *num_entries) {
    if (fread(header, sizeof(metadata_header_t), 1, fp) != 1) {
        fprintf(stderr, "Error reading metadata header\n");
        exit(1);
    }

    if (header->magic != METADATA_MAGIC) {
        fprintf(stderr, "Invalid metadata file\n");
        exit(1);
    }

    *entries = malloc(header->num_entries * sizeof(metadata_entry_t));

    if (*entries == NULL) {
        fprintf(stderr, "Error allocating memory for metadata entries\n");
        exit(1);
    }

    if (fread(*entries, sizeof(metadata_entry_t), header->num_entries, fp) != header->num_entries) {
        fprintf(stderr, "Error reading metadata entries\n");
        exit(1);
    }

    *num_entries = header->num_entries;
}

void print_statistics(metadata_entry_t *entries, size_t num_entries) {
    uint64_t sum = 0;
    size_t num_uints = 0, num_uint64s = 0;

    for (size_t i = 0; i < num_entries; ++i) {
        if (strlen(entries[i].key) <= 3) {
            if (entries[i].value < 4294967295ULL) {
                sum += entries[i].value;
                num_uints++;
            } else {
                num_uint64s++;
            }
        }
    }

    printf("Statistics:\n");
    printf("  Number of 32-bit unsigned integers: %zu\n", num_uints);
    printf("  Sum of their values: %llu\n", sum);
    printf("  Number of 64-bit unsigned integers: %zu\n", num_uint64s);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <metadata file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error opening metadata file\n");
        exit(1);
    }

    metadata_header_t header;
    metadata_entry_t *entries = NULL;
    size_t num_entries = 0;

    read_metadata(fp, &header, &entries, &num_entries);

    print_statistics(entries, num_entries);

    free(entries);
    fclose(fp);

    return 0;
}