//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *name;
    int value;
    struct Token *next;
} Token;

Token *parse_metadata(char *data) {
    Token *head = NULL;
    char *token_start = data;
    char *token_end;

    while (token_start) {
        token_end = strstr(token_start, ":");
        if (token_end) {
            char *token_name = malloc(token_end - token_start);
            memcpy(token_name, token_start, token_end - token_start);
            token_name[token_end - token_start] = '\0';

            int token_value = atoi(token_end + 1);

            Token *new_token = malloc(sizeof(Token));
            new_token->name = token_name;
            new_token->value = token_value;
            new_token->next = head;
            head = new_token;
        }

        token_start = token_end + 1;
    }

    return head;
}

int main() {
    char data[] = "name: John Doe\n"
                   "age: 30\n"
                   "interests: Music, Reading\n";

    Token *tokens = parse_metadata(data);

    for (Token *token = tokens; token; token = token->next) {
        printf("%s: %d\n", token->name, token->value);
    }

    return 0;
}