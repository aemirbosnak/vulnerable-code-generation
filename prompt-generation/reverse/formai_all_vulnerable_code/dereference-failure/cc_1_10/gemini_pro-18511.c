//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define METADATA_KEY_TITLE "title"
#define METADATA_KEY_ARTIST "artist"
#define METADATA_KEY_ALBUM "album"
#define METADATA_KEY_YEAR "year"

typedef struct {
    char *key;
    char *value;
} MetadataEntry;

typedef struct {
    MetadataEntry *entries;
    int numEntries;
} Metadata;

Metadata *createMetadata() {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->entries = NULL;
    metadata->numEntries = 0;
    return metadata;
}

void destroyMetadata(Metadata *metadata) {
    for (int i = 0; i < metadata->numEntries; i++) {
        free(metadata->entries[i].key);
        free(metadata->entries[i].value);
    }
    free(metadata->entries);
    free(metadata);
}

MetadataEntry *createMetadataEntry(char *key, char *value) {
    MetadataEntry *entry = malloc(sizeof(MetadataEntry));
    entry->key = strdup(key);
    entry->value = strdup(value);
    return entry;
}

void destroyMetadataEntry(MetadataEntry *entry) {
    free(entry->key);
    free(entry->value);
    free(entry);
}

void addMetadataEntry(Metadata *metadata, char *key, char *value) {
    metadata->entries = realloc(metadata->entries, sizeof(MetadataEntry) * (metadata->numEntries + 1));
    metadata->entries[metadata->numEntries++] = *createMetadataEntry(key, value);
}

char *getMetadataValue(Metadata *metadata, char *key) {
    for (int i = 0; i < metadata->numEntries; i++) {
        if (strcmp(metadata->entries[i].key, key) == 0) {
            return metadata->entries[i].value;
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    Metadata *metadata = createMetadata();

    addMetadataEntry(metadata, METADATA_KEY_TITLE, "The Dream of the Fisherman's Wife");
    addMetadataEntry(metadata, METADATA_KEY_ARTIST, "Henri Rousseau");
    addMetadataEntry(metadata, METADATA_KEY_ALBUM, "Tropical Forest");
    addMetadataEntry(metadata, METADATA_KEY_YEAR, "1908");

    printf("Title: %s\n", getMetadataValue(metadata, METADATA_KEY_TITLE));
    printf("Artist: %s\n", getMetadataValue(metadata, METADATA_KEY_ARTIST));
    printf("Album: %s\n", getMetadataValue(metadata, METADATA_KEY_ALBUM));
    printf("Year: %s\n", getMetadataValue(metadata, METADATA_KEY_YEAR));

    destroyMetadata(metadata);

    return 0;
}