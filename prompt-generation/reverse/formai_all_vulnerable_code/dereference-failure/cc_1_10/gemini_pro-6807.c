//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} metadata_entry;

typedef struct {
    metadata_entry *entries;
    size_t num_entries;
} metadata;

typedef struct {
    char *filename;
    metadata *metadata;
} file_data;

pthread_mutex_t metadata_lock = PTHREAD_MUTEX_INITIALIZER;

void *extract_metadata(void *arg) {
    file_data *data = (file_data *)arg;

    // Read the metadata from the file.
    metadata *metadata = malloc(sizeof(metadata));
    metadata->entries = NULL;
    metadata->num_entries = 0;

    // Parse the metadata into key-value pairs.
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file = fopen(data->filename, "r");
    while ((read = getline(&line, &len, file)) != -1) {
        char *key = strtok(line, ":");
        if (key == NULL) {
            continue;
        }
        char *value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }

        metadata_entry *entry = malloc(sizeof(metadata_entry));
        entry->key = strdup(key);
        entry->value = strdup(value);

        pthread_mutex_lock(&metadata_lock);
        metadata->entries = realloc(metadata->entries, (metadata->num_entries + 1) * sizeof(metadata_entry));
        metadata->entries[metadata->num_entries++] = *entry;
        pthread_mutex_unlock(&metadata_lock);
    }
    fclose(file);

    data->metadata = metadata;

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>...\n", argv[0]);
        return 1;
    }

    // Create a thread for each file.
    pthread_t *threads = malloc((argc - 1) * sizeof(pthread_t));
    file_data *data = malloc((argc - 1) * sizeof(file_data));
    for (int i = 1; i < argc; i++) {
        data[i - 1].filename = argv[i];
        data[i - 1].metadata = NULL;
        pthread_create(&threads[i - 1], NULL, extract_metadata, &data[i - 1]);
    }

    // Wait for all threads to finish.
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
    }

    // Print the metadata for each file.
    for (int i = 1; i < argc; i++) {
        metadata *metadata = data[i - 1].metadata;
        printf("Metadata for %s:\n", argv[i]);
        for (size_t j = 0; j < metadata->num_entries; j++) {
            printf("  %s: %s\n", metadata->entries[j].key, metadata->entries[j].value);
        }
    }

    // Free the allocated memory.
    for (int i = 1; i < argc; i++) {
        metadata *metadata = data[i - 1].metadata;
        for (size_t j = 0; j < metadata->num_entries; j++) {
            free(metadata->entries[j].key);
            free(metadata->entries[j].value);
        }
        free(metadata->entries);
        free(metadata);
    }
    free(data);
    free(threads);

    return 0;
}