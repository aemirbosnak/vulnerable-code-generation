//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *name;
    char *value;
} MetadataItem;

typedef struct {
    MetadataItem *items;
    int count;
} Metadata;

Metadata *create_metadata() {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->items = NULL;
    metadata->count = 0;
    return metadata;
}

void add_metadata_item(Metadata *metadata, char *name, char *value) {
    metadata->items = realloc(metadata->items, sizeof(MetadataItem) * (metadata->count + 1));
    metadata->items[metadata->count].name = strdup(name);
    metadata->items[metadata->count].value = strdup(value);
    metadata->count++;
}

void print_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->count; i++) {
        printf("%s=%s\n", metadata->items[i].name, metadata->items[i].value);
    }
}

void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->count; i++) {
        free(metadata->items[i].name);
        free(metadata->items[i].value);
    }
    free(metadata->items);
    free(metadata);
}

int main() {
    Metadata *metadata = create_metadata();
    add_metadata_item(metadata, "name", "John Doe");
    add_metadata_item(metadata, "age", "30");
    add_metadata_item(metadata, "occupation", "Software Engineer");
    print_metadata(metadata);
    free_metadata(metadata);
    return 0;
}