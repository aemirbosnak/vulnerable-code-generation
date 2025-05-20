//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

// Token types
enum token_type {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_NUMBER,
};

// Token structure
struct token {
    enum token_type type;
    char *value;
};

// List of keywords
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while"
};

// List of operators
static const char *operators[] = {
    "+", "-", "*", "/", "%", "=", "!=", "<", ">", "<=", ">=", "&&", "||", "++", "--",
    "&", "|", "^", "~", "<<", ">>", "->", ".", ","
};

// List of punctuators
static const char *punctuators[] = {
    "{", "}", "(", ")", "[", "]", ";", ":", ","
};

// Tokenizer
struct tokenizer {
    char *input;
    char *current;
    int line;
    int column;
};

// Create a new tokenizer
struct tokenizer *tokenizer_new(char *input) {
    struct tokenizer *tokenizer = malloc(sizeof(struct tokenizer));
    tokenizer->input = strdup(input);
    tokenizer->current = tokenizer->input;
    tokenizer->line = 1;
    tokenizer->column = 0;
    return tokenizer;
}

// Free the tokenizer
void tokenizer_free(struct tokenizer *tokenizer) {
    free(tokenizer->input);
    free(tokenizer);
}

// Get the next token
struct token tokenizer_next(struct tokenizer *tokenizer) {
    struct token token;
    token.type = TOKEN_EOF;
    token.value = NULL;

    // Skip whitespace
    while (*tokenizer->current == ' ' || *tokenizer->current == '\t' || *tokenizer->current == '\n') {
        if (*tokenizer->current == '\n') {
            tokenizer->line++;
            tokenizer->column = 0;
        }
        tokenizer->current++;
        tokenizer->column++;
    }

    // Check for the end of the input
    if (*tokenizer->current == '\0') {
        return token;
    }

    // Check for an identifier
    if (isalpha(*tokenizer->current) || *tokenizer->current == '_') {
        int length = 0;
        while (isalnum(*tokenizer->current) || *tokenizer->current == '_') {
            length++;
            tokenizer->current++;
            tokenizer->column++;
        }
        char *value = malloc(length + 1);
        strncpy(value, tokenizer->current - length, length);
        value[length] = '\0';
        token.type = TOKEN_IDENTIFIER;
        token.value = value;
        return token;
    }

    // Check for a keyword
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        int length = strlen(keywords[i]);
        if (strncmp(tokenizer->current, keywords[i], length) == 0) {
            char *value = malloc(length + 1);
            strncpy(value, keywords[i], length);
            value[length] = '\0';
            token.type = TOKEN_KEYWORD;
            token.value = value;
            tokenizer->current += length;
            tokenizer->column += length;
            return token;
        }
    }

    // Check for an operator
    for (int i = 0; i < sizeof(operators) / sizeof(char *); i++) {
        int length = strlen(operators[i]);
        if (strncmp(tokenizer->current, operators[i], length) == 0) {
            char *value = malloc(length + 1);
            strncpy(value, operators[i], length);
            value[length] = '\0';
            token.type = TOKEN_OPERATOR;
            token.value = value;
            tokenizer->current += length;
            tokenizer->column += length;
            return token;
        }
    }

    // Check for a punctuator
    for (int i = 0; i < sizeof(punctuators) / sizeof(char *); i++) {
        int length = strlen(punctuators[i]);
        if (strncmp(tokenizer->current, punctuators[i], length) == 0) {
            char *value = malloc(length + 1);
            strncpy(value, punctuators[i], length);
            value[length] = '\0';
            token.type = TOKEN_PUNCTUATOR;
            token.value = value;
            tokenizer->current += length;
            tokenizer->column += length;
            return token;
        }
    }

    // Check for a number
    if (isdigit(*tokenizer->current)) {
        int length = 0;
        while (isdigit(*tokenizer->current)) {
            length++;
            tokenizer->current++;
            tokenizer->column++;
        }
        char *value = malloc(length + 1);
        strncpy(value, tokenizer->current - length, length);
        value[length] = '\0';
        token.type = TOKEN_NUMBER;
        token.value = value;
        return token;
    }

    // Unknown token
    token.type = TOKEN_EOF;
    token.value = NULL;
    return token;
}

// Main function
int main(int argc, char **argv) {
    // Create a tokenizer
    struct tokenizer *tokenizer = tokenizer_new("int main() { return 0; }");

    // Get the first token
    struct token token = tokenizer_next(tokenizer);

    // Print the tokens
    while (token.type != TOKEN_EOF) {
        printf("%s (%d)\n", token.value, token.type);
        token = tokenizer_next(tokenizer);
    }

    // Free the tokenizer
    tokenizer_free(tokenizer);

    return 0;
}