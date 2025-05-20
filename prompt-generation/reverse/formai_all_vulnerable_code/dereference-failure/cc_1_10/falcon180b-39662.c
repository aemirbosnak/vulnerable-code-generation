//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

metadata_t *metadata_create(void) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    memset(metadata, 0, sizeof(metadata_t));
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    free(metadata);
}

void metadata_set_key(metadata_t *metadata, const char *key) {
    strncpy(metadata->key, key, MAX_KEY_LENGTH - 1);
}

void metadata_set_value(metadata_t *metadata, const char *value) {
    strncpy(metadata->value, value, MAX_VALUE_LENGTH - 1);
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Failed to open file '%s'.\n", argv[1]);
        return 2;
    }

    metadata_t *metadata = metadata_create();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (key!= NULL && value!= NULL) {
            metadata_set_key(metadata, key);
            metadata_set_value(metadata, value);
            metadata_print(metadata);
        }
    }

    fclose(file);
    metadata_destroy(metadata);

    return 0;
}