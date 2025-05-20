//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    char *key, *value;
    Metadata *metadata = malloc(sizeof(Metadata));

    if (metadata == NULL) {
        printf("Error: Failed to allocate memory for metadata.\n");
        exit(1);
    }

    key = strtok(line, ": ");
    value = strtok(NULL, ": ");

    if (key == NULL || value == NULL) {
        printf("Error: Invalid metadata format.\n");
        free(metadata);
        exit(1);
    }

    metadata->key = strdup(key);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Metadata *metadata;

    file = fopen("metadata.txt", "r");

    if (file == NULL) {
        printf("Error: Failed to open metadata file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata = parse_metadata(line);
        print_metadata(metadata);
        free(metadata->key);
        free(metadata->value);
        free(metadata);
    }

    fclose(file);

    return 0;
}