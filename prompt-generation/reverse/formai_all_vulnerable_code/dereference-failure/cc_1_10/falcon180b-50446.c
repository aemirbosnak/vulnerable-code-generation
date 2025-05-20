//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *line) {
    char *key = NULL;
    char *value = NULL;
    char *start = line;
    char *end = NULL;
    metadata_t *metadata = NULL;

    while (*start!= '\0') {
        if (*start == ':') {
            *start = '\0';
            value = start + 1;
            break;
        }
        start++;
    }

    if (value == NULL) {
        return NULL;
    }

    metadata = (metadata_t *) malloc(sizeof(metadata_t));
    metadata->key = strdup(line);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata = parse_metadata(line);
        if (metadata!= NULL) {
            print_metadata(metadata);
            free(metadata->key);
            free(metadata->value);
            free(metadata);
        }
    }

    fclose(file);
    return 0;
}