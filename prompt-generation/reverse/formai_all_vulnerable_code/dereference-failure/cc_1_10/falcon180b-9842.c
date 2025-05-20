//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

void parse_metadata(char *line, metadata_t *metadata) {
    char *name = strtok(line, ":");
    char *value = strtok(NULL, ":");

    metadata->name = strdup(name);
    metadata->value = strdup(value);
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    metadata_t metadata;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#' || line[0] == '\0') {
            continue;
        }

        parse_metadata(line, &metadata);
        print_metadata(&metadata);
        free_metadata(&metadata);
    }

    fclose(file);

    return 0;
}