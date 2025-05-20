//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

void parse_metadata(char *line, metadata_t *metadata) {
    char *key_start = line;
    char *value_start = NULL;
    char *current_char = line;

    // Find the start of the value
    while (*current_char!= '=' && *current_char!= '\0') {
        current_char++;
    }

    if (*current_char == '\0') {
        return;
    }

    *current_char = '\0';
    value_start = current_char + 1;

    // Allocate memory for the key and value
    metadata->key = malloc(strlen(key_start) + 1);
    metadata->value = malloc(strlen(value_start) + 1);

    // Copy the key and value into the metadata struct
    strcpy(metadata->key, key_start);
    strcpy(metadata->value, value_start);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            parse_metadata(line + 1, &metadata);
            print_metadata(&metadata);
            free_metadata(&metadata);
        }
    }

    fclose(file);

    return 0;
}