//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *metadata_str) {
    int num_tokens = 0;
    char **tokens = malloc(MAX_TOKENS * sizeof(char*));
    char *token;
    metadata_t *metadata = malloc(sizeof(metadata_t));

    token = strtok(metadata_str, ",");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many metadata tokens.\n");
            exit(1);
        }
        tokens[num_tokens] = malloc(MAX_TOKEN_LEN * sizeof(char));
        strncpy(tokens[num_tokens], token, MAX_TOKEN_LEN - 1);
        tokens[num_tokens][MAX_TOKEN_LEN - 1] = '\0';
        num_tokens++;
        token = strtok(NULL, ",");
    }
    metadata->name = tokens[0];
    metadata->value = tokens[1];

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

int main() {
    char *metadata_str = "name,value";
    metadata_t *metadata = parse_metadata(metadata_str);
    print_metadata(metadata);
    free(metadata->name);
    free(metadata->value);
    free(metadata);
    return 0;
}