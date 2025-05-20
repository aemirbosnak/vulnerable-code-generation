//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char* str;
    int type;
    struct Token* next;
} Token;

Token* parse_metadata(char* text) {
    char* ptr = text;
    Token* head = NULL;
    Token* tail = NULL;

    while (ptr) {
        // Skip comments and whitespace
        while (*ptr && (*ptr == '/' || isspace(*ptr))) ptr++;

        // Extract token
        char* token = ptr;
        while (*ptr && !isspace(*ptr) && *ptr != '=') ptr++;

        // Create token
        Token* new_token = malloc(sizeof(Token));
        new_token->str = strdup(token);
        new_token->type = 0; // To be filled in later
        new_token->next = NULL;

        // Add token to list
        if (head) tail->next = new_token;
        else head = new_token;
        tail = new_token;
    }

    return head;
}

int main() {
    char* text = "Hello, world! My name is John Doe. I am a programmer.";
    Token* tokens = parse_metadata(text);

    printf("Tokens:\n");
    for (Token* token = tokens; token; token = token->next) {
        printf("  - %s\n", token->str);
    }

    return 0;
}