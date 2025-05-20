//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKEN_SIZE 64

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    Metadata *metadata = NULL;
    char *name = NULL;
    char *value = NULL;
    char *token = NULL;
    int token_size = 0;
    bool in_value = false;

    token = strtok(line, "=");
    if (token == NULL) {
        return NULL;
    }

    name = strdup(token);
    token = strtok(NULL, "=");
    if (token == NULL) {
        free(name);
        return NULL;
    }

    value = strdup(token);
    metadata = malloc(sizeof(Metadata));
    metadata->name = name;
    metadata->value = value;

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

int main() {
    char line[MAX_LINE_SIZE];
    Metadata *metadata = NULL;

    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        metadata = parse_metadata(line);
        if (metadata!= NULL) {
            print_metadata(metadata);
            free(metadata->name);
            free(metadata->value);
            free(metadata);
        }
    }

    return 0;
}