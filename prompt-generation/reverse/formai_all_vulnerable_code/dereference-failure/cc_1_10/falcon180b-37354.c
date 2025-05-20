//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    Metadata *metadata = malloc(sizeof(Metadata));
    char *name_start = line;
    char *value_start = strchr(line, ':');
    if (value_start == NULL) {
        printf("Invalid metadata format: %s\n", line);
        exit(1);
    }
    *value_start = '\0';
    metadata->name = strdup(name_start);
    metadata->value = strdup(value_start + 1);
    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

void free_metadata(Metadata *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main() {
    char line[MAX_LINE_LENGTH];
    Metadata *metadata = NULL;
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) {
            continue;
        }
        if (line[0] == '#') {
            printf("Comment: %s\n", line + 1);
        } else {
            metadata = parse_metadata(line);
            print_metadata(metadata);
            free_metadata(metadata);
            metadata = NULL;
        }
    }
    return 0;
}