//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

struct metadata {
    uint32_t size;
    uint32_t type;
    uint8_t data[];
};

struct metadata_extractor {
    FILE *file;
    struct metadata *metadata;
    size_t metadata_size;
    size_t metadata_index;
};

struct metadata_extractor *metadata_extractor_create(FILE *file) {
    struct metadata_extractor *extractor = malloc(sizeof(struct metadata_extractor));
    extractor->file = file;
    extractor->metadata = NULL;
    extractor->metadata_size = 0;
    extractor->metadata_index = 0;
    return extractor;
}

void metadata_extractor_destroy(struct metadata_extractor *extractor) {
    if (extractor->metadata) free(extractor->metadata);
    free(extractor);
}

int metadata_extractor_read(struct metadata_extractor *extractor) {
    struct metadata *metadata;
    size_t size;

    if (fread(&size, sizeof(size), 1, extractor->file) != 1) {
        return -1;
    }

    metadata = realloc(extractor->metadata, extractor->metadata_size + size);
    if (!metadata) {
        return -1;
    }

    if (fread(metadata + extractor->metadata_size, size, 1, extractor->file) != 1) {
        return -1;
    }

    extractor->metadata = metadata;
    extractor->metadata_size += size;

    return 0;
}

int metadata_extractor_get_type(struct metadata_extractor *extractor, size_t index) {
    if (index >= extractor->metadata_index) {
        return -1;
    }

    return extractor->metadata[index].type;
}

size_t metadata_extractor_get_size(struct metadata_extractor *extractor, size_t index) {
    if (index >= extractor->metadata_index) {
        return -1;
    }

    return extractor->metadata[index].size;
}

uint8_t *metadata_extractor_get_data(struct metadata_extractor *extractor, size_t index) {
    if (index >= extractor->metadata_index) {
        return NULL;
    }

    return extractor->metadata[index].data;
}

int main(int argc, char **argv) {
    struct metadata_extractor *extractor;
    FILE *file;
    size_t i;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    extractor = metadata_extractor_create(file);
    if (!extractor) {
        perror("metadata_extractor_create");
        fclose(file);
        return 1;
    }

    while (metadata_extractor_read(extractor) == 0) {
        extractor->metadata_index++;
    }

    for (i = 0; i < extractor->metadata_index; i++) {
        printf("Metadata %lu:\n", i);
        printf("  Size: %lu\n", extractor->metadata[i].size);
        printf("  Type: %u\n", extractor->metadata[i].type);
        printf("  Data: ");
        for (size_t j = 0; j < extractor->metadata[i].size; j++) {
            printf("%02x ", extractor->metadata[i].data[j]);
        }
        printf("\n");
    }

    metadata_extractor_destroy(extractor);
    fclose(file);

    return 0;
}