//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 256
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    char filename[MAX_LINE_LENGTH];
    int num_pairs;
    KeyValuePair pairs[MAX_NUM_KEYS];
} Metadata;

void read_metadata(Metadata *metadata) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    int num_pairs = 0;

    file = fopen(metadata->filename, "r");
    if (file == NULL) {
        printf("Error: could not open metadata file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_pairs >= MAX_NUM_KEYS) {
            printf("Error: too many key-value pairs in metadata file.\n");
            exit(1);
        }
        key = strtok(line, ":");
        value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            printf("Error: invalid key-value pair in metadata file.\n");
            exit(1);
        }
        strncpy(metadata->pairs[num_pairs].key, key, MAX_KEY_LENGTH);
        strncpy(metadata->pairs[num_pairs].value, value, MAX_VALUE_LENGTH);
        num_pairs++;
    }

    fclose(file);
    metadata->num_pairs = num_pairs;
}

int main(int argc, char *argv[]) {
    Metadata metadata;

    if (argc < 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        exit(1);
    }

    strncpy(metadata.filename, argv[1], MAX_LINE_LENGTH);
    read_metadata(&metadata);

    printf("Metadata:\n");
    for (int i = 0; i < metadata.num_pairs; i++) {
        printf("%s: %s\n", metadata.pairs[i].key, metadata.pairs[i].value);
    }

    return 0;
}