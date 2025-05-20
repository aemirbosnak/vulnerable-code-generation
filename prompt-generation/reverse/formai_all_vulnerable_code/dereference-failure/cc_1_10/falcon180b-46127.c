//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    token_t tokens[MAX_TOKENS];
    int num_tokens;
} metadata_t;

void init_metadata(metadata_t *metadata) {
    metadata->num_tokens = 0;
}

void add_token(metadata_t *metadata, char *name, char *value) {
    if (metadata->num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    metadata->tokens[metadata->num_tokens].name = strdup(name);
    metadata->tokens[metadata->num_tokens].value = strdup(value);
    metadata->num_tokens++;
}

void print_metadata(metadata_t *metadata) {
    printf("Metadata:\n");
    for (int i = 0; i < metadata->num_tokens; i++) {
        printf("%s: %s\n", metadata->tokens[i].name, metadata->tokens[i].value);
    }
}

int main() {
    char input[MAX_TOKEN_LEN];
    char *token;
    metadata_t metadata;

    init_metadata(&metadata);

    while (fgets(input, MAX_TOKEN_LEN, stdin)) {
        token = strtok(input, ":");
        if (!token) {
            printf("Error: Invalid input\n");
            exit(1);
        }
        add_token(&metadata, token, strtok(NULL, ":"));
    }

    print_metadata(&metadata);

    return 0;
}