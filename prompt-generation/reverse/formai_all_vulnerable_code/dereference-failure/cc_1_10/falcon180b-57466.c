//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    char *name = NULL;
    char *value = NULL;
    char *token = strtok(line, "=");
    if (token == NULL) {
        return NULL;
    }
    name = strdup(token);
    token = strtok(NULL, "=");
    if (token == NULL) {
        free(name);
        return NULL;
    }
    value = strdup(token);
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->name = name;
    metadata->value = value;
    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

void free_metadata(Metadata *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Metadata *metadata = NULL;
    int num_metadata = 0;

    file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Metadata *new_metadata = parse_metadata(line);
        if (new_metadata!= NULL) {
            metadata = realloc(metadata, sizeof(Metadata) * (num_metadata + 1));
            metadata[num_metadata] = *new_metadata;
            free_metadata(new_metadata);
            num_metadata++;
        }
    }

    fclose(file);

    for (int i = 0; i < num_metadata; i++) {
        print_metadata(&metadata[i]);
    }

    free(metadata);

    return 0;
}