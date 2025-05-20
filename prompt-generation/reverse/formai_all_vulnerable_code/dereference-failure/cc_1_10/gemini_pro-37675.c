//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum token_type {
    TOKEN_EOF,
    TOKEN_IDENT,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_PUNCT,
    TOKEN_KEYWORD,
    TOKEN_ERROR
};

struct token {
    enum token_type type;
    char *value;
};

struct lexer {
    char *input;
    char *current;
    int length;
};

struct lexer *lexer_new(char *input) {
    struct lexer *lexer = malloc(sizeof(struct lexer));
    lexer->input = input;
    lexer->current = input;
    lexer->length = strlen(input);
    return lexer;
}

void lexer_free(struct lexer *lexer) {
    free(lexer);
}

struct token *lexer_next_token(struct lexer *lexer) {
    struct token *token = malloc(sizeof(struct token));
    token->type = TOKEN_EOF;
    token->value = NULL;

    // Skip whitespace
    while (*lexer->current == ' ' || *lexer->current == '\n' || *lexer->current == '\t') {
        lexer->current++;
    }

    // Check for end of input
    if (*lexer->current == '\0') {
        return token;
    }

    // Check for identifiers
    if (isalpha(*lexer->current)) {
        int length = 0;
        while (isalpha(*lexer->current) || isdigit(*lexer->current) || *lexer->current == '_') {
            lexer->current++;
            length++;
        }
        token->type = TOKEN_IDENT;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->current - length, length);
        token->value[length] = '\0';
        return token;
    }

    // Check for numbers
    if (isdigit(*lexer->current)) {
        int length = 0;
        while (isdigit(*lexer->current)) {
            lexer->current++;
            length++;
        }
        token->type = TOKEN_NUMBER;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->current - length, length);
        token->value[length] = '\0';
        return token;
    }

    // Check for strings
    if (*lexer->current == '\"') {
        lexer->current++;
        int length = 0;
        while (*lexer->current != '\"' && *lexer->current != '\0') {
            lexer->current++;
            length++;
        }
        token->type = TOKEN_STRING;
        token->value = malloc(length + 1);
        strncpy(token->value, lexer->current - length, length);
        token->value[length] = '\0';
        lexer->current++; // Skip the closing "
        return token;
    }

    // Check for punctuation
    if (ispunct(*lexer->current)) {
        token->type = TOKEN_PUNCT;
        token->value = malloc(2);
        token->value[0] = *lexer->current;
        token->value[1] = '\0';
        lexer->current++;
        return token;
    }

    // Check for keywords
    if (!strncmp(lexer->current, "if", 2)) {
        token->type = TOKEN_KEYWORD;
        token->value = malloc(3);
        strcpy(token->value, "if");
        lexer->current += 2;
        return token;
    }
    if (!strncmp(lexer->current, "else", 4)) {
        token->type = TOKEN_KEYWORD;
        token->value = malloc(5);
        strcpy(token->value, "else");
        lexer->current += 4;
        return token;
    }
    if (!strncmp(lexer->current, "while", 5)) {
        token->type = TOKEN_KEYWORD;
        token->value = malloc(6);
        strcpy(token->value, "while");
        lexer->current += 5;
        return token;
    }
    if (!strncmp(lexer->current, "return", 6)) {
        token->type = TOKEN_KEYWORD;
        token->value = malloc(7);
        strcpy(token->value, "return");
        lexer->current += 6;
        return token;
    }

    // Error
    token->type = TOKEN_ERROR;
    token->value = malloc(2);
    token->value[0] = *lexer->current;
    token->value[1] = '\0';
    lexer->current++;
    return token;
}

int main() {
    char *input = "if (x == 1) {\n  x = 2;\n} else {\n  x = 3;\n}";
    struct lexer *lexer = lexer_new(input);
    struct token *token;

    while ((token = lexer_next_token(lexer)) != NULL) {
        switch (token->type) {
            case TOKEN_EOF:
                printf("End of input\n");
                break;
            case TOKEN_IDENT:
                printf("Identifier: %s\n", token->value);
                break;
            case TOKEN_NUMBER:
                printf("Number: %s\n", token->value);
                break;
            case TOKEN_STRING:
                printf("String: %s\n", token->value);
                break;
            case TOKEN_PUNCT:
                printf("Punctuation: %s\n", token->value);
                break;
            case TOKEN_KEYWORD:
                printf("Keyword: %s\n", token->value);
                break;
            case TOKEN_ERROR:
                printf("Error: %s\n", token->value);
                break;
        }
        free(token);
    }

    lexer_free(lexer);
    return 0;
}