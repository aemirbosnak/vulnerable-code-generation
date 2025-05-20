//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_META_KEYS 100
#define MAX_META_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char delimiter = ':';
    int num_meta_keys = 0;
    metadata_t *metadata = NULL;
    char *key, *value;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    metadata = (metadata_t *) malloc(MAX_META_KEYS * sizeof(metadata_t));
    if (metadata == NULL) {
        printf("Error: Could not allocate memory for metadata\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_meta_keys >= MAX_META_KEYS) {
            printf("Error: Too many metadata keys\n");
            free(metadata);
            fclose(file);
            return 1;
        }

        key = strtok(line, &delimiter);
        value = strtok(NULL, &delimiter);

        if (key == NULL || value == NULL) {
            printf("Error: Invalid metadata format\n");
            free(metadata);
            fclose(file);
            return 1;
        }

        metadata[num_meta_keys].key = strdup(key);
        metadata[num_meta_keys].value = strdup(value);
        num_meta_keys++;
    }

    fclose(file);

    printf("Metadata:\n");
    for (int i = 0; i < num_meta_keys; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    free(metadata);

    return 0;
}