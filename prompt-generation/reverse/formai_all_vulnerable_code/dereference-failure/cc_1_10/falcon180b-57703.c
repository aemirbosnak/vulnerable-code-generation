//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata_line(char *line) {
    char *name = strtok(line, ": ");
    char *value = strtok(NULL, ": ");

    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->name = strdup(name);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n\n", metadata->value);
}

void free_metadata(Metadata *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Metadata *metadata = parse_metadata_line(line);
        print_metadata(metadata);
        free_metadata(metadata);
    }

    fclose(fp);

    return 0;
}