//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *name;
    char *value;
} metadata_t;

int parse_metadata(char *line, metadata_t *metadata) {
    char *token = strtok(line, ":");
    int count = 0;

    while (token!= NULL && count < MAX_TOKENS) {
        if (count == 0) {
            metadata->name = strdup(token);
        } else {
            metadata->value = strdup(token);
            return count;
        }

        count++;
        token = strtok(NULL, ":");
    }

    return -1;
}

int main() {
    FILE *input_file;
    char line[MAX_TOKEN_LENGTH];
    metadata_t metadata;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LENGTH, input_file)!= NULL) {
        int token_count = parse_metadata(line, &metadata);

        if (token_count >= 0) {
            printf("Name: %s\n", metadata.name);
            printf("Value: %s\n", metadata.value);
        } else {
            printf("Error: Invalid metadata format.\n");
        }

        free(metadata.name);
        free(metadata.value);
    }

    fclose(input_file);

    return 0;
}