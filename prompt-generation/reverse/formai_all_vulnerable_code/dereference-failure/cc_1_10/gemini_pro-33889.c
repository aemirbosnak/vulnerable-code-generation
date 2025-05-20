//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char *name;
    char *value;
} MetadataEntry;

typedef struct {
    size_t size;
    MetadataEntry *entries;
} Metadata;

Metadata *metadata_new() {
    Metadata *metadata = malloc(sizeof(Metadata));
    assert(metadata != NULL);

    metadata->size = 0;
    metadata->entries = NULL;

    return metadata;
}

void metadata_free(Metadata *metadata) {
    for (size_t i = 0; i < metadata->size; i++) {
        free(metadata->entries[i].name);
        free(metadata->entries[i].value);
    }

    free(metadata->entries);
    free(metadata);
}

int metadata_add_entry(Metadata *metadata, const char *name, const char *value) {
    assert(metadata != NULL);
    assert(name != NULL);
    assert(value != NULL);

    MetadataEntry *entry = malloc(sizeof(MetadataEntry));
    assert(entry != NULL);

    entry->name = strdup(name);
    entry->value = strdup(value);

    metadata->entries = realloc(metadata->entries, (metadata->size + 1) * sizeof(MetadataEntry));
    assert(metadata->entries != NULL);

    metadata->entries[metadata->size] = *entry;
    metadata->size++;

    return 0;
}

char *metadata_get_value(Metadata *metadata, const char *name) {
    assert(metadata != NULL);
    assert(name != NULL);

    for (size_t i = 0; i < metadata->size; i++) {
        if (strcmp(metadata->entries[i].name, name) == 0) {
            return metadata->entries[i].value;
        }
    }

    return NULL;
}

int main() {
    // Create a new metadata object.
    Metadata *metadata = metadata_new();

    // Add some metadata entries.
    metadata_add_entry(metadata, "title", "My Awesome Program");
    metadata_add_entry(metadata, "author", "John Doe");
    metadata_add_entry(metadata, "version", "1.0");

    // Get the value of a metadata entry.
    char *title = metadata_get_value(metadata, "title");

    // Print the metadata.
    printf("Title: %s\n", title);
    printf("Author: %s\n", metadata_get_value(metadata, "author"));
    printf("Version: %s\n", metadata_get_value(metadata, "version"));

    // Free the metadata object.
    metadata_free(metadata);

    return 0;
}