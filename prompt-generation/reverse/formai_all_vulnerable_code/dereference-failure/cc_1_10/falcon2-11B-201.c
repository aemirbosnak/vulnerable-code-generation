//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_PATH 256

typedef struct {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} MetadataEntry;

typedef struct {
    char filepath[MAX_FILE_PATH];
    int num_entries;
    MetadataEntry* entries;
} Metadata;

Metadata* extract_metadata(const char* filepath) {
    Metadata* metadata = (Metadata*)malloc(sizeof(Metadata));
    strcpy(metadata->filepath, filepath);
    metadata->num_entries = 0;
    metadata->entries = NULL;

    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        free(metadata);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* name = strtok(line, ":");
        char* value = strtok(NULL, ":");
        if (name!= NULL && value!= NULL) {
            MetadataEntry* entry = (MetadataEntry*)malloc(sizeof(MetadataEntry));
            strcpy(entry->name, name);
            strcpy(entry->value, value);
            metadata->entries = (MetadataEntry*)realloc(metadata->entries, (metadata->num_entries + 1) * sizeof(MetadataEntry));
            metadata->entries[metadata->num_entries++] = *entry;
            free(entry);
        }
    }

    fclose(file);

    return metadata;
}

void print_metadata(Metadata* metadata) {
    if (metadata == NULL) {
        printf("No metadata found.\n");
        return;
    }

    printf("Metadata for file: %s\n", metadata->filepath);
    printf("Number of entries: %d\n", metadata->num_entries);

    for (int i = 0; i < metadata->num_entries; i++) {
        printf("- %s: %s\n", metadata->entries[i].name, metadata->entries[i].value);
    }
}

int main() {
    const char* filepath = "cyberpunk_metadata.txt";
    Metadata* metadata = extract_metadata(filepath);
    if (metadata!= NULL) {
        print_metadata(metadata);
        free(metadata);
    } else {
        printf("Failed to extract metadata.\n");
    }

    return 0;
}