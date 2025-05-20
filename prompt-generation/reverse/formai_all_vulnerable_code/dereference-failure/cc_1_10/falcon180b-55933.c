//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *metadata_create() {
    Metadata *meta = malloc(sizeof(Metadata));
    meta->key = NULL;
    meta->value = NULL;
    return meta;
}

void metadata_destroy(Metadata *meta) {
    if (meta->key!= NULL) {
        free(meta->key);
    }
    if (meta->value!= NULL) {
        free(meta->value);
    }
    free(meta);
}

void metadata_set_key(Metadata *meta, char *key) {
    if (meta->key!= NULL) {
        free(meta->key);
    }
    meta->key = strdup(key);
}

void metadata_set_value(Metadata *meta, char *value) {
    if (meta->value!= NULL) {
        free(meta->value);
    }
    meta->value = strdup(value);
}

char *metadata_get_key(Metadata *meta) {
    return meta->key;
}

char *metadata_get_value(Metadata *meta) {
    return meta->value;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    char line[MAX_LINE_LENGTH];
    Metadata *metadata = metadata_create();

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *delimiter = strchr(line, ':');
        if (delimiter!= NULL) {
            *delimiter = '\0';
            char *key = line;
            char *value = delimiter + 1;
            metadata_set_key(metadata, key);
            metadata_set_value(metadata, value);
        }
    }

    fclose(file);

    printf("Key: %s\n", metadata_get_key(metadata));
    printf("Value: %s\n", metadata_get_value(metadata));

    metadata_destroy(metadata);

    return 0;
}