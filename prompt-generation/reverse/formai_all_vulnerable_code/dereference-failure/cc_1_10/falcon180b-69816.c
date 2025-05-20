//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char* key;
    char* value;
} metadata_t;

metadata_t* parse_metadata(char* line) {
    char* key_start = line;
    char* value_start = strchr(line, ':');
    if (value_start == NULL) {
        return NULL;
    }
    *value_start = '\0';
    value_start++;
    char* value_end = strchr(value_start, '\n');
    if (value_end == NULL) {
        return NULL;
    }
    *value_end = '\0';
    metadata_t* metadata = malloc(sizeof(metadata_t));
    metadata->key = strndup(key_start, value_start - key_start);
    metadata->value = strndup(value_start, value_end - value_start);
    return metadata;
}

void print_metadata(metadata_t* metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(metadata_t* metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata_t* metadata = parse_metadata(line);
        if (metadata!= NULL) {
            print_metadata(metadata);
            free_metadata(metadata);
        }
    }
    fclose(file);
    return 0;
}