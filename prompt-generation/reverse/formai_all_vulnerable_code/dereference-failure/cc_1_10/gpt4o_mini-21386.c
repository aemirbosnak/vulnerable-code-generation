//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256
#define MAX_METADATA 10

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Metadata;

typedef struct {
    Metadata entries[MAX_METADATA];
    int count;
} MetadataCollection;

void init_metadata_collection(MetadataCollection *collection) {
    collection->count = 0;
}

void add_metadata(MetadataCollection *collection, const char *key, const char *value) {
    if (collection->count < MAX_METADATA) {
        strncpy(collection->entries[collection->count].key, key, MAX_LINE_LENGTH);
        strncpy(collection->entries[collection->count].value, value, MAX_LINE_LENGTH);
        collection->count++;
    } else {
        fprintf(stderr, "Metadata collection is full!\n");
    }
}

void print_metadata(const MetadataCollection *collection) {
    for (int i = 0; i < collection->count; i++) {
        printf("%s: %s\n", collection->entries[i].key, collection->entries[i].value);
    }
}

void extract_metadata(const char *filename, MetadataCollection *collection) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *delimiter = strchr(line, ':');
        if (delimiter) {
            *delimiter = '\0'; // Split key and value
            add_metadata(collection, line, delimiter + 1);
        } else {
            fprintf(stderr, "Skipping invalid line: %s", line);
        }

        if (collection->count >= MAX_METADATA) {
            break; // Avoid overflow for safety
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    MetadataCollection metadata;
    init_metadata_collection(&metadata);

    extract_metadata(argv[1], &metadata);
    print_metadata(&metadata);

    return EXIT_SUCCESS;
}