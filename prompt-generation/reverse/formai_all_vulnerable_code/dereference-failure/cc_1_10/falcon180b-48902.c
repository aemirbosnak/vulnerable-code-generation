//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

void parse_metadata(metadata_t *metadata, char *line) {
    char *key_start = line;
    char *value_start = strchr(line, ':');

    if (!value_start) {
        printf("Invalid metadata: %s\n", line);
        return;
    }

    *value_start = '\0';
    value_start++;

    metadata->key = strdup(key_start);
    metadata->value = strdup(value_start);
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;

    file = fopen("metadata.txt", "r");

    if (!file) {
        printf("Could not open metadata file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        parse_metadata(&metadata, line);
        print_metadata(&metadata);
        free_metadata(&metadata);
    }

    fclose(file);

    return 0;
}