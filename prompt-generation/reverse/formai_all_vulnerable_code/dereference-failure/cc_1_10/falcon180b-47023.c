//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *metadata_create(char *key, char *value) {
    Metadata *meta = (Metadata *) malloc(sizeof(Metadata));
    meta->key = strdup(key);
    meta->value = strdup(value);
    return meta;
}

void metadata_destroy(Metadata *meta) {
    free(meta->key);
    free(meta->value);
    free(meta);
}

int metadata_compare(Metadata *a, Metadata *b) {
    return strcmp(a->key, b->key);
}

void metadata_print(Metadata *meta) {
    printf("%s: %s\n", meta->key, meta->value);
}

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    Metadata *metadata = NULL;

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
        key = strtok(line, ": ");
        if (key == NULL) {
            continue;
        }
        value = strtok(NULL, ": ");
        if (value == NULL) {
            continue;
        }
        metadata = metadata_create(key, value);
        metadata_print(metadata);
        metadata_destroy(metadata);
    }

    fclose(file);
    return 0;
}