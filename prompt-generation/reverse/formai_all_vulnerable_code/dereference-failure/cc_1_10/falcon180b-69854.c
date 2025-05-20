//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 256

typedef struct {
    char* key;
    char* value;
} Metadata;

int compare_metadata(const void* a, const void* b) {
    Metadata* metadata_a = (Metadata*)a;
    Metadata* metadata_b = (Metadata*)b;

    return strcmp(metadata_a->key, metadata_b->key);
}

void extract_metadata(char* line, Metadata* metadata) {
    char* delimiter = ": ";
    char* key = strtok(line, delimiter);
    char* value = strtok(NULL, delimiter);

    strncpy(metadata->key, key, MAX_KEY_SIZE);
    strncpy(metadata->value, value, MAX_VALUE_SIZE);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->key = malloc(MAX_KEY_SIZE);
    metadata->value = malloc(MAX_VALUE_SIZE);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        extract_metadata(line, metadata);
    }

    qsort(metadata, 1, sizeof(Metadata), compare_metadata);

    printf("Metadata:\n");
    for (int i = 0; i < 1; i++) {
        printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
    }

    free(metadata->key);
    free(metadata->value);
    free(metadata);

    fclose(input_file);

    return 0;
}