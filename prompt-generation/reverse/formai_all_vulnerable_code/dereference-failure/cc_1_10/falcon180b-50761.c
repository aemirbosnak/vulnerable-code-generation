//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 4096
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

void metadata_init(metadata_t *metadata) {
    strcpy(metadata->key, "");
    strcpy(metadata->value, "");
}

bool metadata_parse_line(char *line, metadata_t *metadata) {
    char *key_start = strstr(line, ": ");
    if (key_start == NULL) {
        return false;
    }

    // Extract key
    int key_length = key_start - line;
    if (key_length >= MAX_KEY_LENGTH) {
        return false;
    }
    strncpy(metadata->key, line, key_length);
    metadata->key[key_length] = '\0';

    // Extract value
    int value_start = key_start + 2;
    int value_length = strlen(line) - value_start;
    if (value_length >= MAX_VALUE_LENGTH) {
        return false;
    }
    strncpy(metadata->value, line + value_start, value_length);
    metadata->value[value_length] = '\0';

    return true;
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n---\n", metadata->key, metadata->value);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    metadata_t metadata;
    metadata_init(&metadata);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (metadata_parse_line(line, &metadata)) {
            metadata_print(&metadata);
            fprintf(output_file, "%s\n", line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}