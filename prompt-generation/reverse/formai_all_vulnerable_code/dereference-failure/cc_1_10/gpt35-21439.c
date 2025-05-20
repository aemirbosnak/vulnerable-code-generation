//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} metadata_t;

typedef struct {
    metadata_t *metadata;
    size_t size;
} metadata_list_t;

metadata_list_t* extract_metadata(char *file_path) {
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error: File could not be opened\n");
        exit(1);
    }

    metadata_list_t *metadata_list = malloc(sizeof(metadata_list_t));
    metadata_list->metadata = NULL;
    metadata_list->size = 0;

    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        if (line[0] != '#') {
            break;
        }

        metadata_t metadata;

        token = strtok(line, ":");
        metadata.key = strdup(token);
        token = strtok(NULL, "\n");
        metadata.value = strdup(token);

        metadata_list->size++;
        metadata_list->metadata = realloc(metadata_list->metadata, metadata_list->size * sizeof(metadata_t));
        metadata_list->metadata[metadata_list->size - 1] = metadata;
    }

    fclose(file);

    return metadata_list;
}

int main() {

    char *file_path = "example.txt";
    metadata_list_t *metadata_list = extract_metadata(file_path);

    for (int i = 0; i < metadata_list->size; i++) {
        printf("%s: %s\n", metadata_list->metadata[i].key, metadata_list->metadata[i].value);
    }

    // Free memory
    for (int i = 0; i < metadata_list->size; i++) {
        free(metadata_list->metadata[i].key);
        free(metadata_list->metadata[i].value);
    }
    free(metadata_list->metadata);
    free(metadata_list);

    return 0;
}