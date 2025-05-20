//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *parse_metadata(const char *line) {
    char *start, *end;
    metadata_t *metadata = malloc(sizeof(metadata_t));

    if (!metadata) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    start = line;
    metadata->key = strtok_r(start, ":", &start);
    metadata->value = strtok_r(NULL, "\n", &start);

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    metadata_t *metadata;

    file = fopen("metadata.txt", "r");

    if (!file) {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        metadata = parse_metadata(line);
        print_metadata(metadata);
        free_metadata(metadata);
    }

    fclose(file);

    return 0;
}