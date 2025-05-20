//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} Metadata;

int compare_metadata(const void *a, const void *b) {
    Metadata *metadata_a = (Metadata *)a;
    Metadata *metadata_b = (Metadata *)b;

    return strcmp(metadata_a->key, metadata_b->key);
}

void print_metadata(Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *key = NULL;
    char *value = NULL;
    size_t key_length = 0;
    size_t value_length = 0;
    Metadata *metadata = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *line_copy = strdup(line);
        char *token = strtok(line_copy, ":");

        if (token == NULL) {
            free(line_copy);
            continue;
        }

        if (key!= NULL) {
            value = strdup(token);
            break;
        }

        key = strdup(token);
        value_length = strlen(token);
    }

    if (key == NULL || value == NULL) {
        if (key!= NULL) {
            free(key);
        }
        if (value!= NULL) {
            free(value);
        }
        fclose(file);
        return 1;
    }

    metadata = (Metadata *)malloc(sizeof(Metadata));
    metadata->key = key;
    metadata->value = value;

    fclose(file);

    qsort(metadata, 1, sizeof(Metadata), compare_metadata);
    print_metadata(metadata);

    free(key);
    free(value);
    free(metadata);

    return 0;
}