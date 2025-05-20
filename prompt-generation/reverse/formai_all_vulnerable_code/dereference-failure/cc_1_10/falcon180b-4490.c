//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *name;
    char *value;
} metadata_t;

bool is_metadata(const char *line) {
    return line[0] == '#' && line[1]!= '#';
}

metadata_t *parse_metadata(const char *line) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    char *name = strdup(line + 2);
    char *value = strchr(name, ':');
    if (!value) {
        fprintf(stderr, "Invalid metadata: %s\n", line);
        exit(1);
    }
    *value = '\0';
    value++;
    while (isspace(*value)) {
        value++;
    }
    metadata->name = name;
    metadata->value = value;
    return metadata;
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

void print_metadata(const metadata_t *metadata) {
    printf("%s: %s\n", metadata->name, metadata->value);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return 1;
    }
    metadata_t *metadata = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (is_metadata(line)) {
            metadata_t *new_metadata = parse_metadata(line);
            if (metadata) {
                free_metadata(metadata);
            }
            metadata = new_metadata;
        }
    }
    if (metadata) {
        print_metadata(metadata);
    }
    fclose(file);
    return 0;
}