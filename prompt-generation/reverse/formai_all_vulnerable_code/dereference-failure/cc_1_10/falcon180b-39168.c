//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *name;
    char *value;
} metadata_t;

int parse_metadata(char *line, metadata_t *metadata) {
    char *equal_sign = strchr(line, '=');
    if (!equal_sign) {
        return 0;
    }
    *equal_sign = '\0';
    metadata->name = strdup(line);
    metadata->value = strdup(equal_sign + 1);
    return 1;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
}

int main() {
    FILE *input_file;
    char *line = NULL;
    size_t line_length = 0;
    metadata_t metadata;
    int found_metadata = 0;

    input_file = fopen("input.txt", "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    metadata.name = NULL;
    metadata.value = NULL;

    while ((getline(&line, &line_length, input_file))!= -1) {
        if (line[0] == '#') {
            if (found_metadata) {
                continue;
            }
            if (parse_metadata(line + 1, &metadata)) {
                found_metadata = 1;
                printf("Metadata found:\n");
            }
        } else if (found_metadata) {
            print_metadata(&metadata);
            free_metadata(&metadata);
            found_metadata = 0;
        }
    }

    if (metadata.name) {
        print_metadata(&metadata);
        free_metadata(&metadata);
    }

    free(line);
    fclose(input_file);

    return 0;
}