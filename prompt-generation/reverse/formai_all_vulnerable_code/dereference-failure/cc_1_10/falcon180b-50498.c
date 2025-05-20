//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *filename;
    char **tokens;
    int num_tokens;
} Metadata;

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, file);
    if (line == NULL && len == 0) {
        fprintf(stderr, "Error reading line.\n");
        exit(1);
    }
    return line;
}

char **tokenize(char *line) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            fprintf(stderr, "Too many tokens.\n");
            exit(1);
        }
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Tokens:\n");
    for (int i = 0; i < metadata->num_tokens; i++) {
        printf("- %s\n", metadata->tokens[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    Metadata metadata;
    metadata.filename = argv[1];
    metadata.tokens = tokenize(read_line(fopen(metadata.filename, "r")));
    metadata.num_tokens = 0;
    while (metadata.tokens[metadata.num_tokens]!= NULL) {
        metadata.num_tokens++;
    }
    print_metadata(&metadata);
    free(metadata.tokens);
    free(metadata.filename);
    return 0;
}