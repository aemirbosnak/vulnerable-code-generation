//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct token {
    char *data;
    int len;
} token_t;

typedef struct {
    token_t *tokens;
    int num_tokens;
} metadata_t;

void tokenize(metadata_t *metadata, const char *str) {
    char *token_start = str;
    char *token_end = str;

    while (*token_end) {
        if (isspace(*token_end)) {
            *token_end = '\0';
            metadata->tokens[metadata->num_tokens++] = (token_t) {
               .data = token_start,
               .len = token_end - token_start
            };
            token_start = token_end + 1;
        } else {
            token_end++;
        }
    }

    if (token_start!= token_end) {
        metadata->tokens[metadata->num_tokens++] = (token_t) {
           .data = token_start,
           .len = token_end - token_start
        };
    }
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tokens; i++) {
        printf("%s\n", metadata->tokens[i].data);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;

    while (fread(buffer + buffer_size, 1, 1, fp)!= 0) {
        buffer_size++;
        if (buffer_size == MAX_TOKEN_LEN) {
            buffer_size = 0;
        }
    }

    metadata_t metadata = {
       .tokens = malloc(sizeof(token_t) * MAX_TOKENS),
       .num_tokens = 0
    };

    tokenize(&metadata, buffer);

    print_metadata(&metadata);

    free(buffer);
    free(metadata.tokens);

    return 0;
}