//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *name;
    char *value;
} metadata_t;

int parse_metadata(char *line, metadata_t *metadata) {
    char *name = NULL;
    char *value = NULL;
    char *token;
    int num_tokens = 0;

    // Split line into tokens
    token = strtok(line, ":");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens in metadata.\n");
            return -1;
        }
        if (strlen(token) >= MAX_TOKEN_LENGTH) {
            printf("Error: Token too long in metadata.\n");
            return -1;
        }
        if (name == NULL) {
            name = strdup(token);
        } else if (value == NULL) {
            value = strdup(token);
        } else {
            printf("Error: Too many values in metadata.\n");
            return -1;
        }
        token = strtok(NULL, ":");
        num_tokens++;
    }

    if (name == NULL || value == NULL) {
        printf("Error: Missing name or value in metadata.\n");
        return -1;
    }

    metadata->name = name;
    metadata->value = value;

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;

    // Check for correct number of arguments
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read metadata from file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (line[0] == '#') {
            if (parse_metadata(line + 1, &metadata)!= 0) {
                fclose(input_file);
                return 1;
            }
        }
    }

    // Print metadata
    printf("Name: %s\nValue: %s\n", metadata.name, metadata.value);

    // Close input file
    fclose(input_file);

    return 0;
}