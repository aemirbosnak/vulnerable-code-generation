//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *key;
    char *value;
} MetadataEntry;

typedef struct {
    int num_entries;
    MetadataEntry *entries;
} Metadata;

int load_metadata(const char *filename, Metadata *metadata) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, ":");
        if (key == NULL) {
            continue;
        }

        char *value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }

        MetadataEntry entry = {
            .key = strdup(key),
            .value = strdup(value),
        };

        metadata->entries = realloc(metadata->entries, sizeof(MetadataEntry) * (metadata->num_entries + 1));
        metadata->entries[metadata->num_entries++] = entry;
    }

    fclose(fp);
    return 0;
}

void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->num_entries; i++) {
        free(metadata->entries[i].key);
        free(metadata->entries[i].value);
    }

    free(metadata->entries);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <metadata file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata metadata = {
        .num_entries = 0,
        .entries = NULL,
    };

    if (load_metadata(argv[1], &metadata) == -1) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < metadata.num_entries; i++) {
        printf("%s: %s\n", metadata.entries[i].key, metadata.entries[i].value);
    }

    free_metadata(&metadata);
    return EXIT_SUCCESS;
}