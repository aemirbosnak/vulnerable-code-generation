//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    int lineNumber;
    struct Token *next;
} Token;

Token *tokenize(char *source) {
    char *p = source;
    Token *head = NULL;
    Token *tail = NULL;

    while (p) {
        char *start = p;
        int quoted = 0;

        // Skip comments and quoted strings
        while (*p && (*p == '/' || *p == '"')) {
            if (*p == '/') {
                // Comments
                p++;
                while (*p && *p != '\n') {
                    p++;
                }
            } else if (*p == '"') {
                // Quoted strings
                quoted = 1;
                p++;
                while (*p && *p != '"') {
                    p++;
                }
                p++;
            }
        }

        // Extract tokens
        if (!quoted) {
            char *end = p;
            while (*p && !isspace(*p)) {
                p++;
            }
            if (head == NULL) {
                head = tail = malloc(sizeof(Token));
            } else {
                tail = tail->next = malloc(sizeof(Token));
                tail = tail->next;
            }
            tail->name = strdup(start);
            tail->lineNumber = 0; // To be filled in
            tail->next = NULL;
        }
    }

    return head;
}

int main() {
    char source[] = "Romeo and Juliet\n"
                        "Two star-crossed lovers\n"
                        "From feuding families\n"
                        "A tragedy\n";

    Token *tokens = tokenize(source);

    for (Token *token = tokens; token; token = token->next) {
        printf("Token: %s, Line Number: %d\n", token->name, token->lineNumber);
    }

    return 0;
}