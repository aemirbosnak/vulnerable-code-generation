//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} metadata_entry;

typedef struct {
    int num_entries;
    metadata_entry *entries;
} metadata;

metadata *create_metadata() {
    metadata *m = malloc(sizeof(metadata));
    m->num_entries = 0;
    m->entries = NULL;
    return m;
}

void destroy_metadata(metadata *m) {
    for (int i = 0; i < m->num_entries; i++) {
        free(m->entries[i].key);
        free(m->entries[i].value);
    }
    free(m->entries);
    free(m);
}

int add_metadata_entry(metadata *m, char *key, char *value) {
    m->entries = realloc(m->entries, (m->num_entries + 1) * sizeof(metadata_entry));
    m->entries[m->num_entries].key = strdup(key);
    m->entries[m->num_entries].value = strdup(value);
    m->num_entries++;
    return 0;
}

char *get_metadata_value(metadata *m, char *key) {
    for (int i = 0; i < m->num_entries; i++) {
        if (strcmp(m->entries[i].key, key) == 0) {
            return m->entries[i].value;
        }
    }
    return NULL;
}

int main() {
    metadata *m = create_metadata();
    add_metadata_entry(m, "title", "My Awesome Song");
    add_metadata_entry(m, "artist", "Me");
    add_metadata_entry(m, "album", "My Awesome Album");

    printf("Title: %s\n", get_metadata_value(m, "title"));
    printf("Artist: %s\n", get_metadata_value(m, "artist"));
    printf("Album: %s\n", get_metadata_value(m, "album"));

    destroy_metadata(m);
    return 0;
}