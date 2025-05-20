//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int metadata_compare(const void *a, const void *b) {
    return strcmp(*(metadata_t **)a, *(metadata_t **)b);
}

void metadata_free(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

void metadata_print(const metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

metadata_t *metadata_parse(const char *line) {
    char *key = NULL;
    char *value = NULL;
    char *token = strtok(line, ":");
    if (token == NULL) {
        return NULL;
    }
    key = strdup(token);
    token = strtok(NULL, ":");
    if (token == NULL) {
        return NULL;
    }
    value = strdup(token);
    metadata_t *metadata = malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        free(key);
        free(value);
        return NULL;
    }
    metadata->key = key;
    metadata->value = value;
    return metadata;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            if (metadata!= NULL) {
                metadata_t *new_metadata = metadata_parse(line + 1);
                if (new_metadata!= NULL) {
                    metadata_free(metadata);
                    metadata = new_metadata;
                } else {
                    metadata_free(metadata);
                    metadata = NULL;
                }
            }
        } else {
            if (metadata == NULL) {
                metadata = metadata_parse(line);
                if (metadata == NULL) {
                    fprintf(stderr, "Error parsing metadata.\n");
                    metadata_free(metadata);
                    metadata = NULL;
                }
            }
        }
    }
    fclose(file);
    if (metadata!= NULL) {
        metadata_print(metadata);
        metadata_free(metadata);
    }
    return 0;
}