//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a metadata entry
typedef struct {
    char *name;
    char *value;
} MetadataEntry;

// Structure representing metadata
typedef struct {
    MetadataEntry *entries;
    int size;
} Metadata;

// Function to create a new Metadata object
Metadata* create_metadata(int size) {
    Metadata *metadata = (Metadata *)malloc(sizeof(Metadata));
    metadata->entries = (MetadataEntry *)malloc(size * sizeof(MetadataEntry));
    metadata->size = size;
    return metadata;
}

// Function to set an entry in the metadata
void set_metadata_entry(Metadata *metadata, int index, const char *name, const char *value) {
    if (index < metadata->size) {
        metadata->entries[index].name = strdup(name);
        metadata->entries[index].value = strdup(value);
    }
}

// Function to retrieve an entry from the metadata
const char* get_metadata_entry(Metadata *metadata, const char *name) {
    for (int i = 0; i < metadata->size; i++) {
        if (strcmp(metadata->entries[i].name, name) == 0) {
            return metadata->entries[i].value;
        }
    }
    return NULL;
}

// Function to free the metadata
void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->size; i++) {
        free(metadata->entries[i].name);
        free(metadata->entries[i].value);
    }
    free(metadata->entries);
    free(metadata);
}

// Function to print all metadata
void print_metadata(Metadata *metadata) {
    printf("Metadata Entries:\n");
    for (int i = 0; i < metadata->size; i++) {
        printf("Name: %s, Value: %s\n", metadata->entries[i].name, metadata->entries[i].value);
    }
}

// Main function showcasing metadata extraction and management
int main() {
    // Create metadata object with space for 5 entries
    Metadata *metadata = create_metadata(5);

    // Populate metadata entries
    set_metadata_entry(metadata, 0, "Title", "The Great Gatsby");
    set_metadata_entry(metadata, 1, "Author", "F. Scott Fitzgerald");
    set_metadata_entry(metadata, 2, "Year", "1925");
    set_metadata_entry(metadata, 3, "Genre", "Fiction");
    set_metadata_entry(metadata, 4, "ISBN", "9780743273565");

    // Print all metadata
    print_metadata(metadata);

    // Fetch and print a specific entry
    const char *author = get_metadata_entry(metadata, "Author");
    if (author != NULL) {
        printf("Fetched Author: %s\n", author);
    } else {
        printf("Author not found.\n");
    }

    // Clean up
    free_metadata(metadata);
    return 0;
}