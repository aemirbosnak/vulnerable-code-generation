//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char **values;
    int num_values;
} Token;

Token **extract_metadata(char *filename) {
    FILE *fp;
    char line[1024];
    Token **tokens = NULL;
    int num_tokens = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    while (fgets(line, 1024, fp) != NULL) {
        char *key, *value, *p, *q;
        key = strpbrk(line, ":");
        if (key) {
            value = strchr(line, ':') + 1;
            p = strchr(key, '"');
            q = strchr(value, '"');
            if (p && q) {
                Token *token = malloc(sizeof(Token));
                token->name = strdup(key);
                token->values = malloc(MAX_TOKENS * sizeof(char *));
                token->num_values = 0;
                tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token *));
                tokens[num_tokens++] = token;
                token->values[token->num_values++] = strdup(value);
            }
        }
    }

    fclose(fp);
    return tokens;
}

int main() {
    char *filename = "foo.txt";
    Token **tokens = extract_metadata(filename);
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s: ", tokens[i]->name);
        for (int j = 0; tokens[i]->values[j] != NULL; j++) {
            printf("%s ", tokens[i]->values[j]);
        }
        printf("\n");
    }

    return 0;
}