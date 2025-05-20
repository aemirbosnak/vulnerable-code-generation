//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *line) {
    char *key = NULL, *value = NULL;
    char *delimiter = "=";
    char *token = strtok(line, delimiter);
    key = strdup(token);
    value = strdup(strtok(NULL, delimiter));

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = key;
    metadata->value = value;

    return metadata;
}

void metadata_free(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

void metadata_print(metadata_t *metadata) {
    printf("key: %s, value: %s\n", metadata->key, metadata->value);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (line[0] == '#') {
            metadata_t *metadata = metadata_parse(line);
            metadata_print(metadata);
            metadata_free(metadata);
        }
    }

    fclose(file);
    return 0;
}