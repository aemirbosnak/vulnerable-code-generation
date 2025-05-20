//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 1024
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

int num_keys = 0;
Metadata *metadata = NULL;

void add_metadata(char *key, char *value) {
    if (num_keys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of metadata keys reached.\n");
        return;
    }

    Metadata *new_metadata = realloc(metadata, sizeof(Metadata) * (num_keys + 1));
    if (new_metadata == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    metadata = new_metadata;

    strcpy(metadata[num_keys].key, key);
    strcpy(metadata[num_keys].value, value);

    num_keys++;
}

void print_metadata() {
    for (int i = 0; i < num_keys; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    metadata = malloc(sizeof(Metadata) * 1);
    if (metadata == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    num_keys = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *equals_pos = strchr(line, '=');
        if (equals_pos == NULL) {
            continue;
        }

        *equals_pos = '\0';

        strcpy(key, line);
        strcpy(value, equals_pos + 1);

        add_metadata(key, value);
    }

    print_metadata();

    free(metadata);
    return 0;
}