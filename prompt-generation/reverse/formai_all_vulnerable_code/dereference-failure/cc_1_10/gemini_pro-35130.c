//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define METADATA_LIMIT 1024

struct MetadataEntry {
    char *name;
    char *value;
};

struct Metadata {
    int count;
    struct MetadataEntry *entries;
};

struct Metadata *metadata_new() {
    struct Metadata *metadata = malloc(sizeof(struct Metadata));
    metadata->count = 0;
    metadata->entries = NULL;
    return metadata;
}

void metadata_free(struct Metadata *metadata) {
    for (int i = 0; i < metadata->count; i++) {
        free(metadata->entries[i].name);
        free(metadata->entries[i].value);
    }
    free(metadata->entries);
    free(metadata);
}

int metadata_add(struct Metadata *metadata, char *name, char *value) {
    metadata->entries = realloc(metadata->entries, (metadata->count + 1) * sizeof(struct MetadataEntry));
    metadata->entries[metadata->count].name = strdup(name);
    metadata->entries[metadata->count].value = strdup(value);
    metadata->count++;
    return 0;
}

int metadata_get(struct Metadata *metadata, char *name, char **value) {
    for (int i = 0; i < metadata->count; i++) {
        if (strcmp(metadata->entries[i].name, name) == 0) {
            *value = strdup(metadata->entries[i].value);
            return 0;
        }
    }
    return -1;
}

int metadata_extract(char *path, struct Metadata *metadata) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return -1;
    }

    char line[METADATA_LIMIT];
    while (fgets(line, METADATA_LIMIT, file) != NULL) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (name != NULL && value != NULL) {
            metadata_add(metadata, name, value);
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct Metadata *metadata = metadata_new();
    metadata_extract(argv[1], metadata);

    for (int i = 0; i < metadata->count; i++) {
        printf("%s: %s\n", metadata->entries[i].name, metadata->entries[i].value);
    }

    metadata_free(metadata);
    return 0;
}