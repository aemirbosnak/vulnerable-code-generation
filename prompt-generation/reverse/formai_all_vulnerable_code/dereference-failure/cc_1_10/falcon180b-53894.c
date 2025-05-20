//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

void metadata_free(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

metadata_t *metadata_parse_line(char *line) {
    char *key_start = line;
    char *key_end = strchr(line, ':');
    if (key_end == NULL) {
        return NULL;
    }
    *key_end = '\0';
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = strdup(key_start);
    metadata->value = strdup(key_end + 1);
    return metadata;
}

void metadata_print(metadata_t *metadata) {
    printf("%.*s: %.*s\n", metadata->key? strlen(metadata->key) : 0, metadata->key, metadata->value? strlen(metadata->value) : 0, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }
    metadata_t *metadata = NULL;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata_t *new_metadata = metadata_parse_line(line);
        if (new_metadata!= NULL) {
            if (metadata!= NULL) {
                metadata_free(metadata);
            }
            metadata = new_metadata;
        }
    }
    if (metadata!= NULL) {
        metadata_print(metadata);
        metadata_free(metadata);
    }
    fclose(file);
    return 0;
}