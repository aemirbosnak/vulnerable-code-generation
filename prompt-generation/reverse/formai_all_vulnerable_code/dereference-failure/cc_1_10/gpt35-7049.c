//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char key[256];
    char value[768];
} MetadataItem;

typedef struct {
    MetadataItem items[MAX_METADATA_SIZE];
    int count;
} Metadata;

Metadata* extractMetadata(char *filename) {
    Metadata *metadata = (Metadata*) malloc(sizeof(Metadata));
    metadata->count = 0;

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s", filename);
        return metadata;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *key, *value;
        int len = strlen(line);

        // remove trailing newline
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // find the colon separator
        key = line;
        value = strchr(line, ':');

        if (!value) {
            printf("Syntax error in metadata: %s\n", line);
            continue;
        }

        // null terminate the key and value strings
        *value = '\0';
        value++;

        // remove leading and trailing whitespace from both strings
        while (*key && (*key == ' ')) key++;
        while (*value && (*value == ' ')) value++;

        len = strlen(value);
        while (len > 0 && value[len - 1] == ' ') {
            value[--len] = '\0';
        }

        len = strlen(key);
        while (len > 0 && key[len - 1] == ' ') {
            key[--len] = '\0';
        }

        if (metadata->count >= MAX_METADATA_SIZE) {
            printf("Too many metadata items, discarding extra.\n");
            break;
        }

        strcpy(metadata->items[metadata->count].key, key);
        strcpy(metadata->items[metadata->count].value, value);
        metadata->count++;
    }

    fclose(file);

    return metadata;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", *argv);
        return 1;
    }

    Metadata *metadata = extractMetadata(argv[1]);

    printf("Metadata items:\n");
    for (int i = 0; i < metadata->count; i++) {
        printf("%s: %s\n", metadata->items[i].key, metadata->items[i].value);
    }

    free(metadata);

    return 0;
}