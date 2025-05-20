//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_COMMENT,
    TOKEN_WHITESPACE
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

typedef struct {
    token tokens[MAX_TOKENS];
    int num_tokens;
} tokenizer;

tokenizer *tokenizer_new() {
    tokenizer *tokenizer = malloc(sizeof(tokenizer));
    tokenizer->num_tokens = 0;
    return tokenizer;
}

void tokenizer_free(tokenizer *tokenizer) {
    for (int i = 0; i < tokenizer->num_tokens; i++) {
        free(tokenizer->tokens[i].value);
    }
    free(tokenizer);
}

token *tokenizer_next(tokenizer *tokenizer) {
    if (tokenizer->num_tokens == 0) {
        return NULL;
    }
    return &tokenizer->tokens[tokenizer->num_tokens - 1];
}

void tokenizer_add(tokenizer *tokenizer, token_type type, char *value) {
    if (tokenizer->num_tokens == MAX_TOKENS) {
        fprintf(stderr, "Error: tokenizer is full\n");
        exit(1);
    }
    tokenizer->tokens[tokenizer->num_tokens].type = type;
    tokenizer->tokens[tokenizer->num_tokens].value = strdup(value);
    tokenizer->num_tokens++;
}

int main() {
    // Create a tokenizer
    tokenizer *tokenizer = tokenizer_new();

    // Tokenize a string
    char *input = "int main() { printf(\"Hello, world!\\n\"); }";
    char *p = input;
    while (*p != '\0') {
        // Skip whitespace
        while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
            p++;
        }

        // Check for end of input
        if (*p == '\0') {
            break;
        }

        // Check for identifier
        if (isalpha(*p) || *p == '_') {
            char *start = p;
            while (isalnum(*p) || *p == '_') {
                p++;
            }
            char *end = p;
            int len = end - start;
            char *value = malloc(len + 1);
            strncpy(value, start, len);
            value[len] = '\0';
            tokenizer_add(tokenizer, TOKEN_IDENTIFIER, value);
            free(value);
            continue;
        }

        // Check for number
        if (isdigit(*p)) {
            char *start = p;
            while (isdigit(*p)) {
                p++;
            }
            char *end = p;
            int len = end - start;
            char *value = malloc(len + 1);
            strncpy(value, start, len);
            value[len] = '\0';
            tokenizer_add(tokenizer, TOKEN_NUMBER, value);
            free(value);
            continue;
        }

        // Check for string
        if (*p == '"') {
            char *start = p + 1;
            while (*p != '"' && *p != '\0') {
                p++;
            }
            char *end = p;
            int len = end - start;
            char *value = malloc(len + 1);
            strncpy(value, start, len);
            value[len] = '\0';
            tokenizer_add(tokenizer, TOKEN_STRING, value);
            free(value);
            p++;
            continue;
        }

        // Check for keyword
        if (strcmp(p, "int") == 0) {
            tokenizer_add(tokenizer, TOKEN_KEYWORD, "int");
            p += 3;
            continue;
        }
        if (strcmp(p, "main") == 0) {
            tokenizer_add(tokenizer, TOKEN_KEYWORD, "main");
            p += 4;
            continue;
        }

        // Check for operator
        if (strcmp(p, "+") == 0) {
            tokenizer_add(tokenizer, TOKEN_OPERATOR, "+");
            p += 1;
            continue;
        }
        if (strcmp(p, "-") == 0) {
            tokenizer_add(tokenizer, TOKEN_OPERATOR, "-");
            p += 1;
            continue;
        }
        if (strcmp(p, "*") == 0) {
            tokenizer_add(tokenizer, TOKEN_OPERATOR, "*");
            p += 1;
            continue;
        }
        if (strcmp(p, "/") == 0) {
            tokenizer_add(tokenizer, TOKEN_OPERATOR, "/");
            p += 1;
            continue;
        }

        // Check for punctuator
        if (strcmp(p, ",") == 0) {
            tokenizer_add(tokenizer, TOKEN_PUNCTUATOR, ",");
            p += 1;
            continue;
        }
        if (strcmp(p, ";") == 0) {
            tokenizer_add(tokenizer, TOKEN_PUNCTUATOR, ";");
            p += 1;
            continue;
        }
        if (strcmp(p, "{") == 0) {
            tokenizer_add(tokenizer, TOKEN_PUNCTUATOR, "{");
            p += 1;
            continue;
        }
        if (strcmp(p, "}") == 0) {
            tokenizer_add(tokenizer, TOKEN_PUNCTUATOR, "}");
            p += 1;
            continue;
        }

        // Check for comment
        if (strcmp(p, "//") == 0) {
            while (*p != '\n' && *p != '\0') {
                p++;
            }
            continue;
        }
        if (strcmp(p, "/*") == 0) {
            while (strcmp(p, "*/") != 0 && *p != '\0') {
                p++;
            }
            if (*p == '\0') {
                fprintf(stderr, "Error: unterminated comment\n");
                exit(1);
            }
            p += 2;
            continue;
        }

        // Unknown character
        fprintf(stderr, "Error: unexpected character '%c'\n", *p);
        exit(1);
    }

    // Print the tokens
    for (int i = 0; i < tokenizer->num_tokens; i++) {
        token *token = &tokenizer->tokens[i];
        switch (token->type) {
            case TOKEN_EOF:
                printf("EOF\n");
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", token->value);
                break;
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", token->value);
                break;
            case TOKEN_STRING:
                printf("STRING: %s\n", token->value);
                break;
            case TOKEN_KEYWORD:
                printf("KEYWORD: %s\n", token->value);
                break;
            case TOKEN_OPERATOR:
                printf("OPERATOR: %s\n", token->value);
                break;
            case TOKEN_PUNCTUATOR:
                printf("PUNCTUATOR: %s\n", token->value);
                break;
            case TOKEN_COMMENT:
                printf("COMMENT: %s\n", token->value);
                break;
            case TOKEN_WHITESPACE:
                printf("WHITESPACE\n");
                break;
        }
    }

    // Free the tokenizer
    tokenizer_free(tokenizer);

    return 0;
}