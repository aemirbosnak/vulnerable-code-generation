//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MetaDataEntry {
    char *key;
    char *value;
} MetaDataEntry;

typedef struct Metadata {
    int num_entries;
    MetaDataEntry *entries;
} Metadata;

// Create a new metadata object
Metadata *new_metadata() {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->num_entries = 0;
    metadata->entries = NULL;
    return metadata;
}

// Add a new entry to the metadata object
void add_metadata_entry(Metadata *metadata, char *key, char *value) {
    metadata->num_entries++;
    metadata->entries = realloc(metadata->entries, metadata->num_entries * sizeof(MetaDataEntry));
    MetaDataEntry *entry = &metadata->entries[metadata->num_entries - 1];
    entry->key = strdup(key);
    entry->value = strdup(value);
}

// Get the value of a metadata entry
char *get_metadata_value(Metadata *metadata, char *key) {
    for (int i = 0; i < metadata->num_entries; i++) {
        MetaDataEntry *entry = &metadata->entries[i];
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
    }
    return NULL;
}

// Free the metadata object
void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->num_entries; i++) {
        MetaDataEntry *entry = &metadata->entries[i];
        free(entry->key);
        free(entry->value);
    }
    free(metadata->entries);
    free(metadata);
}

int main(int argc, char **argv) {
    // Create a new metadata object
    Metadata *metadata = new_metadata();

    // Add some entries to the metadata object
    add_metadata_entry(metadata, "title", "My Awesome Video");
    add_metadata_entry(metadata, "author", "John Doe");
    add_metadata_entry(metadata, "description", "This is a video about my awesome life.");

    // Get the value of a metadata entry
    char *title = get_metadata_value(metadata, "title");
    printf("Title: %s\n", title);

    // Free the metadata object
    free_metadata(metadata);

    return 0;
}