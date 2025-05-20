//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char *value;
    struct Token *next;
} Token;

Token *parse_metadata(char *metadata) {
    char *token_start = metadata;
    Token *head = NULL;

    while (token_start) {
        char *name_end = strchr(token_start, '=');
        char *value_end = strchr(name_end, ';');

        if (name_end && value_end) {
            int token_size = value_end - name_end + 1;
            char *name = malloc(token_size);
            memcpy(name, name_end + 1, token_size);

            char *value = malloc(value_end - name_end + 1);
            memcpy(value, value_end + 1, value_end - name_end);

            Token *new_token = malloc(sizeof(Token));
            new_token->name = name;
            new_token->value = value;
            new_token->next = head;
            head = new_token;
        }

        token_start = value_end + 1;
    }

    return head;
}

int main() {
    char *metadata = "name=John Doe;email=john.doe@example.com;age=30";

    Token *head = parse_metadata(metadata);

    while (head) {
        printf("%s: %s\n", head->name, head->value);
        head = head->next;
    }

    return 0;
}