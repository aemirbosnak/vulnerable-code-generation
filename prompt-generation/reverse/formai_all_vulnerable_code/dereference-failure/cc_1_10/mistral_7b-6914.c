//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256
#define METADATA_TAG "METADATA"

typedef struct {
    char tag[8];
    int size;
    char data[MAX_SIZE];
} Metadata;

Metadata* extract_metadata(char* buffer, int length) {
    Metadata* metadata = NULL;

    if (length < 8 || memcmp(buffer, METADATA_TAG, 8) != 0) {
        return NULL;
    }

    metadata = (Metadata*) malloc(sizeof(Metadata));
    strncpy(metadata->tag, buffer, 8);
    metadata->size = *(int*) (buffer + 8);

    if (length < (8 + metadata->size)) {
        free(metadata);
        return NULL;
    }

    strncpy(metadata->data, buffer + 8 + sizeof(int), metadata->size);

    return metadata;
}

int main(int argc, char* argv[]) {
    char buffer[1024];
    int length;
    Metadata* metadata;

    if (argc != 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fread(buffer, 1, sizeof(buffer), file);
    length = sizeof(buffer);

    metadata = extract_metadata(buffer, length);
    if (metadata == NULL) {
        printf("Invalid metadata found\n");
        fclose(file);
        return 1;
    }

    printf("Tag: %s, Size: %d, Data: %s\n", metadata->tag, metadata->size, metadata->data);

    free(metadata);
    fclose(file);

    return 0;
}