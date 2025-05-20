//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Create a custom metadata extractor that extracts a specific piece of information from a file.
typedef struct {
    char *key;
    char *value;
} metadata_entry;

// Extract the value of a specific key from a file.
char *extract_metadata(const char *file_name, const char *key) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *equal_sign = strchr(line, '=');
        if (equal_sign != NULL) {
            char *key_str = strndup(line, equal_sign - line);
            char *value = strdup(equal_sign + 1);
            if (strcmp(key_str, key) == 0) {
                fclose(file);
                return value;
            }
            free(key_str);
            free(value);
        }
    }

    fclose(file);
    return NULL;
}

// Create a metadata entry from a key and a value.
metadata_entry create_metadata_entry(const char *key, const char *value) {
    metadata_entry entry;
    entry.key = strdup(key);
    entry.value = strdup(value);
    return entry;
}

// Free the memory allocated for a metadata entry.
void free_metadata_entry(metadata_entry entry) {
    free(entry.key);
    free(entry.value);
}

// Extract all metadata from a file into an array of metadata entries.
metadata_entry *extract_all_metadata(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return NULL;
    }

    int num_entries = 0;
    metadata_entry *entries = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *equal_sign = strchr(line, '=');
        if (equal_sign != NULL) {
            char *key_str = strndup(line, equal_sign - line);
            char *value = strdup(equal_sign + 1);
            metadata_entry entry = create_metadata_entry(key_str, value);
            entries = realloc(entries, sizeof(metadata_entry) * (num_entries + 1));
            entries[num_entries++] = entry;
            free(key_str);
            free(value);
        }
    }

    fclose(file);
    return entries;
}

// Free the memory allocated for an array of metadata entries.
void free_all_metadata(metadata_entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free_metadata_entry(entries[i]);
    }
    free(entries);
}

// Print the metadata entries to the console.
void print_metadata(metadata_entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s = %s\n", entries[i].key, entries[i].value);
    }
}

int main() {
    // Extract a specific piece of metadata from a file.
    char *value = extract_metadata("metadata.txt", "title");
    printf("Title: %s\n", value);
    free(value);

    // Extract all metadata from a file.
    metadata_entry *entries = extract_all_metadata("metadata.txt");
    int num_entries = 0;
    while (entries[num_entries].key != NULL) {
        num_entries++;
    }
    print_metadata(entries, num_entries);
    free_all_metadata(entries, num_entries);

    return 0;
}