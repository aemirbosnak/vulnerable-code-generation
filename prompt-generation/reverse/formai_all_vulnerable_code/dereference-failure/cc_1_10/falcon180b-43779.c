//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *line) {
    char *name = NULL;
    char *value = NULL;
    char *delimiter = "=";
    char *token = strtok(line, delimiter);

    if (token == NULL) {
        return NULL;
    }

    name = strdup(token);

    token = strtok(NULL, delimiter);

    if (token == NULL) {
        free(name);
        return NULL;
    }

    value = strdup(token);

    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->name = name;
    metadata->value = value;

    return metadata;
}

void metadata_free(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

void metadata_print(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

int main() {
    FILE *file = fopen("metadata.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    metadata_t *metadata = NULL;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        metadata = metadata_parse(line);

        if (metadata!= NULL) {
            metadata_print(metadata);
        }
    }

    fclose(file);

    return 0;
}