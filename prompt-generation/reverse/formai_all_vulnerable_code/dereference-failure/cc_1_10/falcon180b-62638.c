//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* name;
    char* value;
} metadata_t;

metadata_t* parse_metadata(char* metadata_str) {
    metadata_t* metadata = (metadata_t*)malloc(sizeof(metadata_t));
    metadata->name = NULL;
    metadata->value = NULL;

    char* token = strtok(metadata_str, ":");
    if (token == NULL) {
        free(metadata);
        return NULL;
    }
    metadata->name = strdup(token);

    token = strtok(NULL, ":");
    if (token == NULL) {
        free(metadata->name);
        free(metadata);
        return NULL;
    }
    metadata->value = strdup(token);

    return metadata;
}

void free_metadata(metadata_t* metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main() {
    char* metadata_str = "author:John Doe\ntitle:My Program\nversion:1.0";
    metadata_t* metadata = parse_metadata(metadata_str);

    if (metadata!= NULL) {
        printf("Author: %s\nTitle: %s\nVersion: %s\n", metadata->name, metadata->value, metadata->value);
        free_metadata(metadata);
    }

    return 0;
}