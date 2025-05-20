//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *metadata_parse(char *line) {
    char *key = NULL;
    char *value = NULL;
    char *token = strtok(line, "=");

    if (token == NULL) {
        return NULL;
    }

    key = strdup(token);

    token = strtok(NULL, "=");

    if (token == NULL) {
        free(key);
        return NULL;
    }

    value = strdup(token);

    Metadata *metadata = (Metadata *) malloc(sizeof(Metadata));
    metadata->key = key;
    metadata->value = value;

    return metadata;
}

void metadata_free(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    Metadata *metadata = NULL;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *comment = strchr(line, '#');

        if (comment!= NULL) {
            *comment = '\0';
        }

        metadata = metadata_parse(line);

        if (metadata!= NULL) {
            printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
        }
    }

    fclose(file);

    return 0;
}