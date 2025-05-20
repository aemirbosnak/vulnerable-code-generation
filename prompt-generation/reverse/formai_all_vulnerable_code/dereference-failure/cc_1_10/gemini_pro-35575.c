//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char *name;
    char *value;
} metadata_t;

void print_metadata(metadata_t *metadata, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }
}

int main() {
    // Read metadata from stdin
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int count = 0;
    metadata_t *metadata = NULL;

    while ((read = getline(&line, &len, stdin)) != -1) {
        // Parse metadata line
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Allocate memory for metadata struct
        metadata = realloc(metadata, (count + 1) * sizeof(metadata_t));

        // Set metadata name and value
        metadata[count].name = strdup(name);
        metadata[count].value = strdup(value);

        // Increment metadata count
        count++;
    }

    // Print metadata
    print_metadata(metadata, count);

    // Free memory
    for (int i = 0; i < count; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);
    free(line);

    return 0;
}